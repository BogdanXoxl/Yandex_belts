#include <iostream>
#include <iomanip>
#include <fstream>

#include <sstream>

using namespace std;

int main(){
    ifstream input("input.txt");
//    stringstream input;
//    input<<2<<" "<<3<<endl<<1<<","<<2<<","<<3<<endl<<4<<","<<5<<","<<6<<endl;
    int N, M, data;
    if(input){
        input>>N>>M;
        for(int i = 0; i<N; ++i){
            for(int j = 0; j<M; ++j){
                input>>data;
                input.ignore(1);
                cout<<setw(10)<<data;
                if(j+1<M)
                    cout<<" ";
            }
            if(i+1<N)
                    cout<<endl;
        }
    }
    return 0;
}