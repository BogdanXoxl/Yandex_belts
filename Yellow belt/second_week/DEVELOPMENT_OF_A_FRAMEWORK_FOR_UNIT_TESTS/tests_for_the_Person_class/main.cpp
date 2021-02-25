#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

//class Person {
//public:
//  void ChangeFirstName(int year, const string& first_name) {
//  }
//  void ChangeLastName(int year, const string& last_name) {
//  }
//  string GetFullName(int year) {
//  }
//};

void TestChangeFirstName(){
        Person p;
        p.ChangeFirstName(1,"Alibaba");
        AssertEqual(p.GetFullName(1), "Alibaba with unknown last name");
        AssertEqual(p.GetFullName(5), "Alibaba with unknown last name");
        AssertEqual(p.GetFullName(0), "Incognito");
        p.ChangeFirstName(2, "Muhamed");
        AssertEqual(p.GetFullName(1), "Alibaba with unknown last name");
        AssertEqual(p.GetFullName(2), "Muhamed with unknown last name");
        AssertEqual(p.GetFullName(5), "Muhamed with unknown last name");
        AssertEqual(p.GetFullName(0), "Incognito");
}

void TestChangeLastName(){
    Person p;
    p.ChangeLastName(1,"Lua");
    AssertEqual(p.GetFullName(1), "Lua with unknown first name");
    AssertEqual(p.GetFullName(5), "Lua with unknown first name");
    AssertEqual(p.GetFullName(0), "Incognito");
    p.ChangeLastName(2, "Ali");
    AssertEqual(p.GetFullName(1), "Lua with unknown first name");
    AssertEqual(p.GetFullName(2), "Ali with unknown first name");
    AssertEqual(p.GetFullName(5), "Ali with unknown first name");
    AssertEqual(p.GetFullName(0), "Incognito");
}
void TestGetFullName(){
    Person p;
    p.ChangeLastName(1,"Muhamed");
    p.ChangeFirstName(3, "Ali");
    AssertEqual(p.GetFullName(1), "Muhamed with unknown first name");
    AssertEqual(p.GetFullName(2), "Muhamed with unknown first name");
    AssertEqual(p.GetFullName(3), "Ali Muhamed");
    AssertEqual(p.GetFullName(0), "Incognito");
    p.ChangeFirstName(4, "Lua");
    AssertEqual(p.GetFullName(4), "Lua Muhamed");
    AssertEqual(p.GetFullName(5), "Lua Muhamed");
    AssertEqual(p.GetFullName(3), "Ali Muhamed");
    p.ChangeLastName(4, "Lukoabrazi");
    AssertEqual(p.GetFullName(4), "Lua Lukoabrazi");
    AssertEqual(p.GetFullName(5), "Lua Lukoabrazi");
    AssertEqual(p.GetFullName(3), "Ali Muhamed");
    AssertEqual(p.GetFullName(5), "Lua Lukoabrazi");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestGetFullName, "TestGetFullName");
  runner.RunTest(TestChangeLastName, "TestChangeLastName");
  runner.RunTest(TestChangeFirstName, "TestChangeFirstName");

  return 0;
}