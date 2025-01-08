//
// Created by user on 1/2/2025.
//

#ifndef TRUCK_H
#define TRUCK_H
#include "vehicle.h"

// part of dynamic cast
class truck : public vehicle {
public:
    void display() const override {
        std::cout << "Truck details:\n";
        vehicle::display();
    }
};


#endif //TRUCK_H
