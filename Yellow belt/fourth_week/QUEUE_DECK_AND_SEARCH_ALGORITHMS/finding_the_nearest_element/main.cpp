#include <iostream>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border){
    set<int>::const_iterator second_el;
    auto first_el = numbers.lower_bound(border);
    if(first_el == numbers.begin())
        return numbers.begin();

    second_el = prev(first_el);
    if(first_el == numbers.end())
        return second_el;

    return *first_el - border >= border - *second_el? second_el: first_el;
}


int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
