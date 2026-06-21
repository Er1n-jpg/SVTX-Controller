extern bool sw_prev_raw_val[SW_GPIO_SIZE];
extern bool sw_cooked_val[SW_GPIO_SIZE];
extern uint64_t sw_timestamp[SW_GPIO_SIZE];

#include "deferred.c"
#include "eager.c"