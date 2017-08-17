#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#define SLEEP_TIME   5

int main() {
    int        nap = SLEEP_TIME;
    time_t     now;
    struct tm *t;
    int        remains = 0;
    int        sig;
    char       whoami[50];
    pid_t      pid;

    sprintf(whoami, "parent (%d)", getpid());
    if ((pid = fork()) == -1) {
       perror("fork()");
       exit(1);
    }
    if (pid == 0) {
      if (execl("./peekaboo", "./peekaboo", NULL) == -1) {
         perror("execl");
         exit(1);
      }
    }
    while (1) {
       if (remains == 0) {
          now = time(NULL);
          t = localtime(&now);
          printf("%s %02d:%02d:%02d beep!\n",
                  whoami,
                  t->tm_hour, t->tm_min, t->tm_sec);
          remains = sleep(nap);
        } else {
          remains = sleep(remains - 1);
        }
    }
    return 0;
}
