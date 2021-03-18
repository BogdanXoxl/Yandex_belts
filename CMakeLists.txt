cmake_minimum_required(VERSION 3.17)
project(Yandex_belts)


set(CMAKE_CXX_STANDARD 20)

add_executable(Yandex_belts
        "Yellow belt/sixth_week/FINAL_PROJECT/main.cpp"
        "Yellow belt/sixth_week/FINAL_PROJECT/date.cpp"
        "Yellow belt/sixth_week/FINAL_PROJECT/date.h"
        "Yellow belt/sixth_week/FINAL_PROJECT/database.cpp"
        "Yellow belt/sixth_week/FINAL_PROJECT/database.h"

        "Yellow belt/sixth_week/FINAL_PROJECT/node.cpp"
        "Yellow belt/sixth_week/FINAL_PROJECT/node.h"
        "Yellow belt/sixth_week/FINAL_PROJECT/condition_parser.cpp"
        "Yellow belt/sixth_week/FINAL_PROJECT/condition_parser.h"
        "Yellow belt/sixth_week/FINAL_PROJECT/token.cpp"
        "Yellow belt/sixth_week/FINAL_PROJECT/token.h"
        "Yellow belt/sixth_week/FINAL_PROJECT/condition_parser_test.cpp"
        "Yellow belt/sixth_week/FINAL_PROJECT/test_runner.cpp"
        "Yellow belt/sixth_week/FINAL_PROJECT/test_runner.h"
        "Tools/profile.cpp"
        "Tools/profile.h"


        "Yellow belt/sixth_week/FINAL_PROJECT/tests.h"
        )

