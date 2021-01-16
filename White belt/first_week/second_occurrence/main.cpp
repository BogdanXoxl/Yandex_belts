#include <iostream>
#include <string>
#include <algorithm>
#include "../../../Tools/profile.h"

using namespace std;
//SECOND faster then FIRST  but FIRST more understandable

void first(const string& str){
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
}

void second(const string& str){
    int result = -2;

    for (int i = 0; i < str.size(); ++i)
     if (str[i] == 'f')
        if (result == -2)
            result = -1;
        else if (result == -1) {
            result = i;
            break;
        }
    cout << result;
}

int main(){

    {
        LOG_DURATION("FIRST");
        first("tuytuystdydasytyutduiydoaisudoiusoiduaoisduaoisduasodyftwyuudoiwuywyustdyuiwoiwudiouwofiusdywtusyduuwoiu");
    }
    {
        LOG_DURATION("SECOND");
        second("tuytuystdydasytyutduiydoaisudoiusoiduaoisduaoisduasodyftwyuudoiwuywyustdyuiwoiwudiouwofiusdywtusyduuwoiu");
    }
    {
        LOG_DURATION("FIRST");
        first("ff");
    }
    {
        LOG_DURATION("SECOND");
        second("ff");
    }
    {
        LOG_DURATION("FIRST");
        first("fasf");
    }
    {
        LOG_DURATION("SECOND");
        second("fasf");
    }
    return 0;
}
