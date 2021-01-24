#include <iostream>

using namespace std;

//string AskTimeServer();

class TimeServer {
public:
  string GetCurrentTime(){
      try{
         return last_fetched_time = AskTimeServer();
      } catch (system_error& e) {
          return last_fetched_time;
      }
  }
private:
  string last_fetched_time = "00:00:00";
};

int main(){
    return 0;
}