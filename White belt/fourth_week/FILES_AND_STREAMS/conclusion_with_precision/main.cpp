#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ifstream stream("input.txt");
    double a;
    cout<<fixed<<setprecision(3);
    while (stream>>a)
        cout<<a<<endl;
    return 0;
}