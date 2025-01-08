//
// Created by user on 12/2/2024.
//

#ifndef VEHICLE_TYPE_H
#define VEHICLE_TYPE_H
#include <iostream>
#include <fstream>
#include <iomanip>

#include "earnings.h"

class vehicle_type {
private:
    std::string vehicle_type_name;

public:
    vehicle_type() : vehicle_type_name("vehicle") {
    }

    //copy constructor
    vehicle_type(const vehicle_type &other) {
        this->vehicle_type_name = other.vehicle_type_name;
    }

    std::string get_vehicle_type_name() {
        return this->vehicle_type_name;
    }

    //select vehicle type
    void set_vehicle_type(earnings &Earnings) {
        while (1) {
            std::cout << "Select vehicle category: " << std::endl;
            std::cout << "1.A" << ' ' << "2.B" << ' ' << "3.C" << ' ' << "4.D" << std::endl;
            int vehicle_type;
            std::cin >> vehicle_type;
            if (vehicle_type == 1) {
                vehicle_type_name = "A";
                Earnings.input(20, 0, 0, 0, 20);
                break;
            } else if (vehicle_type == 2) {
                vehicle_type_name = "B";
                Earnings.input(0, 20, 0, 0, 20);
                break;
            } else if (vehicle_type == 3) {
                vehicle_type_name = "C";
                Earnings.input(0, 0, 60, 0, 60);
                break;
            } else if (vehicle_type == 4) {
                vehicle_type_name = "D";
                Earnings.input(0, 0, 0, 100, 100);
                break;
            } else {
                //invalid data
                std::cout << "Error" << std::endl;
            }
        }
    }

    virtual void display() {
        std::cout << vehicle_type_name << ' ' << std::endl;
    }

    virtual ~vehicle_type() = default;


};



#endif //VEHICLE_TYPE_H
