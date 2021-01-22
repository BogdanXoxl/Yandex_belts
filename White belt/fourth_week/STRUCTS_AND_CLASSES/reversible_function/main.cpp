#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class FunctionPart{
public:
    FunctionPart(char new_operation, double new_value):operation(new_operation), value(new_value){}
    double Apply(double source_value)const{return (operation == '-'?source_value - value: source_value + value);}
    void Invert(){operation = (operation == '+'? '-':'+' );}
private:
    char operation;
    double value;
};

class Function{
public:
    void AddPart(char operation, double value){
        parts.emplace_back(operation, value);
    }
    double Apply(double value) const{
        for(const auto& part: parts)
            value = part.Apply(value);
        return value;
    }
    void Invert(){
        for(auto& part: parts)
            part.Invert();
        reverse(parts.begin(), parts.end());
    }
private:
    vector<FunctionPart> parts;
};
