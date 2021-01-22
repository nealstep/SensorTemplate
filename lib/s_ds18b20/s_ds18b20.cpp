#include "s_ds18b20.h"
#ifdef S_DS18B20
#include <sensors.h>

#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(pin_one_wire);
DallasTemperature ds18b20(&oneWire);

void s_ds18b20_init(void) {
    lg.debug("s_ds18b20 init");
  
    ds18b20.begin();
}

void s_ds18b20_check(void) {
    lg.debug("s_ds18b20 check");

  	float tempc;

	ds18b20.requestTemperatures();
	tempc = ds18b20.getTempCByIndex(0);
	if(tempc != DEVICE_DISCONNECTED_C) {
		lg.report("ds18b20.temp", conv_float_uint32(tempc));
    } else {
        lg.error("DS18B20: Read failed");
    }
}

#endif // S_DS18B20
