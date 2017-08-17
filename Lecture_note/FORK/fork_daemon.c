#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main() {
    int        remains = 0;
    char       whoami[50];
    pid_t      pid;

    sprintf(whoami, "parent (%d)", getpid());
    if ((pid = fork()) == -1) {
       perror("fork()");
       exit(1);
    }
    if (pid == 0) {
      if (execl("./peekaboo_daemon", "./peekaboo_daemon", NULL) == -1) {
         perror("execl");
         exit(1);
      }
    }
    printf("%s daemon started - quitting\n", whoami);
    return 0;
}
