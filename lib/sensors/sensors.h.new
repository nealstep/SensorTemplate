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
// include end flag
