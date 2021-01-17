#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Routes{
public:
    string ADD(const vector<string>& v);
private:
    map<vector<string>, int> _routes;
};

string Routes::ADD(const vector<string> &v) {
    if(_routes.count(v) != 0)
        return "Already exists for " + to_string(_routes[v]);

    size_t col_routs = _routes.size();
    _routes[v] = ++col_routs;
    return "New bus " + to_string(col_routs);
}

int main(){
    int Q = 0, col;
    Routes routes;
    cin>>Q;
    for(;Q;--Q){
        cin>>col;
        vector<string> stops(col);
        for(auto& i: stops)
            cin>>i;
        cout<<routes.ADD(stops)<<endl;
    }
    return 0;
}