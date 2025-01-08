//
// Created by user on 1/8/2025.
//

#include "Observer.h"

//we implemented an observer pattern
int function() {
    EarningsSubject earningsSubject;
    Logger logger;

    earningsSubject.addObserver(&logger);
    earningsSubject.updateEarnings(100);

    return 0;
}