#include "database.h"

using namespace std;

void Database::Add(const Date& date, const string& event){
    if(_db[date].s.find(event) == _db[date].s.end()){
        _db[date].s.insert(event);
        _db[date].v.push_back(event);
    }
}


void Database::Print(std::ostream& stream) const{
    for(auto& [date, events]: _db)
        for(auto& e: events.v){
            if(date != Date())
                stream<<date<<" ";
            stream<<e<<endl;
        }
}


pair<Date, string> Database::Last(const Date& date) const{
    auto it = _db.upper_bound(date);
    if(it == _db.begin())
        return {{},"No entries"};
    else
        return {prev(it)->first, prev(it)->second.v.back()};
}

