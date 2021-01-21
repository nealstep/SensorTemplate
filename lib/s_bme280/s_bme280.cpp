#include <s_bme280.h>
#ifdef S_BME280
#include <sensors.h>

#include <Seeed_BME280.h>

BME280 bme280;
bool status;

void s_bme280_init(void) {
    lg.debug("s_bme280 init");
    
    status = bme280.init();
    if (!status){
        lg.error("BME280: Init failed");
    }
}

void s_bme280_check(void) {
    lg.debug("s_bme280 check");

    uint32 tempc, press, humid;

    if (status) {
        tempc = conv_float_uint32(bme280.getTemperature());
        lg.report("bme280.temp", tempc);
        press = bme280.getPressure();
        lg.report("bme280.press", press);
        humid = bme280.getHumidity();
        lg.report("bme280.humid", humid);
    }
}

#endif // S_BME280
