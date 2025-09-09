cmake_minimum_required(VERSION 3.20)
project(RPN_Calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение тестов
enable_testing()

# Поиск GoogleTest
find_package(GTest REQUIRED)

# Основное приложение
add_executable(rpn_calculator src/main.cpp src/rpn.cpp)
target_include_directories(rpn_calculator PUBLIC include)

# Основная библиотека
add_library(rpn_lib src/rpn.cpp)
target_include_directories(rpn_lib PUBLIC include)

# Тестовый исполняемый файл (ТОЛЬКО ОДИН РАЗ!)
add_executable(test_rpn test/test_rpn.cpp)
target_link_libraries(test_rpn rpn_lib GTest::GTest GTest::Main)

# Добавление теста в CTest (ТОЛЬКО ОДИН РАЗ!)
add_test(NAME RPNTests COMMAND test_rpn)