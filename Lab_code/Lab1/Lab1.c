#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char name[50];
    int id;
    printf("Enter your name:");
    gets(name);
    // printf("%s",name );
    printf("Enter your ID:");
    scanf("%d",&id);
    char raw[200];
    sprintf(raw,"Welcome %s(%d) to the C and C++ world",name,id);
    printf("%s\n",raw);

    int i;
    // char *raw="Welcome Ziqiang(11510352) to the C and C++ world";
    // printf("%s\n",raw);

    int char2num(char a){
        return toupper(a)-65;
    }

    char *key="Vigenere";
    for (i = 0; i < strlen(key); i++) {
        toupper(key[i]);
    }

    //generate alphabet table
    char alphabet[26][26];
    for (i=0;i<26;i++){
        char initial='A';
        int j;
        for (j= 0; j < 26; j++) {
            int shift=(i+j)%26;
            alphabet[i][j]=initial+shift;
            printf("%c ",alphabet[i][j]);
        }
        printf("\n");
    }

    //change to upper case
    char rawup[strlen(raw)];
    strcpy(rawup,raw);
    for (i = 0; i < strlen(rawup); i++) {
        toupper(rawup[i]);
    }

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
    printf("Key:%s\n", key);
    printf("%s\n",raw);
    printf("Encrypted: %s\n",encode);

    //decode
    char decode[strlen(encode)];
    for (i = 0; i < strlen(encode); i++) {
        if(isalpha(encode[i])==0) {
            decode[i]=(char)encode[i];
        } else {
            int keyseq = i % (strlen(key));//which char in key
            char dnc= (char2num(encode[i])-char2num(key[keyseq])+260)%26+65;
            decode[i]=(char)dnc;
        }
    }
    printf("Decrypted: %s\n",decode);
    return 0;
}
