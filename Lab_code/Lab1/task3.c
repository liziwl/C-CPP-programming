#include <stdio.h>
#include <string.h>
#include <ctype.h>

int char2num(char a){
    return toupper(a)-65;
}

int main(int argc, char *arg[]){

    // printf("%d\n", strlen(arg[1]);

    //generate alphabet table
    int i;
    char alphabet[26][26];
    for (i=0;i<26;i++){
        char initial='A';
        int j;
        for (j= 0; j < 26; j++) {
            int shift=(i+j)%26;
            alphabet[i][j]=initial+shift;
            // printf("%c ",alphabet[i][j]);
        }
        // printf("\n");
    }

    //change to upper case
    // char *raw[strlen(arg[1])];
    // strcpy(raw,arg[1]);
    // printf("%s\n", raw);
    char rawup[strlen(arg[1])];
    strcpy(rawup,arg[1]);
    for (i = 0; i < strlen(rawup); i++) {
        toupper(rawup[i]);
    }
    printf("%s\n", rawup);

    char *key="Vigenere";
    //encode
    char encode[strlen(arg[1])];
    for (i = 0; i < strlen(rawup); i++) {
        if(isalpha(rawup[i])==0) {
            encode[i]=(char)rawup[i];
        } else {
            int keyseq = i % (strlen(key));//which char in key
            int line = char2num(key[keyseq]);//which line in alphabet
            char enc = alphabet[line][char2num(rawup[i])];
            encode[i]=(char)enc;
        }
    }
    encode[strlen(rawup)]='\0';
    printf("Key:%s\n", key);
    printf("%s\n",arg[1]);
    printf("Encrypted: %s\n",encode);
    return 0;
}
