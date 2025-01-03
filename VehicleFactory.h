//
// Created by user on 1/2/2025.
//

#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H
#include "vehicle.h"
#include "bike.h"
#include "car.h"
#include "truck.h"


class VehicleFactory {
public:
    static vehicle* createVehicle(int type) {
        if (type == 1) {
            return new bike();
        } else if (type == 2) {
            return new car();
        } else if (type == 3) {
            return new truck();
        } else {
            return new vehicle(); // Tip generic
        }
    }
};



#endif //VEHICLEFACTORY_H
