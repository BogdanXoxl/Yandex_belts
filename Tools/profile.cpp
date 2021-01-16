//
// Created by Богдан Хохлов on 09.01.2021.
//

#include "profile.h"

LogDuration::~LogDuration(){
        auto finish = std::chrono::steady_clock::now();
        cerr<<msg<<duration_cast<std::chrono::milliseconds>(finish-start).count()<<" ms; "<<duration_cast<std::chrono::microseconds>(finish-start).count()<<"μs;"<<endl;
    }

