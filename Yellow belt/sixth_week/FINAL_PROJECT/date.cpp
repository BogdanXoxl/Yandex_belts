#include "date.h"

using namespace std;

ostream& operator << (std::ostream& stream, const Date& d){
    stream<<setfill('0')<<setw(4)<<d.year<<"-"<<setw(2)<<d.month<<"-"<<setw(2)<<d.day;
    return stream;
}


Date ParseDate(std::istream& stream){
    Date date;
    char ch;
    stream>>date.year>>ch>>date.month>>ch>>date.day;
    return date;
}

bool operator < (const Date& lhs, const Date& rhs){return SRAV(lhs, rhs, <);}
bool operator <= (const Date& lhs, const Date& rhs){return SRAV(lhs, rhs, <=);}
bool operator > (const Date& lhs, const Date& rhs){return SRAV(lhs, rhs, >);}
bool operator >= (const Date& lhs, const Date& rhs){return SRAV(lhs, rhs, >=);}
bool operator == (const Date& lhs, const Date& rhs){return SRAV(lhs, rhs, ==);}
bool operator != (const Date& lhs, const Date& rhs){return SRAV(lhs, rhs, !=);}

std::ostream& operator << (std::ostream& stream, const std::pair<Date, std::string>& p){
    if(p.first != Date())
        stream<<p.first<<" ";
    stream<<p.second;
    return stream;
}