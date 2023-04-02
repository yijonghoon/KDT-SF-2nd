#pragma once
#ifndef __CHOCO_H__
#define __CHOCO_H__

#include "Snack.h"

class Choco : public Snack {
    static int population;
    std::string shape;
public:
    Choco(std::string shape) {
        this->shape = shape;
    }
    static int get_population() {
        return population;
    }
    std::string get_info() {
        return shape + "모양 초콜릿";
    }
};


#endif