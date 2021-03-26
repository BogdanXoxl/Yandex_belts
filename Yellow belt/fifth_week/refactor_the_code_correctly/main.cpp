#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;


class People{
public:
    People(const string& name, const string& type):Name(name), Type(type){}

    virtual void Walk(const string& destination) const{
        cout << Type << ": " << Name << " walks to: " << destination << endl;
    }
    const string Name;
    const string Type;
};

class Student: public People{
public:

    explicit Student(const string& name, const string& favouriteSong): People(name, "Student"), FavouriteSong(favouriteSong){}

    void Learn() const {
        Log() << " learns" << endl;
    }

    void SingSong() const {
        Log() << " sings a song: " << FavouriteSong << endl;
    }

    void Walk(const string& destination) const override {
        People::Walk(destination);
        SingSong();
    }

public:
    const string FavouriteSong;
private:
    ostream& Log() const {return cout << "Student: " << Name;}
};


class Teacher:public People {
public:

    explicit Teacher(const string& name, const string& subject):People(name, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

public:
    const string Subject;
};


class Policeman: public People {
public:
    explicit Policeman(const string& name):People(name, "Policeman") {}

    void Check(const People& t) const {
        cout << "Policeman: " << Name << " checks "<<t.Type<<". "<<t.Type<<"'s name is: " << t.Name << endl;
    }
};


void VisitPlaces(const People& p, const vector<string>& places) {
    for (auto& place : places)
        p.Walk(place);
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
