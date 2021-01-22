#include <iostream>

using namespace std;

struct Specialization{
    explicit Specialization(const string& str):specialization(str) {}
    string specialization;
};

struct Course{
    explicit Course(const string& str):course(str) {}
    string course;
};

struct Week{
    explicit Week(const string& str):week(str) {}
    string week;
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  explicit LectureTitle(const Specialization& spec, const Course& course, const Week& week):specialization(spec.specialization),
    course(course.course), week(week.week){}
};

LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);

int main(){
    return 0;
}