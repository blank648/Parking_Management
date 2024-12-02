//
// Created by user on 12/2/2024.
//

#ifndef LEVELS_H
#define LEVELS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "vehicle.h"

//managing vehicles though organised levels
class levels : public vehicle {
private:
    std::vector<vehicle> level[6];

public:
    levels() {
    }

    //adding vehicle to a certain level
    void add_to_level(int lvl, const vehicle &v) {
        if (lvl == 1 && lvl <= 4) {
            level[lvl - 1].push_back(v);
            std::cout << "The vehicle has been added to level " << lvl << "\n";
        } else {
            std::cout << "Invalid choice \n";
        }
    }

    //removing the vehicles
    void remove_from_level(int lvl, int vno) {
        if(lvl<1 || lvl>4) {
            throw std::invalid_argument("Invalid choice for the vehicle level");
        }
        if (lvl == 1 && lvl <= 4) {
            auto &vehicles = level[lvl - 1];
            bool found = false;
            for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
                if (it->get_vehicle_number() == vno) {
                    vehicles.erase(it);
                    found = true;
                    std::cout << "The vehicle has been removed from level " << lvl << "\n";
                    break;
                }
            }
            if (!found) {
                std::cout << "The vehicle has not been found";
            }
        } else {
            throw std::runtime_error("Invalid choice for the vehicle level");
        }
    }

    void show_all_vehicles() {
        for (int i = 0; i <= 4; i++) {
            std::cout << "\n Level " << i++ << " vehicles: \n";
            for (const auto &v: level[i]) {
                v.display();
            }
        }
    }

};



#endif //LEVELS_H
