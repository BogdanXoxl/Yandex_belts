#include <iostream>

using namespace std;

int main(){
    int _start = 0, _end = 0;
    cin>>_start>>_end;

    for(_start; _start <= _end; ++_start)
        if(_start%2 == 0)
            cout<<_start<<endl;


    return 0;
}