//
// Created by user on 1/2/2025.
//

#include "VehicleFactory.h"

int main() {
    int vehicleType;
    std::cout << "Select vehicle type: \n1. Bike\n2. Car\n3. Truck\n";
    std::cin >> vehicleType;

    // Creează vehiculul utilizând Factory
    vehicle* newVehicle = VehicleFactory::createVehicle(vehicleType);

    // Apelează metoda `read` a vehiculului creat (dinamic binding)
    newVehicle->read();

    // Eliberează memoria
    delete newVehicle;
    return 0;
}
