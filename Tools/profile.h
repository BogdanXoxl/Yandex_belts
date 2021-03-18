#ifndef UNTITLED_PROFILE_H
#define UNTITLED_PROFILE_H

#include <iostream>

using namespace std;
using namespace std::chrono;

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)
#define LOG_DURATION(message) \
    LogDuration UNIQ_ID(__LINE__){message};


class LogDuration {
public:
    explicit LogDuration(const string& msg = "" ): start(steady_clock::now()), msg(msg + ": "){}
    ~LogDuration();
private:
    steady_clock::time_point start;
    string msg;

};


#endif //UNTITLED_PROFILE_H
