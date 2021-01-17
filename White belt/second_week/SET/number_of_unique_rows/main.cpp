#include <iostream>
#include <set>

using namespace std;

int main(){
    int Q = 0;
    string content;
    set<string> data;
    cin>>Q;
    for(;Q;--Q){
        cin>>content;
        data.insert(content);
    }
    cout<<data.size()<<endl;
    return 0;
}
