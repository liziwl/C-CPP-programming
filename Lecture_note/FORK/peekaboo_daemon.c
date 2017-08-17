#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#define SLEEP_TIME  5 

int main() {
    int        nap = SLEEP_TIME;
    time_t     now;
    struct tm *t;
    FILE      *fp;

    printf("peekaboo daemon program, current pid %d\n", getpid());
    if (daemon(0,0) == -1) {
       perror("daemon");
       exit(1);
    }
    if ((fp = fopen("/tmp/peekaboo.log", "w")) == NULL) {
       perror("fopen");
       exit(1);
    }
    while (1) {
        now = time(NULL);
        t = localtime(&now);
        fprintf(fp, "%02d:%02d:%02d peekaboo!\n",
                t->tm_hour, t->tm_min, t->tm_sec);
        fflush(fp);
        sleep(nap);
    }
    return 0;
}
