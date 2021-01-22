#include "s_temp_ntc.h"
#ifdef S_TEMP_NTC
#include <sensors.h>

static const uint16_t b = 4275;
static const uint32_t r = 100000;
static const uint32_t r0 = 100000;
static const float t0 = 273.15 + 25;

void s_temp_ntc_init(void) {
    lg.debug("s_temp_ntc init");

    noop();
}

void s_temp_ntc_check(void) {
    lg.debug("s_temp_ntc check");
    
    uint16_t adc;
    float v, i, rt, t;
    double t1, t2, t3;

    adc = ana_read();
    lg.report("temp.adc", adc);
    v = (adc * vin) / 1024.0;
    i = (vin / v) - 1.0;
    rt = r * i;
    t1 = log2(rt / r0);
    t2 = t1 / b;
    t3 = t2 + (1.0 / t0);
    t = 1.0 / t3;
    t -= 273.15;
    lg.report("temp.tempc", conv_float_uint32(t));  
}

#endif // S_TEMP_NTC
