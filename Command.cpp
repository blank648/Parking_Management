//
// Created by user on 1/2/2025.
//

#include "Command.h"

//we implement adding a new vwhicle through a Command pattern
int function3() {
    vehicle v;
    Command* cmd = new AddVehicleCommand(&v);
    cmd->execute(); // adaug vehiculul

    return 0;
}