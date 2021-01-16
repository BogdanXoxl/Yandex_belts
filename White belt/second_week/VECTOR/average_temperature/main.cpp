#include <iostream>
#include <vector>
#include "../../../../Tools/profile.h"

using namespace std;

int main(){

    int N = 0, sum = 0;
    cin>>N;

    vector<int> v(N);
    for(auto& i: v){
        cin>>i;
        sum+=i;
    }

    auto avarge = sum/N;
    vector<int> result;

    for(int i=0; i<v.size(); ++i)
        if(v[i] > avarge)
            result.push_back(i);

    cout<<result.size()<<endl;
    for(auto& i: result)
        cout<<i<<" ";

    return 0;
}