#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

struct Date{
    int Day;
    int Month;
    int Year;
    Date():Day(1),Month(1),Year(1){}
    Date(int new_year, int new_month, int new_day);
};

class Database{
public:
    void AddEvent(const Date& date, const string& event);
    string Del(const Date& date, const string& event = "");
    string Find(const Date& date) const;
    string Print() const;
private:
    map<Date, set<string>> db;
};

ostream& operator << (ostream& stream, const Date& date);
istream& operator >> (istream& stream, Date& date);
bool operator < (const Date& ldate, const Date& rdate);


int main(){
    string command_line, command;
    stringstream stream;

    try{
        Database db;
        while(getline(cin, command_line)){
            if(!command_line.empty()){
                stream<<command_line;
                stream>>command;
                if(command == "Add"){
                    Date date;
                    string event;
                    stream>>date>>event;
                    db.AddEvent(date, event);
                }else if(command == "Del"){
                    Date date;
                    string event;
                    stream>>date;
                    if(!stream.eof())
                        stream>>event;
                    cout<<db.Del(date, event)<<endl;
                }else if(command == "Find"){
                    Date date;
                    stream>>date;
                    cout<<db.Find(date);
                }else if(command == "Print")
                    cout<<db.Print();
                else if(!command.empty())
                    throw logic_error("Unknown command: " + command);
            }
            stream.clear();
        }
    }catch(const exception& e){
        cout<<e.what();
    }
    return 0;
}


Date::Date(int new_year, int new_month, int new_day) {
    Year = new_year;
    if (new_month > 12 || new_month < 1) {
      throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    Month = new_month;
    if (new_day > 31 || new_day < 1) {
      throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    Day = new_day;
}

ostream& operator << (ostream& stream, const Date& date){
    stream<<setw(4)<<setfill('0')<<date.Year
            <<"-"<<setw(2)<<setfill('0')<<date.Month
            <<"-"<<setw(2)<<setfill('0')<<date.Day;
    return stream;
}

istream& operator >> (istream& stream, Date& date){
    int day, month, year;
    bool ok = true;
    stringstream strstream;
    string str;

    stream>>str;
    strstream<<str;

    ok = ok && (strstream >> year) && (strstream.peek() == '-');
    strstream.ignore(1);
    ok = ok && (strstream >> month) && (strstream.peek() == '-');
    strstream.ignore(1);
    ok = ok && (strstream >> day) && strstream.eof();

    if(!ok)
        throw invalid_argument("Wrong date format: " + str);
    date = Date(year, month, day);
    return stream;
}

bool operator < (const Date& ldate, const Date& rdate){
    return tie(ldate.Year, ldate.Month, ldate.Day) < tie(rdate.Year, rdate.Month, rdate.Day);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DatabaseDatabaseDatabaseDatabaseDatabaseDatabaseDatabaseDatabaseDatabaseDatabaseDatabaseDatabaseDatabaseDatabaseDatabase/////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Database::AddEvent(const Date& date, const string& event) {
    db[date].insert(event);
}

string Database::Del(const Date &date, const string &event) {
    if(event.empty()){
        const int count = db[date].size();
        if(db.count(date) > 0)
            db.erase(date);
        return "Deleted " + to_string(count) + " events";
    }else if(db.count(date) > 0 && db[date].count(event) > 0){
            db[date].erase(event);
            return "Deleted successfully";
        }
    return "Event not found";
}

string Database::Find(const Date &date) const{
    stringstream stream;
    try{
        for(const auto& i: db.at(date))
            stream<<i<<endl;
    } catch (exception&) {}
    return stream.str();
}

string Database::Print() const{
    stringstream stream;
    for(const auto& [date, events]: db){
        for(const auto& e: events)
            stream << date << " " << e << endl;
    }
    return stream.str();
}
