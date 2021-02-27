#include "bus_manager.h"

using namespace std;

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    buses_for_stops[bus] = stops;
    for(const auto& i: stops)
        stops_for_busses[i].push_back(bus);
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
      if(stops_for_busses.count(stop) == 0)
          return {};
      return {stops_for_busses.at(stop)};
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
      if(buses_for_stops.count(bus) == 0)
          return {};
      StopsForBusResponse response;
      response.bus = bus;
      for(const auto& stop: buses_for_stops.at(bus))
          response.stops.emplace_back(stop, stops_for_busses.at(stop));
      return response;
}

AllBusesResponse BusManager::GetAllBuses() const {
    return {buses_for_stops};
}