#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    //if have 2 argv, the first is considered as name and the second is considered as ID. 
    //if not, warn user to intput.
    char raw[200];
    if (argc <3)
    {
        char name[50];
        int id;
        printf("Enter your name:");
        gets(name);
        printf("Enter your ID:");
        scanf("%d",&id);
        sprintf(raw,"Welcome %s(%d) to the C and C++ world",name,id);
    }
    else{
        sprintf(raw,"Welcome %s(%s) to the C and C++ world",argv[1],argv[2]);
    }
    fprintf(stdout, raw);
    return 0;
}
