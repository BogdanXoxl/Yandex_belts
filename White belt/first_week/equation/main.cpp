#include <iostream>
#include <cmath>

using namespace std;

void equation(const double& a, const double& b);//if a == 0 then equation is not sqr
void sqr_equation(const double& a, const double& b, const double& c, const double& D);


int main(){
    double a, b, c;
    cin>>a>>b>>c;
    if(a == 0)
        equation(b,c);
    else
        sqr_equation(a,b,c, (b*b-4*a*c));
    return 0;
}

void equation(const double& a, const double& b){
    if(a != 0)
        cout<< -b/a<<endl;
}

void sqr_equation(const double& a, const double& b, const double& c, const double& D){
    if(D == 0)
        cout<<(-b + sqrt(D))/(2 * a)<<endl;
    else if(D<0)
        return;
    else
        cout<<(-b + sqrt(D))/(2 * a)<<" "<<(-b - sqrt(D))/(2 * a)<<endl;
}