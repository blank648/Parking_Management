//
// Created by user on 12/2/2024.
//

#ifndef LEVELS_H
#define LEVELS_H
#include <iostream>
#include <vector>
#include <algorithm>

#include "vehicle.h"



//managing vehicles though organised levels
//we modify this class in order to make it a template class
template <typename T>
class levels : public vehicle {
private:
    std::vector<std::vector<T>> level;
    T dependant_atribute;
public:
    levels(int nr_Levels, T initial_weight)
        : level(nr_Levels), dependant_atribute(initial_weight) {};

    void update_atribute(const T& new_attribute) {
        dependant_atribute = new_attribute;
        std::cout<<"update atribute "<<dependant_atribute<<std::endl;
    }

    //adding vehicle to a certain level
    void add_to_level(int level_number, const T& item) {
        if (level_number >= 0 && level_number <= level.size()) {
            level[level_number].push_back(item);
        } else {
            throw std::out_of_range("level number out of range");
        }
    }

    //comparing 2 vehicles
    bool compare_vehicle(const T& a, const T& b) {
        return a.get_vehicle_number() == b.get_vehicle_number();
    }

    //removing the vehicles
    void remove_from_level(int level_number, const T& item) {
        if (level_number >= 0 && level_number < level.size()) {
            auto& items = level[level_number];

            // Folosim std::find_if pentru a găsi vehiculul
            auto it = std::find_if(items.begin(), items.end(), [&item](const T& v) {
                return item.compare_vehicle(v);  // Compară vehiculele folosind funcția compare_vehicle
            });

            if (it != items.end()) {
                items.erase(it);
            } else {
                throw std::runtime_error("Item not found in the specified level!");
            }
        } else {
            throw std::out_of_range("Invalid level number!");
        }
    }

    //showing all levels
    void show_all_levels() const {
        for (size_t i = 0; i < level.size(); ++i) {
            std::cout << "Level " << i + 1 << ":\n";
            for (const auto& item : level[i]) {
                std::cout << item << "\n";
            }
        }
    }

    //we allow friend functions to access levels
    template <typename U>
    friend void display_level_info(const levels<U>& lvl);

};

//template function defined
template <typename U>
void display_level_info(const levels<U>& lvl) {
    std::cout << "Displaying information for all levels:\n";
    for (size_t i = 0; i < lvl.level.size(); ++i) {
        std::cout << "Level " << i + 1 << " contains " << lvl.level[i].size() << " items.\n";
    }
    std::cout << "Dependent attribute value: " << lvl.dependant_atribute << "\n";
}


#endif //LEVELS_H
