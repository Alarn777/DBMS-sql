cmake_minimum_required(VERSION 3.8)
project(DBMS-sql)

set(CMAKE_CXX_STANDARD 11)

set(BOOST_ROOT "/path_to_boost_1_67_0")

find_package(Boost 1.67.0)

LINK_DIRECTORIES(/usr/local/include)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()


set(SOURCE_FILES
        main.cpp
        menu.h
        Database.cpp
        Database.h
        Book.cpp
        Book.h
        Order.cpp Order.h Customer.cpp Customer.h Store.cpp Store.h)
add_executable(DBMS-sql ${SOURCE_FILES})


target_link_libraries(DBMS-sql mysqlcppconn)
target_link_libraries(DBMS-sql boost_date_time)

target_include_directories(DBMS-sql PUBLIC /usr/local/lib)

# Create imported target boost_date_time-mt-shared
#ADD_LIBRARY(boost_date_time-mt-shared SHARED IMPORTED)

# Import target "boost_date_time-mt-shared" for

#SET_PROPERTY(TARGET boost_date_time-mt-shared APPEND
#PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
