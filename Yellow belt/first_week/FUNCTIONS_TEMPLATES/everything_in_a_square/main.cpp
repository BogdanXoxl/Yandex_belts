#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

template<class T>
T Sqr(T);

template<class T, class S>
pair<T, S> Sqr(pair<T, S>);

template<class T, class S>
map<T,S> Sqr(map<T, S>);

template<class T>
vector<T> Sqr(vector<T>);


int main(){
        // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
      cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
}


template<class T>
T Sqr(T a){
    return a*a;
}

template<class T>
vector<T> Sqr(vector<T> v){
    for(auto& i:v)
        i = Sqr(i);
    return v;
}

template<class T, class S>
pair<T, S> Sqr(pair<T, S> p){
    p.first = Sqr(p.first);
    p.second = Sqr(p.second);
    return p;
}

template<class T, class S>
map<T,S> Sqr(map<T, S> m){
    for(auto& [key, value]: m)
        value = Sqr(value);
    return m;
}
