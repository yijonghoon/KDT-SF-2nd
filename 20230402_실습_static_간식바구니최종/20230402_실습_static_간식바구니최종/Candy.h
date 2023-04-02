#pragma once
#ifndef __CANDY_H__
#define __CANDY_H__

#include "Snack.h"


class Candy : public Snack {
    static int population;
    std::string flavor;
public:
    Candy(std::string flavor) {
        population++;
        this->flavor = flavor;
    }
    static int get_population() {
        return population;
    }
    std::string get_info() {
        return flavor + "∏¿ ªÁ≈¡";
    }
};



#endif