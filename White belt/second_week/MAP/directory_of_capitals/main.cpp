#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Directory{
public:
    string CHANGE_CAPITAL(const string& country,const string& new_capital);
    string RENAME(const string& old_country_name, const string& new_country_name);
    string ABOUT(const string& country)const;
    string DUMP()const;
private:
    map<string, string> countries;
};

string Directory::CHANGE_CAPITAL(const string &country, const string &new_capital) {
    string result;
    if(countries.count(country) == 1){
        if(countries[country] == new_capital)
            result = "Country " + country + " hasn't changed its capital";
        else
            result = "Country " + country + " has changed its capital from " + countries[country] + " to " + new_capital;
    }else
        result = "Introduce new country " + country + " with capital "+ new_capital;

    countries[country]  = new_capital;
    return result;
}

string Directory::RENAME(const string &old_country_name, const string &new_country_name) {
    string result;

    if(countries.count(old_country_name) == 1 && countries.count(new_country_name) == 0){
        countries[new_country_name] = countries[old_country_name];
        countries.erase(old_country_name);
        result = "Country " + old_country_name + " with capital " + countries[new_country_name] + " has been renamed to " + new_country_name;
    }
    else
        result = "Incorrect rename, skip";
    return result;
}

string Directory::ABOUT(const string &country) const {
    string result;
    if(countries.count(country) == 1)
        result = "Country " + country + " has capital " + countries.at(country);
    else
        result = "Country " + country + " doesn't exist";
    return result;
}

string Directory::DUMP() const {
    stringstream stream;
    if(countries.empty())
        stream<<"There are no countries in the world";
    else
        for(const auto& i: countries)
            stream<<i.first<<"/"<<i.second<<" ";
    return stream.str();
}

int main(){
    int Q = 0;
    Directory d;
    cin>>Q;
    string command, country, content;//content - new_country_name, new_capital
    for(;Q>0;--Q){
        cin>>command;
        if(command == "CHANGE_CAPITAL"){
            cin>>country>>content;
            cout<<d.CHANGE_CAPITAL(country, content)<<endl;
        }else if(command == "RENAME"){
            cin>>country>>content;
            cout<<d.RENAME(country, content)<<endl;
        }else if(command == "ABOUT"){
            cin>>country;
            cout<<d.ABOUT(country)<<endl;
        }else if(command == "DUMP"){
            cout<<d.DUMP()<<endl;
        }
    }
    return 0;
}