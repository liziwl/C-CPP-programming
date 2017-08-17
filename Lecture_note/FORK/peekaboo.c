#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define SLEEP_TIME  5 

int main() {
    int        nap = SLEEP_TIME;
    time_t     now;
    struct tm *t;

    while (1) {
        now = time(NULL);
        t = localtime(&now);
        printf("%02d:%02d:%02d peekaboo!\n", t->tm_hour, t->tm_min, t->tm_sec);
        sleep(nap);
    }
    return 0;
}
