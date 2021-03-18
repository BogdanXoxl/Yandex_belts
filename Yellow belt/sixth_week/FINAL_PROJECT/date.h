#ifndef YANDEX_BELTS_DATE_H
#define YANDEX_BELTS_DATE_H

#include <iostream>
#include <tuple>
#include <iomanip>
#include <sstream>

#define SRAV(Lhs, Rhs, Ch) (std::make_tuple(Lhs.year, Lhs.month, Lhs.day) Ch std::make_tuple(Rhs.year, Rhs.month, Rhs.day))

class Date {
public:
    Date(int y = -1, int m = -1, int d = -1): year(y), month(m), day(d){}
    int year, month, day;
};

std::ostream& operator << (std::ostream& stream, const std::pair<Date, std::string>& p);

Date ParseDate(std::istream& stream);

std::ostream& operator << (std::ostream& stream, const Date& d);

bool operator < (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs);
bool operator > (const Date& lhs, const Date& rhs);
bool operator >= (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);

#endif //YANDEX_BELTS_DATE_H
