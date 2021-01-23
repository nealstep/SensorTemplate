#include "s_dht.h"
#ifdef S_DHT
#include <sensors.h>

#include "DHT.h"

#define DHTTYPE DHT22

static const uint8_t pin_dht = 12;

DHT dht(pin_dht, DHTTYPE);

void s_dht_init(void) {
    lg.debug("s_dht init");

    dht.begin();
}

void s_dht_check(void) {
    lg.debug("s_dht check");
    
    float temp_hum_val[2] = {0};

    if (!dht.readTempAndHumidity(temp_hum_val)) {
        lg.report("dht.temp", conv_float_uint32(temp_hum_val[1]));
        lg.report("dht.humi", conv_float_uint32(temp_hum_val[0]));
    } else {
        lg.error("DHT: Read failed");
    }
}

#endif // S_DHT
