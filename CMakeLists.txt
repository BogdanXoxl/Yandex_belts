cmake_minimum_required(VERSION 3.17)
project(Yandex_belts)


set(CMAKE_CXX_STANDARD 20)

add_executable(Yandex_belts
        "Red belt/first_week/MACROS/macro_UPDATE_FIELD/airline_ticket.h"
        "Red belt/first_week/MACROS/macro_UPDATE_FIELD/update_field.cpp"
        "Red belt/first_week/MACROS/macro_UPDATE_FIELD/test_runner.h"
        "Red belt/first_week/MACROS/macro_UPDATE_FIELD/test_runner.cpp"
        "Red belt/first_week/MACROS/macro_UPDATE_FIELD/profile.h"
        "Red belt/first_week/MACROS/macro_UPDATE_FIELD/profile.cpp"
        )

