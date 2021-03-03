#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>

#define PI 3.14
using namespace std;

class Figure{
public:
    Figure(string name): name(name){}
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;

protected:
    const string name;
};

class Triangle: public Figure{
public:
    Triangle(int a, int b, int c): Figure("TRIANGLE"), a(a), b(b), c(c), P(a + b + c){}
    string Name() override {return name;}
    double Perimeter() override {return P;}
    double Area() override {return sqrtl(P/2 * (P/2 - a) * (P/2 - b) * (P/2 - c));}
private:
    int a,b,c;
    double P;
};

class Rect: public Figure{
public:
    Rect(int width, int height): Figure("RECT"), width(width), height(height){}
    string Name() override {return name;}
    double Perimeter() override {return (width + height) * 2;};
    double Area() override {return width * height;}
private:
    int width, height;
};

class Circle: public Figure{
public:
    Circle(int R): Figure("CIRCLE"), R(R){}
    string Name() override { return name;}
    double Perimeter() override {return 2 * PI * R;}
    double Area() override{return PI * R * R;}
private:
    int R;
};

shared_ptr<Figure> CreateFigure(istream& stream){
    string name;
    stream >> name;
    if(name == "RECT"){
        int a,b;
        stream>>a>>b;
        return make_shared<Rect>(a,b);
    }else if(name == "TRIANGLE"){
        int a,b,c;
        stream>>a>>b>>c;
        return make_shared<Triangle>(a,b,c);
    }else if(name == "CIRCLE"){
        int R;
        stream >> R;
        return make_shared<Circle>(R);
    }
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}