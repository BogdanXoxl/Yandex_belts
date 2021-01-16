#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin>>str;

    switch (count(str.begin(), str.end(), 'f')) {
        case 1:
            cout<<-1<<endl;
            break;
        case 0:
            cout<<-2<<endl;
            break;
        default:
            cout<<str.find('f' , str.find('f')+1)<<endl;
    }
    return 0;
}
