#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lt8618_ioctl.h"
#include <argp.h>
#include <asm/types.h>
#include <dlfcn.h>
#include <linux/fb.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include "hb_vot.h"
// #include "iar_interface.h"
#include "iar_interface.h"
#include "hb_vio_interface.h"
#include <signal.h>

int main(int argc, char **argv)
{

    hdmi_timing_t iar_timing = {0};

    hdmi_timing_t hdmi_timing;
    int ret = 0;
    lt8618_ioctl_init();
    memset(&hdmi_timing, 0, sizeof(hdmi_timing));
    ret = lt8618_get_edid_resolution_ratio((hdmi_timing_t *)&hdmi_timing);
    // LOG("main ret = %d, data.hfp = %d,data.hs=%d,data.hbp = %d,data.hact=%d,data.htotal = %d,data.vfp=%d,data.vs = %d,data.vbp=%d,data.vact=%d,data.vtotal=%d,data.vic=%d,data.pic_ratio=%d,data.clk=%d\n",
    //     ret, hdmi_timing.hfp, hdmi_timing.hs, hdmi_timing.hbp, hdmi_timing.hact, hdmi_timing.htotal, hdmi_timing.vfp, hdmi_timing.vs, hdmi_timing.vbp, hdmi_timing.vact, hdmi_timing.vtotal, hdmi_timing.vic, hdmi_timing.pic_ratio, hdmi_timing.clk);
    if (!ret)
    {
        if (hdmi_timing.vact > 1080)
        { /*iar only support 1080p*/
            hdmi_timing.vact = 1080;
            hdmi_timing.hact = 1920;
        }
        printf("%d,%d", hdmi_timing.vact, hdmi_timing.hact);
    }
    else
    {
        printf("1080,1920");
    }

    return 0;
}