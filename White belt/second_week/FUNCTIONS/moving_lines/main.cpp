#include <iostream>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
    destination.insert(destination.end(), source.begin(), source.end());
    source.clear();
}

int main(){
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    return 0;
}