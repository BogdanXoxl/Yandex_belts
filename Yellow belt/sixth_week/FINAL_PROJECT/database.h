#ifndef YANDEX_BELTS_DATABASE_H
#define YANDEX_BELTS_DATABASE_H

#include "date.h"

#include <set>
#include <utility>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



class Database {
public:
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& stream) const;
    std::pair<Date, std::string>  Last(const Date& date) const;
    template<class T> int RemoveIf(T predicate);
    template<class T> std::vector<std::pair<Date, std::string>> FindIf(T predicate) const;

private:
    struct Event{
        std::vector<std::string> v;
        std::set<std::string> s;
    };
    std::map<Date, Event> _db;
};


template<class T> int Database::RemoveIf(T predicate){
    int col = 0;
    auto locale_db = _db;
    for(auto& pair: _db){
        if(predicate(pair.first, "")){
            col += pair.second.s.size();
            locale_db.erase(pair.first);
        }else{
            auto it = std::stable_partition(pair.second.v.begin(), pair.second.v.end(), [&pair,&predicate](const std::string& event){return !predicate(pair.first, event);});
            if(it == pair.second.v.begin()){
                col += locale_db[pair.first].s.size();
                locale_db.erase(pair.first);
            }else{
                col += pair.second.v.end() - it;
                locale_db[pair.first].v = {pair.second.v.begin(), it};
                locale_db[pair.first].s = {locale_db[pair.first].v.begin(), locale_db[pair.first].v.end()};
            }
        }
    }
    _db = locale_db;
    return col;
}

template<class T> std::vector<std::pair<Date, std::string>> Database::FindIf(T predicate) const{

    std::vector<std::pair<Date, std::string>>  m;
    for(auto& date_events_Event: _db){
        std::vector<std::string> v;
        std::copy_if(date_events_Event.second.v.begin() , date_events_Event.second.v.end(), std::back_inserter(v),
                     [&date_events_Event, &predicate](const std::string& event){return predicate(date_events_Event.first, event);});
        for(std::string& event: v)
            m.emplace_back(date_events_Event.first, event);
    }

    return m;
}


#endif //YANDEX_BELTS_DATABASE_H
