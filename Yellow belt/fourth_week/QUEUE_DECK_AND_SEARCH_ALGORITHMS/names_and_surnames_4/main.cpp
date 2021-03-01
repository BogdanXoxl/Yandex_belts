#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

string FindNameByYear(map<int, string>& m, int year){
    auto nameIt = m.upper_bound(year);
    if(nameIt != m.begin())
        return prev(nameIt)->second;
    return {};
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    surnames[year] = last_name;
  }
  string GetFullName(int year) {
    string name = FindNameByYear(names, year);
    string surname = FindNameByYear(surnames, year);
    if(name.empty())
        if(surname.empty())
            return "Incognito";
        else
            return surname + " with unknown first name";
    else
        if(surname.empty())
            return name + " with unknown last name";
        else
            return name + " " + surname;
  }
private:
  map<int, string> names;
  map<int, string> surnames;
};


int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
