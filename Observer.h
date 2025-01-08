//
// Created by user on 1/8/2025.
//

#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include <iostream>


//we implemented an Observer pattern
class Observer {
public:
    virtual void update(int newEarnings) = 0;
    virtual ~Observer() = default;
};

class EarningsSubject {
private:
    std::vector<Observer*> observers;
    int totalEarnings=0;

public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void notifyObservers() {
        for (auto& obs : observers) {
            obs->update(totalEarnings);
        }
    }

    void updateEarnings(int amount) {
        totalEarnings += amount;
        notifyObservers();
    }
};

class Logger : public Observer {
public:
    void update(int newEarnings) override {
        std::cout << "New earnings logged: " << newEarnings << "\n";
    }
};


#endif //OBSERVER_H
