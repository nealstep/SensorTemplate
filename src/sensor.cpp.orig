#include <sensor.h>

void sensor_init(void) {
    noop();
}

void sensor_check(void) {
    float test1 = 5.6;
    uint16_t test2 = 131;

    lg.report("sensor.test1", conv_float_uint32(test1));
    lg.report("sensor.test2", test2);
}
