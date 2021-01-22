#include "s_sht31s.h"
#ifdef S_SHT31S
#include <sensors.h>

#include <SHT31.h>

SHT31 sht31 = SHT31();

void s_sht31s_init(void) {
    lg.debug("s_sht31s init");

    sht31.begin();
}

void s_sht31s_check(void) {
    lg.debug("s_sht31s check");

    float tempc, humid;

    tempc = sht31.getTemperature();
    humid = sht31.getHumidity();
	lg.report("sht31.temp", conv_float_uint32(tempc));
    lg.report("sht31.humi", conv_float_uint32(humid));
}

#endif // S_SHT31S
