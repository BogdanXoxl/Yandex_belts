#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <utility>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string command;
    is>>command;
    if(command == "NEW_BUS"){
        q.type = QueryType::NewBus;
        is>>q.bus;
        int c;
        cin>>c;
        q.stops = vector<string>(c);
        for(auto& i: q.stops)
            is>>i;
    }
    else if(command == "BUSES_FOR_STOP"){
        q.type = QueryType::BusesForStop;
        is>>q.stop;
    }
    else if(command == "STOPS_FOR_BUS"){
        q.type = QueryType::StopsForBus;
        is>>q.bus;
    }
    else if(command == "ALL_BUSES")
        q.type = QueryType::AllBuses;
  return is;
}

struct BusesForStopResponse {
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  bool first_el = true;
  if(r.buses.empty())
      os<<"No stop";
  else
      for(const auto& i: r.buses){
          if(!first_el)
              os<<" ";
          os<<i;
          first_el = false;
      }
  return os;
}

struct StopsForBusResponse {
    string bus;
  vector<pair<string, vector<string>>> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if(r.stops.empty())
      os<<"No bus";
  else
      for(const auto& [key, value]: r.stops){
          os<<"Stop "<<key<<": ";
          if(value.size() < 2)
              os<<"no interchange";
          else{
              bool first_el = true;
              for(const auto& i: value)
                  if(i != r.bus){
                      if(!first_el)
                        os<<" ";
                      os<<i;
                      first_el = false;
                  }
          }
          os<<endl;
      }
  return os;
}

struct AllBusesResponse {
  map<string, vector<string>> busses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if(r.busses.empty())
      os<<"No buses";
  else
      for(const auto& [key, value]: r.busses){
          os<<"Bus "<<key<<": ";
          bool first_el = true;
          for(const auto& i: value)
              if(i != key){
                  if(!first_el)
                    os<<" ";
                  os<<i;
                  first_el = false;
              }
          os<<endl;
      }

  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    buses_for_stops[bus] = stops;
    for(const auto& i: stops)
        stops_for_busses[i].push_back(bus);
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      if(stops_for_busses.count(stop) == 0)
          return {};
      return {stops_for_busses.at(stop)};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
      if(buses_for_stops.count(bus) == 0)
          return {};
      StopsForBusResponse response;
      response.bus = bus;
      for(const auto& stop: buses_for_stops.at(bus))
          response.stops.emplace_back(stop, stops_for_busses.at(stop));
      return response;
  }

  AllBusesResponse GetAllBuses() const {
    return {buses_for_stops};
  }
private:
    map<string, vector<string>> buses_for_stops;
    map<string, vector<string>> stops_for_busses;
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
