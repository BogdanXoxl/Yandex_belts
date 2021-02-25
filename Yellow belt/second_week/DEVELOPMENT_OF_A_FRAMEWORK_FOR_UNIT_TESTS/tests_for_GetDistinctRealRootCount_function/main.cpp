#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <random>

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

int GetDistinctRealRootCount(double a, double b, double c);
//b2 - 4ac
//ax2 + bx + c = 0
void TestNoRoots(){
    AssertEqual(GetDistinctRealRootCount(1,0,1), 0, "0");
    AssertEqual(GetDistinctRealRootCount(1,3,4), 0, "0");
    AssertEqual(GetDistinctRealRootCount(1,-1,1), 0, "0");
}

void TestConstant(){
    AssertEqual(GetDistinctRealRootCount(0,0,1), 0, "0");
    AssertEqual(GetDistinctRealRootCount(0,0,-99999), 0, "0");
    AssertEqual(GetDistinctRealRootCount(0,0,9999999), 0, "0");
    AssertEqual(GetDistinctRealRootCount(0,3,999), 1, "1");
    AssertEqual(GetDistinctRealRootCount(1,3,999), 0, "0");
}
void TestOneRoot(){
    for(int b = 1; b < 100; ++b)
        for(int c = 0; c < 100; ++c)
            AssertEqual(GetDistinctRealRootCount(0,b,c), 1, "1");
}

void TestTwoRoot(){
    AssertEqual(GetDistinctRealRootCount(1,3,1), 2, "1");
    AssertEqual(GetDistinctRealRootCount(-5,3,999), 2, "1");
    AssertEqual(GetDistinctRealRootCount(5,-3,-999), 2, "1");
}

void TestCountRoots(){
    for(int a = 0; a < 10; ++a)
        for(int b = 0; b < 10; ++b)
            for(int c = 0; c< 10; ++c)
                Assert(GetDistinctRealRootCount(a,b,c) < 3 && GetDistinctRealRootCount(a,b,c) >= 0,"<3>0" );
}



int main() {
  TestRunner runner;
  runner.RunTest(TestCountRoots, "TestRootCount");
  runner.RunTest(TestOneRoot, "TestOneRoot");
  runner.RunTest(TestNoRoots, "TestNoRoots");
  runner.RunTest(TestTwoRoot, "TestLinearEquation");
  runner.RunTest(TestConstant, "TestConstant");
  return 0;
}