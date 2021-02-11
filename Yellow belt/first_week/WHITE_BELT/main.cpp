#include <iostream>
#include <vector>

using namespace std;

class Matrix{
public:
    Matrix()= default;
    Matrix(int num_rows, int num_cols){Reset(num_rows, num_cols);}
    void Reset(int rows, int cols);
    int At(int row, int col) const;
    int& At(int row, int col);
    int GetNumRows() const;
    int GetNumColumns() const;
    auto begin() const;
    auto begin();
    auto end() const;
    auto end();
private:
    int num_rows_{0};
    int num_columns_{0};
    vector<vector<int>> v;
};

istream& operator >> (istream& stream, Matrix& m);
ostream& operator << (ostream& stream, const Matrix& m);
bool operator == (const Matrix& one, const Matrix& two);
Matrix operator + (const Matrix& one, const Matrix& two);

auto Matrix::begin() const{return v.begin();}
auto Matrix::begin(){return v.begin();}
auto Matrix::end() const{return v.end();}
auto Matrix::end(){return v.end();}

void Matrix::Reset(int rows, int cols) {
    if(rows < 0 || cols < 0)
        throw out_of_range("");
    if(rows == 0 || cols == 0)
        rows = cols = 0;
    num_rows_ = rows;
    num_columns_ = cols;
    v.assign(rows, vector<int>(cols));
}

int Matrix::At(int row, int col) const {
    return v.at(row).at(col);
}

int &Matrix::At(int row, int col) {
    return v.at(row).at(col);
}

int Matrix::GetNumRows() const {
    return num_rows_;
}

int Matrix::GetNumColumns() const {
    return num_columns_;
}

istream& operator >> (istream& stream, Matrix& m){
    int cols, rows;
    stream>>rows>>cols;
    m = Matrix(rows, cols);
    for(auto& row: m)
        for(auto& col: row)
            stream>>col;
    return stream;
}
ostream& operator << (ostream& stream, const Matrix& m){
    bool first = true;
    stream<<m.GetNumRows()<<" "<<m.GetNumColumns()<<endl;
    for(const auto& row: m){
        for(const auto& item: row){
            if(!first)
                stream<<" ";
            stream << item;
            first = false;
        }
        first = true;
        stream<<endl;
    }
    return stream;
}
Matrix operator + (const Matrix& one, const Matrix& two){
    if(one.GetNumRows() != two.GetNumRows() || one.GetNumColumns() != two.GetNumColumns())
        throw invalid_argument("Operator +: " + to_string(one.GetNumRows()) + "/" + to_string(one.GetNumColumns()) + " != " + to_string(two.GetNumRows()) + "/" + to_string(two.GetNumColumns()));
    Matrix result(one.GetNumRows(), one.GetNumColumns());
    for(int i = 0; i < one.GetNumRows(); ++i)
        for(int j = 0; j < one.GetNumColumns(); ++j)
            result.At(i, j) = one.At(i, j) + two.At(i, j);
    return result;
}
bool operator == (const Matrix& one, const Matrix& two){
    if(one.GetNumRows() != two.GetNumRows() || one.GetNumColumns() != two.GetNumColumns())
        return false;
    for(int i = 0; i < one.GetNumRows(); ++i)
        for(int j = 0; j < one.GetNumColumns(); ++j)
            if(one.At(i, j) != two.At(i, j))
                return false;

    return true;
}
//int main() {
//  Matrix one;
//  Matrix two;
//
//  cin >> one >> two;
//  cout << one + two << endl;
//  return 0;
//}