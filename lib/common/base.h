#ifndef BASE_H
#define BASE_H

// common includes to all
#include <Arduino.h>
#include <Logger.h>

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

// sensor to test
// define begin flag
// #define S_AHT20
// #define S_BME280
// #define S_DS18B20
// #define S_DUMMY
// #define S_MHZ16
#define S_MLX90641
// #define S_SCD30S
// #define S_SHT31S
// #define S_SI1145
// #define S_TEMP_NTC
// #define S_ULTRASONIC
// define end flag

#endif // BASE_H
