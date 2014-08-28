#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

#define IDLE_COUNT 60

int main(void) {

    const char *dev = "/dev/input/event0";
    struct input_event ev;
    ssize_t n;
    int fd;

    int time_out = 0;
    int HDMI_ON = 1;

    FILE *in;
    char buff[512];

    if (!(in = popen("/usr/bin/tvservice -s", "r"))) {
        printf("Error reading video on/off status\n");
        return 1;
    }
    //while (fgets(buff, sizeof(buff), in) != NULL);
    fgets(buff, sizeof(buff), in);
    pclose(in);

    //printf("%s\n", buff);
    if (strncmp("state 0x120002 [TV is off]", buff, 26) == 0) {
        printf("HDMI is off\n");
        HDMI_ON = 0;
    } else {
        printf("HDMI is on\n");
        HDMI_ON = 1;
    }
    
    fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }

    // set non blocking mode on device input
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);

    while (1) {
        
        n = read(fd, &ev, sizeof ev);

        if (n == (ssize_t)-1) {
            if (errno == EAGAIN) {
                
                // nothing found in the device buffer
                //printf("."); fflush(stdout);

                if (HDMI_ON == 1) {
                    time_out++;
                    if (time_out > IDLE_COUNT) {
                        printf("power down HDMI\n");
                        system ("/usr/bin/tvservice -o");
                        HDMI_ON = 0;
                        time_out = 0;
                    }
               }
 
                sleep(1);
                continue;

            } else if (errno == EINTR) {
                // don't know what is this
                printf("screenblanker: got error?\n");
                continue;

            } else {
                // error
                break;
            }
        } else if (n != sizeof ev) {
            // error
            errno = EIO;
            break;
        }
       
        // something found in the device buffer
        if(HDMI_ON == 0) {
            system ("/usr/bin/tvservice -p");
            system ("/bin/fbset -depth 8");
            system ("/bin/fbset -depth 16");
            HDMI_ON = 1;
        }
        time_out = 0;
       
    }

    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return EXIT_FAILURE;
}

