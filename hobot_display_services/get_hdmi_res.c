#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h>

int main() {
    // open fb device
    int fb = open("/dev/fb0", O_RDWR);
    if (fb == -1) {
        perror("Can't open fb device");
        exit(EXIT_FAILURE);
    }

    // get fb info
    struct fb_var_screeninfo vinfo;
    if (ioctl(fb, FBIOGET_VSCREENINFO, &vinfo)) {
        perror("Can't get fb info");
        close(fb);
        exit(EXIT_FAILURE);
    }
    printf("%d,%d", vinfo.yres, vinfo.xres);

    // close
    close(fb);

    return 0;
}

