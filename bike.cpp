//
// Created by user on 1/2/2025.
//

#include "bike.h"
#include <iostream>
#include "car.h"
#include "truck.h"
#include "levels.h"
/*
void levels::show_all_vehicles() {
    for (int i = 0; i < 4; i++) {
        std::cout << "\nLevel " << i + 1 << " vehicles:\n";
        for (const auto& v : level[i]) {
            const vehicle* v_ptr = &v; // pointer la baza clasei

            if (const car* c = dynamic_cast<const car*>(v_ptr)) {
                std::cout << "Car found:\n";
                c->display();
            } else if (const truck* t = dynamic_cast<const truck*>(v_ptr)) {
                std::cout << "Truck found:\n";
                t->display();
            } else if (const bike* b = dynamic_cast<const bike*>(v_ptr)) {
                std::cout << "Bike found:\n";
                b->display();
            } else {
                std::cout << "Unknown vehicle type:\n";
                v_ptr->display();
            }
        }
    }
}

int main() {
    levels l;
    car c;
    truck t;
    bike b;

    l.add_to_level(1, c);
    l.add_to_level(2, t);
    l.add_to_level(3, b);
}
*/