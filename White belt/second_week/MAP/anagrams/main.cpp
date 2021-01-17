#include <iostream>
#include <algorithm>
#include <map>
//#include "../../../../Tools/profile.h"

using namespace std;

bool FIRST_is_anagrams(const string& str1, const string& str2){
    return is_permutation(str1.begin(),str1.end(), str2.begin());
}

map<char, int> BuildCharCounters(const string& str){
    map<char, int> result;
    for(const char& i: str)
        ++result[i];
    return result;
}

int main(){
    int Q = 0;
    string str1, str2;
    cin>>Q;
    for(;Q>0;--Q){
        cin>>str1>>str2;

//        {
//            LOG_DURATION("FIRST");
//            cout<<(FIRST_is_anagrams(str1,str2)?"YES":"NO")<<endl;
//        }
        {
            //LOG_DURATION("SECOND");
            if(BuildCharCounters(str1) == BuildCharCounters(str2))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }

    }
    return 0;
}
