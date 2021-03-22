cmake_minimum_required(VERSION 3.17)
project(Yandex_belts)


set(CMAKE_CXX_STANDARD 20)

add_executable(Yandex_belts
        "Red belt/first_week/MACROS/macro_LOG/main.cpp"
        "Red belt/first_week/MACROS/macro_LOG/test_runner.cpp"
        "Red belt/first_week/MACROS/macro_LOG/test_runner.h"
        "Red belt/first_week/MACROS/macro_LOG/profile.cpp"
        "Red belt/first_week/MACROS/macro_LOG/profile.h"
        )

