//
// Created by user on 1/2/2025.
//

#ifndef CAR_H
#define CAR_H
// parte din dynamic cast

#include <iostream>
#include "vehicle.h"

class car : public vehicle {
public:
    void display() override {
        std::cout << "Car details:\n";
        vehicle::display();
    }
};



#endif //CAR_H
