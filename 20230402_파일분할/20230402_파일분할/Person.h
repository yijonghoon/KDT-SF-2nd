#pragma once

#ifndef __PERSON_H__
#define __PERSON_H__
#include <iostream>


class Person {
    static int cnt;
    std::string name;
public:
    Person(std::string name);
    // static이라는 말을 붙이지 않으면 int getPopulation() 함수는 객체로만 접근 가능하다 ex) p.getPopulation() o , Person.getPopulation() x 그렇기때문에 잘 신경써야할거같다
    static int getCnt();
    void plusCnt();

};

#endif