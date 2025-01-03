//
// Created by user on 1/2/2025.
//

#include "Command.h"

int main() {
    vehicle v;
    Command* cmd = new AddVehicleCommand(&v);
    cmd->execute(); // adaug vehiculul

}