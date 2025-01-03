//
// Created by user on 12/2/2024.
//


#include "levels.h"

//we create a frient template function
template <typename U>
void display_level_info(const levels<U>& lvl) {
    std::cout << "Displaying information for all levels:\n";
    for (size_t i = 0; i < lvl.level.size(); ++i) {
        std::cout << "Level " << i + 1 << " contains " << lvl.level[i].size() << " items.\n";
    }
    std::cout << "Dependent attribute value: " << lvl.dependant_atribute << "\n";
}

int main() {
    try {
        // Instanțiem levels pentru vehicule (sau alt tip)
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