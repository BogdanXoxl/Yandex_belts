#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Queue{
public:
    void WORRY(const int& pos);
    void QUIET(const int& pos);
    void COME(int col);
    int WORRY_COUNT() const;
private:
    vector<bool> data;
};

void Queue::WORRY(const int& pos) {data.at(pos) = true;}
void Queue::QUIET(const int &pos) {data.at(pos) = false;}
void Queue::COME(int col) {data.resize(data.size() + col, false);}
int Queue::WORRY_COUNT() const {return count(data.begin(), data.end(), true);}


int main(){
    int Q = 0, num = 0;
    Queue q;
    string input_str;
    cin>>Q;

    for(;Q>0;--Q){
        cin>>input_str;
        if(input_str == "WORRY"){
            cin>>num;
            q.WORRY(num);
        }else if(input_str == "QUIET"){
            cin>>num;
            q.QUIET(num);
        }else if(input_str == "COME"){
            cin>>num;
            q.COME(num);
        }else if(input_str == "WORRY_COUNT")
            cout<<q.WORRY_COUNT()<<endl;
    }
    return 0;
}