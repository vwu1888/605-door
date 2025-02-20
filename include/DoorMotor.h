//
// Created by vwu on 12/19/2024.
//
#pragma once
#include <AccelStepper.h>

#include "Constants.h"
#include <TMCStepper.h>

#ifndef DOORMOTOR_H
#define DOORMOTOR_H

class DoorMotor {
    private:
        TMC2209Stepper driver;
        AccelStepper motionControl;
    protected:
        const TMC2209Config* config;
    public:
        explicit DoorMotor(const TMC2209Config* config);

        void motorEnable();
        void motorDisable();
};

#endif //DOORMOTOR_H
