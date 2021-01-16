#include <iostream>
#include <vector>

using namespace std;

const int col_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

class Monthly_affairs{
public:
    Monthly_affairs():days_lists(col_days[0]){};
    void ADD(int day, const string& thing);
    void DUMP(int day) const;
    void NEXT();

private:
    int month = 0;
    vector<vector<string>> days_lists;
};

void Monthly_affairs::ADD(int day, const string &thing) {days_lists.at(day-1).push_back(thing);}

void Monthly_affairs::DUMP(int day) const {
    auto v = days_lists.at(day-1);
    cout<<v.size()<<" ";
    for(const auto& i: v)
        cout<<i<<" ";
    cout<<endl;
}

void Monthly_affairs::NEXT() {
    month = (month + 1) % 12;

    if(col_days[month] < days_lists.size())
        for(auto it = days_lists.begin() + col_days[month]; it != days_lists.end(); ++it)
            days_lists[col_days[month]-1].insert(days_lists[col_days[month]-1].end(), it->begin(), it->end());

    days_lists.resize(col_days[month]);
}

int main(){
    Monthly_affairs m;
    int Q = 0, day = 0;
    string thing, command;
    cin>>Q;
    for(;Q>0;--Q){
        cin>>command;
        if(command == "ADD"){
            cin>>day>>thing;
            m.ADD(day, thing);
        }else if(command == "DUMP"){
            cin>>day;
            m.DUMP(day);
        }else if(command == "NEXT")
            m.NEXT();
    }
    return 0;
}