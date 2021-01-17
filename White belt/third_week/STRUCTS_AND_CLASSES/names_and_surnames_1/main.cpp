#include <iostream>
#include <map>
//#include "../../../../Tools/profile.h"

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    surnames[year] = last_name;
  }
  string GetFullName(int year) {
      string name = _findLast(names, year);
      string surname = _findLast(surnames, year);
      if(name.empty() && surname.empty())
          return "Incognito";
      else if(name.empty())
          return surname + " with unknown first name";
      else if(surname.empty())
          return name + " with unknown last name";
      else
          return name + " " + surname;
  }
private:
    static string _findLast(const map<int, string>& m, int year){
      auto it = m.upper_bound(year);
      string name;
      if(it != m.begin())
          name = prev(it)->second;
      return name;
    }
  map<int, string> names;
  map<int, string> surnames;
};


//// если имя неизвестно, возвращает пустую строку
//string FindNameByYear(const map<int, string>& names, int year) {
//  string name;  // изначально имя неизвестно
//
//  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
//  for (const auto& item : names) {
//    // если очередной год не больше данного, обновляем имя
//    if (item.first <= year) {
//      name = item.second;
//    } else {
//      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
//      break;
//    }
//  }
//
//  return name;
//}
//
//class Person2 {
//public:
//  void ChangeFirstName(int year, const string& first_name) {
//    first_names[year] = first_name;
//  }
//  void ChangeLastName(int year, const string& last_name) {
//    last_names[year] = last_name;
//  }
//  string GetFullName(int year) {
//    // получаем имя и фамилию по состоянию на год year
//    const string first_name = FindNameByYear(first_names, year);
//    const string last_name = FindNameByYear(last_names, year);
//
//    // если и имя, и фамилия неизвестны
//    if (first_name.empty() && last_name.empty()) {
//      return "Incognito";
//
//    // если неизвестно только имя
//    } else if (first_name.empty()) {
//      return last_name + " with unknown first name";
//
//    // если неизвестна только фамилия
//    } else if (last_name.empty()) {
//      return first_name + " with unknown last name";
//
//    // если известны и имя, и фамилия
//    } else {
//      return first_name + " " + last_name;
//    }
//  }
//
//private:
//  map<int, string> first_names;
//  map<int, string> last_names;
//};

int main() {
    {
//        LOG_DURATION("FIRST");
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
    }
//    {
//        LOG_DURATION("SECOND");
//        Person2 person;
//
//        person.ChangeFirstName(1965, "Polina");
//        person.ChangeLastName(1967, "Sergeeva");
//        for (int year : {1900, 1965, 1990}) {
//            cout << person.GetFullName(year) << endl;
//        }
//
//        person.ChangeFirstName(1970, "Appolinaria");
//        for (int year : {1969, 1970}) {
//            cout << person.GetFullName(year) << endl;
//        }
//
//        person.ChangeLastName(1968, "Volkova");
//        for (int year : {1969, 1970}) {
//            cout << person.GetFullName(year) << endl;
//        }
//    }

  return 0;
}
