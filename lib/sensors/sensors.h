#ifndef SENSORS_H
#define SENSORS_H

#include <base.h>

// main call
void sensor_init(void);
void sensor_check(void);

// utility functions
void noop(void);
uint16_t conv_float_uint16(float arg, uint16_t acc=100);
uint32_t conv_float_uint32(float arg, uint16_t acc=100);
uint16_t ana_read(void);

// include begin flag
#ifdef S_DUMMY
#include <s_dummy.h>
#endif // S_DUMMY

#ifdef S_BME280
#include <s_bme280.h>
#endif // S_BME280

#ifdef S_AHT20
#include <s_aht20.h>
#endif // S_AHT20

#ifdef S_DS18B20
#include <s_ds18b20.h>
#endif // S_DS18B20

#ifdef S_MHZ16
#include <s_mhz16.h>
#endif // S_MHZ16

#ifdef S_SCD30S
#include <s_scd30s.h>
#endif // S_SCD30S

#ifdef S_SHT31S
#include <s_sht31s.h>
#endif // S_SHT31S

#ifdef S_SI1145
#include <s_si1145.h>
#endif // S_SI1145

#ifdef S_TEMP_NTC
#include <s_temp_ntc.h>
#endif // S_TEMP_NTC

#ifdef S_MLX90641
#include <s_mlx90641.h>
#endif // S_MLX90641

#ifdef S_ULTRASONIC
#include <s_ultrasonic.h>
#endif // S_ULTRASONIC

#ifdef S_DHT
#include <s_dht.h>
#endif // S_DHT

#ifdef S_MLX90615
#include <s_mlx90615.h>
#endif // S_MLX90615
// include end flag

#endif // SENSORS_H
