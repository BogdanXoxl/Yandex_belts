#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main(){
    int N = 0;
    int64_t sum = 0;
    cin>>N;

    vector<int> v(N);
    for(auto& i: v){
        cin>>i;
        sum+=i;
    }

    int average = sum/N;
    vector<int> result;

    for(int i=0; i<v.size(); ++i)
        if(v[i] > average)
            result.push_back(i);

    cout<<result.size()<<endl;
    for(auto& i: result)
        cout<<i<<" ";
    return 0;
}