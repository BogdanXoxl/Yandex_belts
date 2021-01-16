#include <iostream>
#include "../Tools/profile.h"


using namespace std;

int main() {
    LOG_DURATION("123");
    cout << "Hello, World!" << endl;
    return 0;
}
