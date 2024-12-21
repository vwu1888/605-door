//
// Created by vwu on 12/19/2024.
//
#include "HardwareSerial.h"

#ifndef CONSTANTS_H
#define CONSTANTS_H

struct TMC2209Config {
    int maxSpeed;
    int minSpeed;
    int stallValue; // [0..255]
    int enPin;
    int dirPin;
    int stepPin;
    int swRx;
    int swTx;
    HardwareSerial serialPort;
    int driverAddress;
    float rSense;
};

const TMC2209Config DOOR_MOTOR = {
    .maxSpeed = 40,
    .minSpeed = 1000,
    .stallValue = 100,
    .enPin = 38,
    .dirPin = 55,
    .stepPin = 54,
    .swRx = 63,
    .swTx = 40,
    .serialPort = Serial2,
    .driverAddress = 0b00,
    .rSense = 0.11f
};

#endif //CONSTANTS_H
