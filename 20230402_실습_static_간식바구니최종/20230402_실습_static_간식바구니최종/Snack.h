#pragma once
#ifndef __SNACK_H__
#define __SNACK_H__
#include <iostream>


class Snack {
protected:
    static int population;
public:
    Snack() {
        population++;
    }
    static int get_population() {
        return population;
    }
    virtual std::string get_info() {
        return "";
    }

};


#endif