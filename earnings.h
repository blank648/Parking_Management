//
// Created by user on 12/2/2024.
//

#ifndef EARNINGS_H
#define EARNINGS_H

#include <iostream>
#include <fstream>
#include <iomanip>

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

    [[nodiscard]] int a() const {
        return A;
    }

    [[nodiscard]] int b() const {
        return B;
    }

    [[nodiscard]] int c() const {
        return C;
    }

    [[nodiscard]] int d() const {
        return D;
    }

    [[nodiscard]] int total1() const {
        return total;
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

    virtual ~earnings() = default;


    void get_money();

    friend void add_money(const earnings& before, earnings& after);
};



#endif //EARNINGS_H
