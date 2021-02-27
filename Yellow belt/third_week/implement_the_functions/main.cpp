#include "sum_reverse_sort.h"
#include <algorithm>


int Sum(int x, int y){
    return x+y;
}

string Reverse(string s){
    return {s.rbegin(), s.rend()};
}

void Sort(vector<int>& nums){
    sort(nums.begin(), nums.end());
}
