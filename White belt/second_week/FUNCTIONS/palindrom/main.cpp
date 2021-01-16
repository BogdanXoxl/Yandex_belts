#include <iostream>
#include "../../../../Tools/profile.h"

using namespace std;

bool IsPalindrom(const string& str){
    return string(str.rbegin(), str.rend()) == str;
}

bool IsPalindrom2(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main(){
    {
        LOG_DURATION("FIRST");
        cout << IsPalindrom("madam") << endl;
        cout << IsPalindrom("gentleman") << endl;
        cout << IsPalindrom("X") << endl;
    }
    {
        LOG_DURATION("SECOND");
        cout << IsPalindrom2("madam") << endl;
        cout << IsPalindrom2("gentleman") << endl;
        cout << IsPalindrom2("X") << endl;
    }
    return 0;
}


