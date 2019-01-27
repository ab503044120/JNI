//
// Created by huihui on 2019/1/27.
//

#ifndef CPPTEST_DOG_H
#define CPPTEST_DOG_H


#include "Animal.h"

class Dog : public Animal {
public:
    Dog(string n);

    void call() override;

};


#endif //CPPTEST_DOG_H
