//
// Created by vwu on 12/19/2024.
//

#include "DoorMotor.h"
#include "Constants.h"

DoorMotor::DoorMotor(const TMC2209Config &config) :
driver(config.serialPort, config.rSense, config.driverAddress),
motionControl(AccelStepper::MotorInterfaceType::DRIVER, config.stepPin, config.dirPin)
{
    DoorMotor::config = &config;
    pinMode(config.enPin, OUTPUT);
    pinMode(config.stepPin, OUTPUT);
    pinMode(config.dirPin, OUTPUT);

    motorDisable();

    driver.begin();
    driver.toff(4);
    driver.blank_time(24);
    driver.rms_current(config.rmsCurrent);
    driver.microsteps(16);
    driver.pwm_autoscale(true);
}

void DoorMotor::motorEnable() {
    digitalWrite(config->enPin, LOW);
}

void DoorMotor::motorDisable() {
    digitalWrite(config->enPin, HIGH);
}
