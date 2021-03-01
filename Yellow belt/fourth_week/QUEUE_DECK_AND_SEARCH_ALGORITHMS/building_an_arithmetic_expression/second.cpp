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
    string prev_str;
    cin>>x>>N;
    vector<NUM> v(N);
    deque<string> deq;

    deq.push_back(to_string(x));

    for(auto& i: v)
        cin>>i.ch>>i.num;

    for(auto& i: v){

        if ((prev_str == "-" || prev_str == "+") && (i.ch == "*" || i.ch == "/")){
                deq.push_front("(");
                deq.push_back(")");
        }

        deq.push_back(" " + i.ch + " " + to_string(i.num));
        prev_str = i.ch;
    }

    for(auto& i: deq)
        cout<<i;

    return 0;
}
