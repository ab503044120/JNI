//
// Created by huihui on 2019/1/26.
//
#include <string>
//#include <iostream>

#ifndef CPPTEST_PARENT_H
#define CPPTEST_PARENT_H

using namespace std;


class Animal {
public:
    string name;

    Animal(string n);

    virtual void call() = 0;
};


#endif //CPPTEST_PARENT_H
