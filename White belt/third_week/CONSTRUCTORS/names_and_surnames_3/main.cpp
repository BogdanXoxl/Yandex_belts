#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    Person(const string& name, const string& surname, int year){
        names[year] = name;
        surnames[year] = surname;
    }
  void ChangeFirstName(int year, const string& first_name) {
        if(year >= names.begin()->first)
            names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
        if(year >= names.begin()->first)
            surnames[year] = last_name;
  }
  string GetFullName(int year)const{
        if(year >= names.begin()->first)
            return BuildFullName(_findLast(names, year),_findLast(surnames, year));
        else
            return "No person";
  }
  string GetFullNameWithHistory(int year)const{
      if(year < names.begin()->first)
        return "No person";
    auto var = _get_history(names, year);
    auto var2 = _get_history(surnames, year);
    return BuildFullName(_findLast(names, year) + (var.empty()?"":" "+var),
                         _findLast(surnames, year) + (var2.empty()?"":" "+var2));
  }
private:
    static string _findLast(const map<int, string>& m, int year){
      auto it = m.upper_bound(year);
      string name;
      if(it != m.begin())
          name = prev(it)->second;
      return name;
    }

    string _get_history(const map<int, string>& m, int year)const{
      if(m.empty())
          return "";
       vector<string> v;
       string result;
       for(auto& [key, value]: m)
           if(key > year)
               break;
           else if(v.empty() || v.back() != value)
               v.push_back(value);
       if(v.size() > 1){
           v.pop_back();
           reverse(v.begin(), v.end());
           result += "(";
           bool flag = true;
           for(auto& i: v){
               if(flag)
                   flag = false;
               else
                   result += ", ";
               result += i;
           }
           result += ")";
       }
       return result;
    }
    string BuildFullName(const string& first_name, const string& last_name)const {
      if (first_name.empty() && last_name.empty()) {
          return "Incognito";
      } else if (first_name.empty()) {
          return last_name + " with unknown first name";
      } else if (last_name.empty()) {
          return first_name + " with unknown last name";
      } else {
          return first_name + " " + last_name;
      }
  }
  map<int, string> names;
  map<int, string> surnames;
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}

