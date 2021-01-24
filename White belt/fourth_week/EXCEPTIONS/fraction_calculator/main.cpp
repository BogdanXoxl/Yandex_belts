#include <iostream>
#include <exception>
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
    Rational a, b;
    char ch;
     try{
        cin>>a>>ch>>b;
        switch (ch) {
            case '+':
                cout<<a+b<<endl;
                break;
            case '-':
                cout<<a-b<<endl;
                break;
            case '/':
                    cout<<a/b<<endl;
                break;
            case '*':
                cout<<a*b<<endl;
                break;
        }
    } catch (domain_error& e) {
        cout<<"Division by zero"<<endl;
    }catch(invalid_argument& e){
        cout<<"Invalid argument"<<endl;
    }
    return 0;
}