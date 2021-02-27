
#ifndef YANDEX_BELTS_BUS_MANAGER_H
#define YANDEX_BELTS_BUS_MANAGER_H
#include <map>
#include <vector>
#include "responses.h"

class BusManager {
public:
  void AddBus(const std::string& bus, const std::vector<std::string>& stops);
  BusesForStopResponse GetBusesForStop(const std::string& stop) const;
  StopsForBusResponse GetStopsForBus(const std::string& bus) const;
  AllBusesResponse GetAllBuses() const;
private:
    std::map<std::string, std::vector<std::string>> buses_for_stops;
    std::map<std::string, std::vector<std::string>> stops_for_busses;
};


#endif //YANDEX_BELTS_BUS_MANAGER_H
