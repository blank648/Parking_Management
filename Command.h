//
// Created by user on 1/2/2025.
//

#ifndef COMMAND_H
#define COMMAND_H
#include "vehicle.h"

//we implemented a command pattern
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class AddVehicleCommand : public Command {
private:
    vehicle* v;

public:
    AddVehicleCommand(vehicle* v) : v(v) {}

    void execute() override {
        v->add_vehicle();
    }
};




#endif //COMMAND_H
