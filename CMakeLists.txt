cmake_minimum_required(VERSION 3.17)
project(Yandex_belts)


set(CMAKE_CXX_STANDARD 20)

add_executable(Yandex_belts
        "Red belt/first_week/MACROS/comparator_generator/airline_ticket.h"
        "Red belt/first_week/MACROS/comparator_generator/sort_by.cpp"
        "Red belt/first_week/MACROS/comparator_generator/test_runner.cpp"
        "Red belt/first_week/MACROS/comparator_generator/test_runner.h"
        "Red belt/first_week/MACROS/comparator_generator/profile.h"
        "Red belt/first_week/MACROS/comparator_generator/profile.cpp"
        )

