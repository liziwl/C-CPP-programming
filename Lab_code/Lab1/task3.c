#include <stdio.h>
#include <string.h>
#include <ctype.h>

int char2num(char a){
    return toupper(a)-65;
}

int main(int argc, char *argv[]){
    //receive the first argv to encrypte.

    //generate alphabet table
    int i;
    char alphabet[26][26];
    for (i=0;i<26;i++){
        char initial='A';
        int j;
        for (j= 0; j < 26; j++) {
            int shift=(i+j)%26;
            alphabet[i][j]=initial+shift;
        }
    }

    char raw[200];
    scanf("%[^\n]",raw);
    //get previous output, so you can use pipe command
    //such that ./taks1 "YOUR NAME" "YOUR ID" | ./task3 
    //This will give the encrypted code.
    char rawup[strlen(raw)];
    strcpy(rawup,raw);
    for (i = 0; i < strlen(rawup); i++) {
        rawup[i]=toupper(rawup[i]);//change to upper case
    }

    char *key="Vigenere";
    //encode
    char encode[strlen(raw)];
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
    printf("%s\n",rawup);
    printf("Encrypted: %s\n",encode);
    return 0;
}
