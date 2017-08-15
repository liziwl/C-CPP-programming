#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
   pid_t pid;

   if ((pid = fork()) >= 0) {
     if (pid == 0) {
       printf("%d: committing suicide (parent %d)\n",
              (int)getpid(), (int)getppid());
       exit(0);
     } else {
       printf("%d: going to sleep for a while - child %d might die while I snooze\n",
              (int)getpid(), (int)pid);
       sleep(30);
       printf("%d: awake\n", (int)getpid());
     }
   }
   return 0;
}
