#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct NUM{
    int num;
    string ch;
};
int main(){
    int N, x;
    cin>>x>>N;
    vector<NUM> v(N);
    deque<string> deq;

    deq.push_back(to_string(x));

    for(auto& i: v)
        cin>>i.ch>>i.num;

    for(auto& i: v){
        deq.push_front("(");
        deq.push_back(") " + i.ch + " " + to_string(i.num));
    }

    for(auto& i: deq)
        cout<<i;

    return 0;
}
