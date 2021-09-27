#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <thread>
#include <iostream>
#include "doctest/doctest.h"
#include "altmutex.h"

TEST_CASE("altmutex should be lockable") {
    altmutex mut;
    std::lock_guard<altmutex> guard{ mut };
}

TEST_CASE("altmutex should should prevent data race") {
    altmutex mut;

    std::thread thd1{[&](){
        std::lock_guard<altmutex> guard{ mut };
        for(int i=0; i<10; i++) {
            std::cout << "hello from thread#1,"
            " cout protected by altmutex!" << std::endl;
        }
    }};

    std::thread thd2{[&](){
        std::lock_guard<altmutex> guard{ mut };
        for(int i=0; i<10; i++) {
            std::cout << "hello from thread#2,"
            " cout protected by altmutex!" << std::endl;
        }
    }};

    thd1.join();
    thd2.join();
}