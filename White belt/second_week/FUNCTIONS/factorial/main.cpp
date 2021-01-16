#include <iostream>

using namespace std;

int Factorial(int a){
    return a<=1?1: a * Factorial(a-1);
}

int main(){
    cout<<Factorial(4);
    return 0;
}