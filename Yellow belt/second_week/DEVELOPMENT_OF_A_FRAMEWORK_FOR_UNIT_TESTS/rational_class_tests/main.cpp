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

//class Rational {
//public:
//  Rational();
//  Rational(int numerator, int denominator) {}
//  int Numerator() const {}
//  int Denominator() const {}
//};

void TestConstructor(){
    AssertEqual(Rational().Denominator(), 1, "TestConstructor");
    AssertEqual(Rational().Numerator(), 0, "TestConstructor");
    AssertEqual(Rational(0,5).Numerator(), 0, "TestConstructor");
    AssertEqual(Rational(0,5).Denominator(), 1, "TestConstructor");
}

void TestReduction(){
    AssertEqual(Rational(5,15).Denominator(), 3, "TestReduction");
    AssertEqual(Rational(5,15).Numerator(), 1, "TestReduction");
    AssertEqual(Rational(-3,-15).Denominator(), 5, "TestReduction");
    AssertEqual(Rational(-3,15).Numerator(), -1, "TestReduction");
    AssertEqual(Rational(24,26).Numerator(), 12, "TestReduction");
    AssertEqual(Rational(24,26).Denominator(), 13, "TestReduction");
}

void TestNegative(){
    AssertEqual(Rational(-1,-2).Denominator(), 2, "TestNegative");
    AssertEqual(Rational(-1,-2).Numerator(), 1, "TestNegative");
    AssertEqual(Rational(1,-2).Numerator(), -1, "TestNegative");
    AssertEqual(Rational(1,-2).Denominator(), 2, "TestNegative");
    AssertEqual(Rational(-1,2).Numerator(), -1, "TestNegative");
    AssertEqual(Rational(-1,2).Denominator(), 2, "TestNegative");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestConstructor, "TestConstructor");
  runner.RunTest(TestNegative, "TestNegative");
  runner.RunTest(TestReduction, "TestReduction");
  return 0;
}