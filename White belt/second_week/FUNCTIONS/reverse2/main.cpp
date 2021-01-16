#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v){
    return {v.rbegin(), v.rend()};
}

int main(){
    return 0;
}