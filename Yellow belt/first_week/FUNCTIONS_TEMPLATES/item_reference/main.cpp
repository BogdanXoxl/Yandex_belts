#include <iostream>
#include <map>

using namespace std;

template<class T, class S>
S& GetRefStrict(map<T,S>& m, T el){
    try{
        return m.at(el);
    } catch (exception&) {
        throw runtime_error("");
    }
}
int main(){
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue

    return 0;
}