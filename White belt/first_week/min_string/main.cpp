#include <iostream>
#include <algorithm>

using namespace std;

// TESTS
/*
stdin	                stdout

milk milkshake month	milk
c a b	                a
fire fog wood	        fire
m m m                   m
123 321 213             123

*/

int main(){
    string str1, str2, str3;
    cin>>str1>>str2>>str3;
    cout<<min(str1, min(str2, str3));
    return 0;
}