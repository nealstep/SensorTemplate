#include "s_dummy.h"
#ifdef S_DUMMY
#include <sensors.h>

void s_dummy_init(void) {
    lg.debug("s_dummy init");
  
    noop();
}

void s_dummy_check(void) {
    lg.debug("s_dummy check");
    
    float test1 = 5.6;
    uint16_t test2 = 131;

    lg.report("s_dummy.test1", conv_float_uint32(test1));
    lg.report("s_dummy.test2", test2);
}

#endif // S_DUMMY
