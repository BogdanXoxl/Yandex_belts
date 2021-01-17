#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int Q = 0;
    cin>>Q;
    vector<int> v(Q);
    for(auto& i:v)
        cin>>i;
    sort(v.begin(), v.end(), [](const int& first, const int&  second){return abs(first)<abs(second);});
    for(const auto& i:v)
        cout<<i<<" ";
    return 0;
}