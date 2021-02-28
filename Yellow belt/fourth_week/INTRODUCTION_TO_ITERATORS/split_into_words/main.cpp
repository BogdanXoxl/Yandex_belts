#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s){
    vector<string> result;
    auto str_begin = s.begin();
    auto str_end = find(s.begin(), s.end(), ' ');
    while(true){
        result.emplace_back(str_begin, str_end);
        if(str_end == s.end())
            break;
        str_begin = ++str_end;
        str_end = find(str_begin, s.end(), ' ');
    }
    return result;
}


int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
