#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *arg[]){
    // char name[50];
    // int id;
    // printf("Enter your name:");
    // gets(name);
    // // printf("%s",name );
    // printf("Enter your ID:");
    // scanf("%d",&id);
    char raw[200];
    // sprintf(raw,"Welcome %s(%d) to the C and C++ world",name,id);
    // fgets(&id,)
    sprintf(raw,"Welcome %s(%s) to the C and C++ world",arg[1],arg[2]);
    fprintf(stdout, raw);  
    // printf("%s\n",raw);

    return 0;
}
