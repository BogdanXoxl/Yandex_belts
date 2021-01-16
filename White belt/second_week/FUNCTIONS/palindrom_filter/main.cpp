#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> PalindromFilter(const vector<string>& v, int minLength){
    vector<string> result;
    for(const auto& i: v)
        if(i.size() >= minLength && string(i.rbegin(), i.rend()) == i)
            result.push_back(i);
    return result;
}
int main(){

    return 0;
}