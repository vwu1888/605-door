//
// Created by vwu on 12/19/2024.
//
#pragma once
#include "HardwareSerial.h"

#ifndef CONSTANTS_H
#define CONSTANTS_H

struct TMC2209Config {
    int maxSpeed;
    int minSpeed;
    int stallValue; // [0..255]
    uint16_t rmsCurrent; // mA
    uint8_t enPin;
    uint8_t dirPin;
    uint8_t stepPin;
    Stream* serialPort;
    uint8_t driverAddress;
    float rSense;
};

const TMC2209Config DOOR_MOTOR = {
    .maxSpeed = 40,
    .minSpeed = 1000,
    .stallValue = 100,
    .enPin = 38,
    .dirPin = 55,
    .stepPin = 54,
    .serialPort = &Serial2,
    .driverAddress = 0b00,
    .rSense = 0.11f
};



#endif //CONSTANTS_H
