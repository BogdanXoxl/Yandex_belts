#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> v(N);
    iota(v.rbegin(), v.rend(), 1);

    do{
        for(const int& i: v)
            cout<<i<<" ";
        cout<<endl;
    }while(prev_permutation(v.begin(), v.end()));

    return 0;
}