//
// Created by user on 1/2/2025.
//

#ifndef BIKE_H
#define BIKE_H
#include "vehicle.h"
// parte din dynamic cast

class bike : public vehicle {
public:
    void display() const override {
        std::cout << "Bike details:\n";
        vehicle::display();
    }
};



#endif //BIKE_H
