#ifndef SENSOR_UTILS_H
#define SENSOR_UTILS_H

#include <Arduino.h>
#include <Logger.h>

static const uint8_t ana_igno = 2;
static const uint8_t ana_samp = 5;
static const uint8_t time_ana_delay = 15;
static const uint8_t pin_ana = A0;

void noop(void);
uint16_t conv_float_uint16(float arg, uint16_t acc=100);
uint32_t conv_float_uint32(float arg, uint16_t acc=100);
uint16_t ana_read(void);

#endif // SENSOR_UTILS_H
