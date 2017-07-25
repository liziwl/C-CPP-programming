#include <stdio.h>
#include <string.h>
#include <ctype.h>

int char2num(char a){
    return toupper(a)-65;
}

int main(int argc, char *arg[]){

    //generate alphabet table
    int i;
    
    char *key="Vigenere";
    printf("Key:%s\n", key);
    printf("%s\n",arg[1]);

    //decode
    char decode[strlen(arg[1])];
    for (i = 0; i < strlen(arg[1]); i++) {
        if(isalpha(arg[1][i])==0) {
            decode[i]=(char)arg[1][i];
        } else {
            int keyseq = i % (strlen(key));//which char in key
            char dnc= (char2num(arg[1][i])-char2num(key[keyseq])+260)%26+65;
            decode[i]=(char)dnc;
        }
    }
    printf("Decrypted: %s\n",decode);
    return 0;
}
