#include <Arduino.h>
#include <Logger.h>

#include <sensor.h>

static const uint32_t baud = 115200;
static const uint16_t loop_delay = 5000;
static const uint8_t time_serial = 50;

void setup(void) {
    Serial.begin(baud);
    lg.set_level(logger_debug);
    while (!Serial.available()) delay(time_serial);
    sensor_init();
    lg.info("Started");
}

void loop(void) {
    sensor_check();
    delay(loop_delay);
    lg.info("Looping");
}

void send(const char* msg) {
    Serial.println(msg);
}
