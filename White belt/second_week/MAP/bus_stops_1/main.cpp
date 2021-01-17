#include <iostream>
#include <map>
#include <vector>

using namespace std;

class BusStops{
public:
    void NEW_BUS(const string& bus, const vector<string>& stops);
    vector<string> BUSES_FOR_STOP(const string& stop) const;
    vector<string> STOPS_FOR_BUS(const string& bus) const;
    map<string, vector<string>> ALL_BUSES()const;
private:
    map<string, vector<string>> stops_for_buses;
    map<string, vector<string>> buses_for_stops;
};

void BusStops::NEW_BUS(const string &bus, const vector<string>& stops) {
    stops_for_buses[bus] = stops;
    for(const auto& stop: stops)
        buses_for_stops[stop].push_back(bus);
}

vector<string> BusStops::BUSES_FOR_STOP(const string& stop) const {
    try{
    return buses_for_stops.at(stop);
    }catch(...){
        return {};
    }
}

vector<string> BusStops::STOPS_FOR_BUS(const string& bus) const {
    try{
        return stops_for_buses.at(bus);
    } catch (...) {
        return{};
    }
}

map<string, vector<string>> BusStops::ALL_BUSES() const {
    return stops_for_buses;
}

int main(){
    int Q = 0, _count = 0;
    string command, content;
    BusStops data;
    cin>>Q;
    for(;Q;--Q){
        cin>>command;
        if(command == "ALL_BUSES"){
            if(data.ALL_BUSES().empty())
                cout<<"No buses";
            else
                for(auto& i: data.ALL_BUSES()){
                    cout<<"Bus "<<i.first<<": ";
                    for(auto& j: i.second)
                        cout<<j<<" ";
                    cout<<endl;
                }
            cout<<endl;
        }else{
            cin>>content;
            if(command == "NEW_BUS"){
                cin>>_count;
                vector<string> v(_count);
                for(auto& i: v)
                    cin>>i;
                data.NEW_BUS(content, v);
            }else if(command == "BUSES_FOR_STOP"){
                if(!data.BUSES_FOR_STOP(content).empty())
                    for(const auto& i:data.BUSES_FOR_STOP(content))
                        cout<<i<<" ";
                else
                    cout<<"No stop";
                cout<<endl;
            }else if(command == "STOPS_FOR_BUS"){
                if(!data.STOPS_FOR_BUS(content).empty()){
                        for(const string& stop: data.STOPS_FOR_BUS(content)){
                            cout<<"Stop "<<stop<<": ";
                            if(data.BUSES_FOR_STOP(stop).size() == 1)
                                cout<<"no interchange";
                            else
                                for(const string& bus: data.BUSES_FOR_STOP(stop))
                                    if(bus != content)
                                        cout<<bus<<" ";
                            cout<<endl;
                        }
                }
                else
                    cout<<"No bus";
                cout<<endl;
            }
        }
    }
    return 0;
}