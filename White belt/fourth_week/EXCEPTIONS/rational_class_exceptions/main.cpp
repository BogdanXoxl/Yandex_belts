#include <iostream>
#include <exception>
#include <map>
#include <set>
#include <vector>
#include <numeric>

using namespace std;

class Rational {
public:
    Rational():numerator(0), denominator(1){}
    Rational(int numerator, int denominator){
        if(denominator == 0)
            throw invalid_argument("");
        this->numerator = numerator/gcd(numerator, denominator) * (denominator<0?-1:1);
        this->denominator = denominator/gcd(numerator, denominator) * (denominator<0?-1:1);
    }

    int Numerator() const {return numerator;}
    int Denominator() const {return denominator;}

    bool operator == (const Rational& r) const{
        return denominator == r.denominator && numerator == r.numerator;
    }
    bool operator < (const Rational& r) const{
        return numerator*r.denominator < denominator*r.numerator;
    }

    Rational operator + (const Rational& r) const{
        return Rational(numerator * r.denominator + r.numerator * denominator, denominator * r.denominator);
    }
    Rational operator - (const Rational& r) const{
        return  Rational(numerator * r.denominator - r.numerator * denominator, denominator * r.denominator);
    }
    Rational operator / (const Rational& r) const{
        if(r.numerator == 0)
            throw domain_error("");
        return Rational(numerator * r.denominator, denominator * r.numerator);
    }
    Rational operator * (const Rational& r) const{
        return Rational(numerator * r.numerator, denominator * r.denominator);
    }

private:
    int numerator;
    int denominator;
};

istream& operator >> (istream& is, Rational& r){
  int n, d;
  char c;
  if (is) {
      is >> n >> c >> d;
      if (is)
          if (c == '/')
              r = Rational(n, d);
          else
              is.setstate(ios_base::failbit);

  }
    return is;
}

ostream& operator << (ostream& stream, const Rational& r){
    stream<<r.Numerator()<<'/'<<r.Denominator();
    return stream;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}