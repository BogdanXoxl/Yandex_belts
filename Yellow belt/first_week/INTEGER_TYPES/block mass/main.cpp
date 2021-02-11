#include <iostream>
#include <cstdint>

using namespace std;

int main(){
    int R, N, W, H, D;
    uint64_t result = 0;
    cin>>N>>R;
    for(int i = 0; i < N; ++i){
        cin>>W>>H>>D;
        result += static_cast<uint64_t>(W)*H*D;
    }
    cout<<result*R<<endl;
    return 0;
}