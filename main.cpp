#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <exception>

#include "earnings.h"
#include "levels.h"
#include "vehicle.h"

void earnings::get_money() {
    std::ifstream f;
    f.open("Earnings.txt", std::ios_base::in | std::ios_base::binary);
    if (!f) {
        throw std::runtime_error("Earnings.txt could not be opened");
    } else {
        f.read((char *) this, sizeof(*this));
    }
}

void add_money(earnings before, earnings &after) {
    after.A += before.A;
    after.B += before.B;
    after.C += before.C;
    after.D += before.D;
    after.total += before.total;
}

//deschidem fisierul in mod binar

void vehicle::add_vehicle() {
    std::ofstream g;
    g.open("add_data.txt", std::ios_base::app | std::ios_base::binary);
    getch();
    g.write((char *) this, sizeof(*this));
    g.close();

    earnings E;
    E.get_money();
    add_money(E, this->Earnings);
    g.open("add_data.txt", std::ios_base::app | std::ios_base::binary);
    g.write((char *) (&this->Earnings), sizeof(this->Earnings));
    g.close();
    std::cout << "Vehicle added \n";
}

//open the file and read the objects in it

void vehicle::add_in_list() {
    std::ifstream f;
    int n = 0;
    f.open("add_data.txt", std::ios_base::in | std::ios_base::binary);
    if (!f) {
        std::cout << "Missing file" << std::endl;
    } else {
        f.read((char *) this, sizeof(*this));
        while (!f.eof()) {
            this->show_vehicle();
            n++;
            f.read((char *) this, sizeof(*this));
        }
        f.close();
        if (n == 0) {
            std::cout << "Vehiculo not added" << std::endl;
        }
    }
}

//we search the vehicle identification number and then display it

void vehicle::search_vehicle(int nr) {
    std::ifstream f;
    int n = 0;
    f.open("add_data.txt", std::ios_base::in | std::ios_base::binary);
    if (!f) {
        std::cout << "Missing file!" << std::endl;
    } else {
        f.read((char *) this, sizeof(*this));
        while (!f.eof()) {
            if (this->vno == nr) {
                this->show_vehicle();
                n = 1;
                break;
            }
            f.read((char *) this, sizeof(*this));
        }
        f.close();
        if (n == 0) {
            std::cout << "Missing data!" << std::endl;
        }
    }
}

//search and update the file, if flg=0, we haven't found the vehicle, if flg=1 we found it and show "Object deleted"

void vehicle::delete_vehicle(int nr) {
    std::ifstream f;
    std::ofstream g;
    int flg = 0;
    f.open("add_data.txt", std::ios_base::in | std::ios_base::binary);
    if (!f) {
        std::cout << "Missing file" << std::endl;
    } else {
        f.read((char *) this, sizeof(*this));
        g.open("add_temp_data.txt", std::ios_base::in | std::ios_base::binary);
        while (!f.eof()) {
            if (this->vno == nr) {
                flg = 1;
            } else {
                g.write((char *) this, sizeof(*this));
            }
            f.read((char *) this, sizeof(*this));
        }
        f.close();
        g.close();
        if (flg == 0) {
            std::cout << "Missing data" << std::endl;
            remove("add_data.txt");
        } else {
            std::cout << "Object deleted" << std::endl;
            remove("add_data.txt");
            rename("add_temp_data.txt", "add_data.txt");
        }
    }
}

//updating vehicle data
void vehicle::update(int nr) {
    std::fstream foutin;
    int flg = 0;
    foutin.open("add_data.txt", std::ios_base::in | std::ios_base::binary);
    if (!foutin) {
        std::cout << "Missing file" << std::endl;
    } else {
        foutin.read((char *) this, sizeof(*this));
        while (!foutin.eof()) {
            if (this->vno == nr) {
                std::cout << "\n Update vehicle: ";
                std::cout << "\n Enter registration number: ";
                std::cin >> nr;
                std::cin.ignore();
                std::cout << "\n Enter vehicle description: ";
                //std::cin.get(description,50);
                time_t tt;
                time(&tt);
                foutin.write((char *) this, sizeof(*this));
                std::cout << "\n Record updated ";
                flg = 1;
                break;
            }
            foutin.read((char *) this, sizeof(*this));
        }
        foutin.close();
        if (flg == 0) {
            std::cout << "Missing data" << std::endl;
        }
    }
}



int menu() {
    int op;
    printf("1. Add vehicle\n");
    printf("2. List all vehicles\n");
    printf("3. Search vehicle\n");
    printf("4. Delete vehicle\n");
    printf("5. Update vehicle\n");
    printf("6. Check earnings\n");
    printf("7. Exit\n");
    printf("Enter your option: ");
    scanf("%d", &op);
    return op;
}

int main() {
    system("cls");
    vehicle v;
    earnings Earnings;
    levels<vehicle> Levels(4, vehicle());
    int brk_loop = 0, nr;
    while (1) {
        system("cls");
        switch (menu()) {
            case 1:
                v.read();
                v.add_vehicle();
                int level_choice;
                std::cin >> level_choice;
                Levels.add_to_level(level_choice, v);
                getch();
                break;
            case 2:
                std::cout << "Enter vehicle number: ";
                std::cin >> nr;
                v.search_vehicle(nr);
                getch();
                break;
            case 3:
                try {
                    int level_choice1;
                    std::cout << "Enter the level of the vehicle: ";
                    std::cin >> level_choice1;
                    std::cout << "Enter vehicle number to delete: ";
                    std::cin >> nr;
                    //Levels.remove_from_level(level_choice1, v);//possible problem
                    v.delete_vehicle(nr);
                }catch (const std::exception &e) {
                    std::cout << "Error" << e.what();
                }

                getch();
                break;
            case 4:
                std::cout << "Enter vehicle number to update: ";
                std::cin >> nr;
                v.update(nr);
                getch();
                break;
            case 5:
                v.add_in_list();
                getch();
                break;
            case 6:
                try {
                    Earnings.get_money();
                    Earnings.display();
                }catch (std::exception &e) {
                    std::cerr << "Error" << e.what() << std::endl;
                }
                getch();
                break;
            case 7:
                brk_loop = 1;
                break;
            default:
                std::cout << "Wrong option!" << std::endl;
                getch();
        }
        if (brk_loop == 1) {
            break;
        }
    }
    return 0;
}

/*
 *static cast
 *template funtion
 *2 design patterns
 *
*/
