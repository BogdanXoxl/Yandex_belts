#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if(range_end - range_begin < 2)
        return;
    auto v = vector(range_begin, range_end);
    auto middle1 = v.begin() + (range_end - range_begin)/3;
    auto middle2 = v.begin() + (range_end - range_begin)/3*2;
    MergeSort(v.begin(), middle1);
    MergeSort(middle1, middle2);
    MergeSort(middle2, v.end());
    auto var = vector(range_begin, range_begin);
    merge(v.begin(), middle1, middle1, middle2, back_inserter(var));
    merge(var.begin(), var.end(), middle2, v.end(), range_begin);
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
