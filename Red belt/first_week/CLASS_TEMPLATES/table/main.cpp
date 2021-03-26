#include "test_runner.h"
#include <vector>
#include <utility>

using namespace std;

template <class T>
class Table{
public:
    Table(size_t x, size_t y);
    vector<T>& operator [](const int& pos){return _table[pos];}
    const vector<T>& operator [](const int& pos) const {return _table.at(pos);}
    pair<size_t, size_t> Size()const {
        if(!_table.empty() && !_table[0].empty()) {
            return {_table.size(), _table[0].size()};
        }
        return  {0, 0};
    }
    void Resize(size_t x, size_t y);
private:
    vector<vector<T>> _table;
};

template<class T>
Table<T>::Table(size_t x, size_t y) {
    Resize(x,y);
}

template<class T>
void Table<T>::Resize(size_t x, size_t y) {
    if(x && y){
        _table.resize(x);
        for(auto& i: _table)
            i.resize(y);
    }
    else
        _table.resize(0);

}

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
