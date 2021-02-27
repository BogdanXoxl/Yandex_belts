
#include "responses.h"

using namespace std;

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