//
// Created by vwu on 12/19/2024.
//

#include "DoorMotor.h"
#include "Constants.h"

DoorMotor::DoorMotor(const TMC2209Config* config) :
driver(config->serialPort, config->rSense, config->driverAddress),
motionControl(AccelStepper::MotorInterfaceType::DRIVER, config->stepPin, config->dirPin)
{
    DoorMotor::config = config;
    pinMode(config->enPin, OUTPUT);
    pinMode(config->stepPin, OUTPUT);
    pinMode(config->dirPin, OUTPUT);

    motorDisable();

    driver.begin();
    driver.toff(config->toff);
    driver.blank_time(config->blankTime);
    driver.rms_current(config->rmsCurrent);
    driver.microsteps(config->microSteps);
    driver.pwm_autoscale(config->pwmAutoScale);
    driver.SGTHRS(config->stallValue);

    motionControl.setSpeed(config->maxSpeed);
    motionControl.setAcceleration(config->maxAccel);
    motionControl.setEnablePin(config->enPin);
    motionControl.setPinsInverted(config->dirPin, config->stepPin, config->enPin);

    motorDisable();
}

void DoorMotor::motorEnable() {
    motionControl.enableOutputs();
}

void DoorMotor::motorDisable() {
    motionControl.disableOutputs();
}
