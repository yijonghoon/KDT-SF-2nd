#pragma once

#ifndef __PERSON_H__
#define __PERSON_H__
#include <iostream>


class Person {
    static int cnt;
    std::string name;
public:
    Person(std::string name);
    // static�̶�� ���� ������ ������ int getPopulation() �Լ��� ��ü�θ� ���� �����ϴ� ex) p.getPopulation() o , Person.getPopulation() x �׷��⶧���� �� �Ű����ҰŰ���
    static int getCnt();
    void plusCnt();

};

#endif