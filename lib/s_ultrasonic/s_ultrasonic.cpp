#include "s_ultrasonic.h"
#ifdef S_ULTRASONIC
#include <sensors.h>

#include <Ultrasonic.h>

static const uint8_t pin_ultrasonic = 13;

Ultrasonic ultrasonic(pin_ultrasonic);

void s_ultrasonic_init(void) {
    lg.debug("s_ultrasonic init");

    noop();
}

void s_ultrasonic_check(void) {
    lg.debug("s_ultrasonic check");

    uint32_t cm;

    cm = ultrasonic.MeasureInCentimeters();
    lg.report("ultra.dist", cm);
}

#endif // S_ULTRASONIC
