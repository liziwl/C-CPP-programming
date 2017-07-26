#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
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
        // printf("%s\n",raw);
    }
    fprintf(stdout, raw);
    return 0;
}
