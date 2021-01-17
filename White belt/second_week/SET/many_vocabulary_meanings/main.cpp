#include <iostream>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> result;
    for(const auto& i: m)
        result.insert(i.second);
  return result;
}
