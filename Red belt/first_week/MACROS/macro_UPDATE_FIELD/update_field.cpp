#include "airline_ticket.h"
#include "test_runner.h"

#include <sstream>

using namespace std;

bool operator < (const Date& lhs, const Date& rhs){return tie(lhs.year, lhs.month, lhs.day) < tie(rhs.year, rhs.month, rhs.day);}
bool operator < (const Time& lhs, const Time& rhs){return tie(lhs.hours, lhs.minutes) < tie(rhs.hours, rhs.minutes);}

bool operator != (const Date& lhs, const Date& rhs){return tie(lhs.year, lhs.month, lhs.day) != tie(rhs.year, rhs.month, rhs.day);}
bool operator != (const Time& lhs, const Time& rhs){return tie(lhs.hours, lhs.minutes) != tie(rhs.hours, rhs.minutes);}

bool operator == (const Date& lhs, const Date& rhs){return tie(lhs.year, lhs.month, lhs.day) == tie(rhs.year, rhs.month, rhs.day);}
bool operator == (const Time& lhs, const Time& rhs){return tie(lhs.hours, lhs.minutes) == tie(rhs.hours, rhs.minutes);}

ostream& operator << (ostream& stream, const Date& rhs){return stream<<rhs.year<<"-"<<rhs.month<<"-"<<rhs.day;}
ostream& operator << (ostream& stream, const Time& rhs){return stream<<rhs.hours<<":"<<rhs.minutes;}

istream& operator >> (istream& stream, Date& rhs){char ch; return stream>>rhs.year>>ch>>rhs.month>>ch>>rhs.day;}
istream& operator >> (istream& stream, Time& rhs){char ch; return stream>>rhs.hours>>ch>>rhs.minutes;}

#define UPDATE_FIELD(ticket, field, values) { \
        auto it = values.find(#field);        \
        if (it != values.end())      {        \
            stringstream stream(it->second);  \
            stream>>ticket.field;            \
        }                                     \
}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
