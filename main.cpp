#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <vector>
#include <exception>

class earnings {
private:
    //facem categori de incasari bazate pe categoria vehiculului
    int A; //bike
    int B; //car
    int C; //small truck / small bus
    int D; //large truck / bus
    int total;

public:
    //facem constructor pentru initializarea variabilelor A,B,C,D
    earnings() {
        this->A = 0;
        this->B = 0;
        this->C = 0;
        this->D = 0;
        this->total = 0;
    }

    //copy constructor
    earnings(const earnings &other) {
        this->A = other.A;
        this->B = other.B;
        this->C = other.C;
        this->D = other.D;
        this->total = other.total;
    }

    //entering the data
    void input(int A, int B, int C, int D, int total) {
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        this->total = total;
    }

    //afisam variabilele si folosimm setw() pt a seta latimea campurilor
    virtual void display() {
        std::cout << "\n--------------------------------------------------------------------------------------------\n";
        std::cout << std::setw(10) << "Category A:" << std::setw(10) << "Category B:" << std::setw(10) << "Category C:"
                << std::setw(10) << "Catagory D:";
        std::cout << "\n--------------------------------------------------------------------------------------------\n";
        std::cout << std::setw(9) << this->A << ' ' << std::setw(9) << this->B << ' ' << std::setw(9) << this->C << ' '
                << std::setw(9) << this->D << std::endl;
    }

    virtual ~earnings() {
    }

    void get_money();

    friend void add_money(earnings, earnings &);
};

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

class vehicle_type {
private:
    std::string vehicle_type_name;

public:
    vehicle_type() : vehicle_type_name("vehicle") {
    }

    //copy constructor
    vehicle_type(const vehicle_type &other) {
        this->vehicle_type_name = other.vehicle_type_name;
    }

    //select vehicle type
    void set_vehicle_type(earnings &Earnings) {
        while (1) {
            std::cout << "Select vehicle category: " << std::endl;
            std::cout << "1.A" << ' ' << "2.B" << ' ' << "3.C" << ' ' << "4.D" << std::endl;
            int vehicle_type;
            std::cin >> vehicle_type;
            if (vehicle_type == 1) {
                vehicle_type_name = "A";
                Earnings.input(20, 0, 0, 0, 20);
                break;
            } else if (vehicle_type == 2) {
                vehicle_type_name = "B";
                Earnings.input(0, 20, 0, 0, 20);
                break;
            } else if (vehicle_type == 3) {
                vehicle_type_name = "C";
                Earnings.input(0, 0, 60, 0, 60);
                break;
            } else if (vehicle_type == 4) {
                vehicle_type_name = "D";
                Earnings.input(0, 0, 0, 100, 100);
                break;
            } else {
                //invalid data
                std::cout << "Error" << std::endl;
            }
        }
    }

    virtual void display() {
        std::cout << vehicle_type_name << ' ' << std::endl;
    }

    virtual ~vehicle_type() {
    }
};

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
    void read() {
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
    void display() const {
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

    void add_vehicle();

    void add_in_list();

    void search_vehicle(int nr); //nr-veh. no
    void delete_vehicle(int nr);

    void update(int nr); //updating vehicle
};

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
    levels Levels;
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
                    Levels.remove_from_level(level_choice1, nr);
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
 *de schimbat:  char* to string
 *
*/
