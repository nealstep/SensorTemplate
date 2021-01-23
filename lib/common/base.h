#ifndef BASE_H
#define BASE_H

// common includes to all
#include <Arduino.h>
#include <Logger.h>

#include <sensor_list.h>

// time constants
static const uint8_t time_ana_delay = 15;

// pin constants
static const uint8_t pin_ana = A0;
static const uint8_t pin_one_wire = 2;

// reading constants
static const uint8_t ana_igno = 2;
static const uint8_t ana_samp = 5;

// board constants
static const float vin = 3.3;

#endif // BASE_H
