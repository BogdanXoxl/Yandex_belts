#include <iostream>
#include <fstream>

using namespace std;

//Part 1

int main(){
    ifstream file("input.txt");
    for(string str; getline(file,str);)
        cout<<str<<endl;
    return 0;
}

//Part 2

//int main(){
//    ifstream file("input.txt");
//    ofstream ofile("output.txt");
//    for(string str; getline(file,str);)
//        ofile<<str<<"\n";
//    return 0;
//}