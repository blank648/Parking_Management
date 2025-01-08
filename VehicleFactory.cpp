//
// Created by user on 1/2/2025.
//

#include "VehicleFactory.h"

int function2() {
    int vehicleType;
    std::cout << "Select vehicle type: \n1. Bike\n2. Car\n3. Truck\n";
    std::cin >> vehicleType;

    //create a new vehicle using factory
    vehicle* newVehicle = VehicleFactory::createVehicle(vehicleType);

    newVehicle->read();

    //free the memory
    delete newVehicle;
    return 0;
}
