#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Reverse(vector<int>& v){
    reverse(v.begin(), v.end());
}

int main(){
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    return 0;
}