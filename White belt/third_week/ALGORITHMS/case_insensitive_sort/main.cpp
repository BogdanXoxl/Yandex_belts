#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main(){
    int Q = 0;
    cin>>Q;

    vector<string> v(Q);
    for(auto& i: v)
        cin>>i;

    sort(v.begin(), v.end(), [](string& first, string& second){
        if(first.size() != second.size())
            return first<second;
        for(size_t i = 0; i<first.size();i++){
            if(tolower(first[i]) != tolower(second[i]))
                return tolower(first[i]) < tolower(second[i]);
        }
        return false;
    });

    for(auto& i: v)
        cout<<i<<" ";

    return 0;
}