#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s){v_strings.emplace(lower_bound(v_strings.begin(), v_strings.end(), s), s);}
  vector<string> GetSortedStrings()const{return  v_strings;}
private:
  vector<string> v_strings;
};



void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}


int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}
