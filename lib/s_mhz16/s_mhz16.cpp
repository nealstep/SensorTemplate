#include "s_mhz16.h"
#ifdef S_MHZ16
#include <sensors.h>

#include <SoftwareSerial.h>

SoftwareSerial sen_ser(1, 3);

const byte cmd_get_sensor[] = {
    0xff, 0x01, 0x86, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x79
};

uint16_t tempc;
uint16_t co2ppm;

void s_mhz16_init(void) {
    lg.debug("s_mhz16 init");

	sen_ser.begin(9600);
}

bool s_mhz16_recv(void) {
    byte data[9];
    uint8_t i;

    //transmit command data
    for(i=0; i<sizeof(cmd_get_sensor); i++) {
		sen_ser.write(cmd_get_sensor[i]);
    }
    delay(10);
    //begin reveiceing data
    if(sen_ser.available()) {
        while(sen_ser.available()) {
            for(i=0;i<9; i++) {
                data[i] = sen_ser.read();
            }
        }
    }
    if((i != 9) || (1 + (0xFF ^ (byte)(data[1] + data[2] + data[3] + data[4] + data[5] + data[6] + data[7]))) != data[8]) {
        return false;
    }
    co2ppm = (int)data[2] * 256 + (int)data[3];
    tempc = (int)data[4] - 40;
    return true;
}

void s_mhz16_check(void) {
    lg.debug("s_mhz16 check");

	if(s_mhz16_recv()) {
		lg.report("mhz16.temp", tempc);
		lg.report("mhz16.co2", co2ppm);
	} else {
		lg.error("MH-Z16: Read failed");
	}
}

#endif // S_MHZ16
