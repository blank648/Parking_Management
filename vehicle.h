//
// Created by user on 12/2/2024.
//

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <exception>

#include "earnings.h"
#include "vehicle_type.h"

class vehicle : public vehicle_type {
private:
    int vno; //vehicle database number
    std::string registration_num;
    std::string color;
    std::string manufacturer;
    std::string model;
    std::string entrance_hour;
    std::string exit_hour;
    earnings Earnings;

public:
    //constructor implicit
    vehicle() {
        this->vno = 0;
        registration_num = "default";
        color = "default";
        manufacturer = "default";
        model = "default";
        time_t tt;
        time(&tt);
        entrance_hour = asctime(localtime(&tt));
        exit_hour = asctime(localtime(&tt));
    }

    //constructor de copiere
    vehicle(const vehicle &other) {
        this->vno = other.vno;
        this->registration_num = other.registration_num;
        this->color = other.color;
        this->manufacturer = other.manufacturer;
        this->model = other.model;
        this->entrance_hour = other.entrance_hour;
        this->exit_hour = other.exit_hour;
        this->Earnings = other.Earnings;
    }

    //enter vehicle data
    virtual void read() {
        std::cout << "Enter vehicle number: " << std::endl;
        std::cin >> vno;
        std::cout << "Enter vehicle registration number: " << std::endl;
        std::cin >> registration_num;
        std::cout << "Enter vehicle color: " << std::endl;
        std::cin >> color;
        std::cout << "Enter manufacturer: " << std::endl;
        std::cin >> manufacturer;
        std::cout << "Enter model: " << std::endl;
        std::cin >> model;
        set_vehicle_type(Earnings);
        time_t tt;
        time(&tt);
        entrance_hour = asctime(localtime(&tt));
        exit_hour = asctime(localtime(&tt));
    }

    //display function
    virtual void display() const {
        std::cout << "Vehicle number: " << vno << std::endl;
        std::cout << "Registration number: " << registration_num << std::endl;
        std::cout << entrance_hour << " - " << exit_hour << std::endl;
    }

    void show_vehicle() {
        std::cout << vno << ' ' << manufacturer << ' ' << color << std::endl;
        Earnings.display();
    }

    int get_vehicle_number() {
        return vno;
    }

    virtual ~vehicle() {}

    void add_vehicle();

    void add_in_list();

    void search_vehicle(int nr); //nr-veh. no
    void delete_vehicle(int nr);

    void update(int nr); //updating vehicle
};



#endif //VEHICLE_H
