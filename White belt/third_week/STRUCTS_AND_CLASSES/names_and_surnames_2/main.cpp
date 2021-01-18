#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    surnames[year] = last_name;
  }
  string BuildFullName(const string& first_name, const string& last_name) {
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
  string GetFullName(int year) {
      return BuildFullName(_findLast(names, year),_findLast(surnames, year));
  }
  string GetFullNameWithHistory(int year) {
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

    string _get_history(const map<int, string>& m, int year){
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
  map<int, string> names;
  map<int, string> surnames;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeFirstName(1965, "Appolinaria");

  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1965, "Volkova");
  person.ChangeLastName(1965, "Volkova-Sergeeva");

  for (int year : {1964, 1965, 1966}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
