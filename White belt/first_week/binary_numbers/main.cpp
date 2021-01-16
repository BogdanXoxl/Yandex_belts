#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int x = 0, s;
    vector<int> v;
    cin>>x;

    while (x >= 1) {
        v.push_back(x % 2);
        x = x / 2;
    }
    for_each(v.rbegin(), v.rend(), [](int x){cout<<x;});

    return 0;
}
