#include <iostream>
#include <set>
#include <map>

using namespace std;

class Routes{
public:
    string ADD(const set<string>& v);
private:
    map<set<string>, int> _routes;
};

string Routes::ADD(const set<string> &v) {
    if(_routes.count(v) != 0)
        return "Already exists for " + to_string(_routes[v]);

    size_t col_routs = _routes.size();
    _routes[v] = ++col_routs;
    return "New bus " + to_string(col_routs);
}

int main(){
    int Q = 0, col;
    string stop;
    Routes routes;
    cin>>Q;
    for(;Q;--Q){
        cin>>col;
        set<string> stops;
        for(;col;--col){
            cin>>stop;
            stops.insert(stop);
        }
        cout<<routes.ADD(stops)<<endl;
    }
    return 0;
}