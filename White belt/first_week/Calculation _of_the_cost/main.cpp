#include <iostream>

using namespace std;

int main(){
    //N - summary cost
    //A, B - level
    //X, Y - discount
    double N, A, B, X, Y;

    cin>>N>>A>>B>>X>>Y;

    if(N > B)
        N *= (1 - Y / 100);
    else if(N>A)
        N *= (1 - X / 100);

    cout<<N<<endl;

    return 0;
}