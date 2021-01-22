#include "s_aht20.h"
#ifdef S_AHT20
#include <sensors.h>

#include <AHT20.h>

AHT20 aht;

void s_aht20_init(void) {
    lg.debug("s_aht20 init");

    aht.begin();
}

void s_aht20_check(void) {
    lg.debug("s_aht20 check");

    float humid, tempc;
    int ret;

    ret = aht.getSensor(&humid, &tempc);
    if (ret) {
        lg.report("aht20.temp", conv_float_uint32(tempc));
        lg.report("aht20.humi", conv_float_uint32(humid));
    } else {
        lg.error("AHT20: Read failed");
    }
}

#endif // S_AHT20
