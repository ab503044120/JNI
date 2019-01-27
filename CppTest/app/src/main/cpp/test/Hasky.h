//
// Created by huihui on 2019/1/27.
//
#include "Dog.h"
#include "Pet.h"

#ifndef CPPTEST_HASKY_H
#define CPPTEST_HASKY_H


class Hasky : public Dog, public Pet {
public:
    Hasky(const string &n);

    void call() override;


};


#endif //CPPTEST_HASKY_H
