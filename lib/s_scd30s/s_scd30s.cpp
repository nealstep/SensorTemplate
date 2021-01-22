#include "s_scd30s.h"
#ifdef S_SCD30S
#include <sensors.h>

#include <SCD30.h>

void s_scd30s_init(void) {
    lg.debug("s_scd30s init");

  	scd30.initialize();
}

void s_scd30s_check(void) {
    lg.debug("s_scd30s check");

    float result[3] = {0};

	if(scd30.isAvailable()) {
		scd30.getCarbonDioxideConcentration(result);
		lg.report("scd30s.co2", conv_float_uint32(result[0]));
		lg.report("scd30s.temp", conv_float_uint32(result[1]));
		lg.report("scd30s.humid", conv_float_uint32(result[2]));
	} else {
		lg.error("SCD30s: Read failed");
	}
}

#endif // S_SCD30S
