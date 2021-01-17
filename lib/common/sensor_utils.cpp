#include <sensor_utils.h>

void noop(void) {
    lg.debug("NoOp");
}

uint16_t conv_float_uint16(float arg, uint16_t acc) {
    if (arg < 0) {
        lg.error("Not a positive number");
        return -1;
    }
    return static_cast<uint32_t>(std::round(arg * acc));
}

uint32_t conv_float_uint32(float arg, uint16_t acc) {
    if (arg < 0) {
        lg.error("Not a positive number");
        return -1;
    }
    return static_cast<uint32_t>(std::round(arg * acc));
}

uint16_t ana_read(void) {
    uint16_t adc;
    uint8_t i;

    for (i=0;i<ana_igno;i++) {
        analogRead(pin_ana);
        delay(time_ana_delay);
    }
    adc = 0;
    for (i=0;i<ana_samp;i++) {
        adc += analogRead(pin_ana);
        delay(time_ana_delay);
    }
    return conv_float_uint16(((float)adc)/ana_samp, 1);
}
