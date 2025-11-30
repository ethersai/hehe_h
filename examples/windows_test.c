#define HEHE_TIME_IMPLEMENTATION
#include "hehe_time.h"

int main(void)
{
    char buffer[64];
    hehe_timestamp_iso(buffer, sizeof(buffer)); 
    printf("%s\n", buffer);
    hehe_timestamp_brief(buffer, sizeof(buffer));
    printf("%s\n", buffer);
   
    uint64_t x = hehe_time_get_ms();
    uint64_t y = hehe_time_get_ns();
    uint64_t z = hehe_time_get_sec();

    HEHE_LOG_INFO("MS:%llu\n, NS:%llu\n, SEC:%llu\n", x, y, z);

    // siema windows!

    return 0;
}
