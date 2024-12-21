//
// Created by vwu on 12/19/2024.
//
#include "Constants.h"
#include <TMCStepper.h>

#ifndef DOORMOTOR_H
#define DOORMOTOR_H



class DoorMotor {
    private:
        TMC2209Stepper driver;
    public:
        DoorMotor();
};



#endif //DOORMOTOR_H
