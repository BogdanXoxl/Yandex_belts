#include <vector>
#include <string>
#include <exception>

using namespace std;


template <class T>
class Deque{
public:
    Deque(){}
    bool Empty() const {return _vfront.empty() && _vback.empty();}
    size_t Size() const {return _vback.size() + _vfront.size();}

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T& At(size_t index);
    const T& At(size_t index) const;

    T& Front(){return _vfront.empty()? _vback.front(): _vfront.back();}
    const T& Front() const{return _vfront.empty()? _vback.front(): _vfront.back();}

    T& Back(){ return _vback.empty()? _vfront.front(): _vback.back();}
    const T& Back() const{ return _vback.empty()? _vfront.front(): _vback.back();}

    void PushFront(const T& value){_vfront.push_back(value);}
    void PushBack(const T& value){_vback.push_back(value);}
private:
    vector<T> _vfront;
    vector<T> _vback;
    void _check (size_t index) const {if(index >= Size()) throw out_of_range("");}

    T& _get(size_t index){return (index >= _vfront.size())? _vback[index - _vfront.size()] : _vfront[_vfront.size() - index - 1];}
    const T& _get(size_t index) const{return (index >= _vfront.size())? _vback[index - _vfront.size()] : _vfront[_vfront.size() - index - 1];}
};

template<class T>
T &Deque<T>::At(size_t index) {
    _check(index);
    return _get(index);
}

template<class T>
const T &Deque<T>::At(size_t index) const {
    _check(index);
    return _get(index);
}

template<class T>
T &Deque<T>::operator[](size_t index) {
    return _get(index);
}

template<class T>
const T &Deque<T>::operator[](size_t index) const {
    return _get(index);
}

int main(){
return 0;
}

