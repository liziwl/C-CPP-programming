#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define SLEEP_TIME   10

int        nap = SLEEP_TIME;

void handler(int sig) {
    printf("Tada!\n");
    nap /= 2;
    if (nap == 0) { nap=1;}
}

int main() {
    time_t     now;
    struct tm *t;

    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    while (1) {
       now = time(NULL);
       t = localtime(&now);
       printf("%02d:%02d:%02d beep!\n",
               t->tm_hour, t->tm_min, t->tm_sec);
       sleep(nap);
    }
    return 0;
}
