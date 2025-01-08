//
// Created by user on 12/2/2024.
//


#include "levels.h"

//we create a frient template function
/* failed dynamic cast attempt
#include "car.h"
#include "truck.h"
#include "bike.h"
#include <type_traits>

// external function that uses dynamic_cast in order to identify vehicle type
template <typename T>
typename std::enable_if<std::is_base_of<vehicle, T>::value>::type
display_vehicle_info(const T& vehicle) {
    const vehicle* v_ptr = &vehicle;  // Pointer la clasa de bază

    // Folosim dynamic_cast pentru a verifica tipul vehiculului
    if (const car* c = dynamic_cast<const car*>(v_ptr)) {
        std::cout << "This is a car.\n";
        c->display();
    } else if (const truck* t = dynamic_cast<const truck*>(v_ptr)) {
        std::cout << "This is a truck.\n";
        t->display();
    } else if (const bike* b = dynamic_cast<const bike*>(v_ptr)) {
        std::cout << "This is a bike.\n";
        b->display();
    } else {
        std::cout << "Unknown vehicle type.\n";
        v_ptr->display();
    }
}*/

int func() {
    try {

        // 3 levels, initial value = 0
        levels<int> intLevels(3, 0);

        // adding to levels
        intLevels.add_to_level(0, 10);
        intLevels.add_to_level(1, 20);
        intLevels.add_to_level(2, 30);

        // showing all levels
        intLevels.show_all_levels();

        // updating content
        intLevels.update_atribute(42);

        display_level_info(intLevels);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;

}
