#include "s_si1145.h"
#ifdef S_SI1145
#include <sensors.h>

#include <SI114X.h>

static const uint8_t tries_si1145_max = 3;
SI114X si1145 = SI114X();
bool si1145_inited;

void s_si1145_init(void) {
    lg.debug("s_si1145 init");

    uint8_t attempts;

    si1145_inited = false;
    attempts = 0;
	lg.warn("SI1145 Untested");
    while (!si1145.Begin()) {
        lg.warn("SI1145 is not ready!");
        delay(100);
        if (++attempts > tries_si1145_max) {
            return;
        }
    }
    lg.info("SI1145 Ready");
    si1145_inited = true;
}

void s_si1145_check(void) {
    lg.debug("s_si1145 check");

    if (!si1145_inited) {
        lg.error("SI1145: Not inited");
        return;
    }
    uint16_t vis, ir, uv;

    vis = si1145.ReadVisible();
    ir = si1145.ReadIR();
    uv = si1145.ReadUV();
    lg.report("si1145.visible", vis);
    lg.report("si1145.infra", ir);
    lg.report("si1145.uv", uv);
}

#endif // S_SI1145
