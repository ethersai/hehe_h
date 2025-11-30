#include "hehe_time.h"

int main(void)
{
    char buffer[64];
    hehe_timestamp_iso(buffer, sizeof(buffer)); 
    printf("%s\n", buffer);
    hehe_timestamp_brief(buffer, sizeof(buffer));
    printf("%s\n", buffer);
    
    // siema windows!

    return 0;
}
