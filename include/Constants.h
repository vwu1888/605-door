//
// Created by vwu on 12/19/2024.
//
#pragma once
#include "HardwareSerial.h"

#ifndef CONSTANTS_H
#define CONSTANTS_H

constexpr float DEG_PER_STEP = 1.8;

struct TMC2209Config {
    float maxSpeed = 1000;
    float maxAccel = 100;
    int stallValue = 100; // [0..255]
    uint8_t toff = 4;
    uint8_t blankTime = 24;
    uint16_t microSteps = 16;
    uint16_t rmsCurrent = 500; // mA
    bool pwmAutoScale = true;
    uint8_t enPin{};
    uint8_t dirPin{};
    uint8_t stepPin{};
    bool enInvert = false;
    bool dirInvert = false;
    bool stepInvert = false;
    Stream* serialPort{};
    uint8_t driverAddress{};
    float rSense = 0.11f;
};

const TMC2209Config DOOR_MOTOR = {
    .maxSpeed = 1000,
    .maxAccel = 200,
    .stallValue = 100,
    .enPin = 38,
    .dirPin = 55,
    .stepPin = 54,
    .serialPort = &Serial2,
    .driverAddress = 0b00,
    .rSense = 0.11f
};

#endif //CONSTANTS_H
