//
// Created by vwu on 12/19/2024.
//

#include "DoorMotor.h"
#include "Constants.h"
#include <TMCStepper.h>

DoorMotor::DoorMotor() : driver(&Serial2, DOOR_MOTOR.rSense, DOOR_MOTOR.driverAddress) {
    pinMode(DOOR_MOTOR.enPin, OUTPUT);
    pinMode(DOOR_MOTOR.stepPin, OUTPUT);
    pinMode(DOOR_MOTOR.dirPin, OUTPUT);
    digitalWrite(DOOR_MOTOR.enPin, LOW);

    driver.begin();
    driver.toff(4);
    driver.blank_time(24);
    driver.rms_current(600);
    driver.microsteps(16);
    driver.pwm_autoscale(true);
}