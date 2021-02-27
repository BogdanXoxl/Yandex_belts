
#include <iostream>
#include <vector>
#include <utility>
#include <map>

#ifndef YANDEX_BELTS_RESPONSES_H
#define YANDEX_BELTS_RESPONSES_H


struct BusesForStopResponse {
    std::vector<std::string> buses;
};
struct StopsForBusResponse {
    std::string bus;
    std::vector<std::pair<std::string, std::vector<std::string>>> stops;
};
struct AllBusesResponse {
  std::map<std::string, std::vector<std::string>> busses;
};


std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);
std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);
std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);

#endif //YANDEX_BELTS_RESPONSES_H
