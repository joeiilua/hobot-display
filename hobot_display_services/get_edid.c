#include <stdio.h>
#include "lt8618_ioctl.h"
#include <string.h>

int main()
{
    edid_raw_t data;
    memset(&data, 0, sizeof(edid_raw_t));
    lt8618_ioctl_init();
    lt8618_get_edid_data(&data);
    for (size_t i = 0; i < 256; i++)
    {
        printf("0x%02x ", data.edid_data[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    if (data.block_num == 2)
    {
        for (size_t i = 0; i < 256; i++)
        {
            printf("0x%x ", data.edid_data2[i]);
            if ((i + 1) % 16 == 0)
                printf("\n");
        }
    }
}