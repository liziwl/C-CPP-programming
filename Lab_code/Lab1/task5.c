#include <stdio.h>
#include <string.h>
#include <ctype.h>

int char2num(char a){
    return toupper(a)-65;
}

int main(int argc, char *argv[]){
    //receive the first argv to decrypte.
    
    int i;
    char *key="Vigenere";
    printf("Key:%s\n", key);
    printf("%s\n",argv[1]);

    //decode
    char decode[strlen(argv[1])];
    for (i = 0; i < strlen(argv[1]); i++) {
        if(isalpha(argv[1][i])==0) {
            decode[i]=(char)argv[1][i];
        } else {
            int keyseq = i % (strlen(key));//which char in key
            char dnc= (char2num(argv[1][i])-char2num(key[keyseq])+260)%26+65;
            decode[i]=(char)dnc;
        }
    }
    printf("Decrypted: %s\n",decode);
    return 0;
}
