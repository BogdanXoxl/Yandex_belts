#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers){
    auto f = find_if(numbers.begin(), numbers.end(), [](const int& i){return i<0;});
    while(f != numbers.begin()){
        --f;
        cout<<*f<<" ";
    }
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
