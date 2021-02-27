#include "query.h"

using namespace std;

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