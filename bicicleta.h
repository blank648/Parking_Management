//
// Created by user on 12/2/2024.
//

#ifndef BICICLETA_H
#define BICICLETA_H

#include <iostream>
#include <fstream>

#include "vehicle_type.h"

//created for upcasting
class bicicleta : public vehicle_type {
private:
    std::string name = "Bycicle";

public:
    bicicleta() = default;

    void display() override {
        std::cout << "This is a " << get_vehicle_type_name() << std::endl;
    }

    ~bicicleta() override = default;
};


#endif //BICICLETA_H
