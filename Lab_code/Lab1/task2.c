#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    //generate alphabet table
    char alphabet[26][26];
    int i;
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

    return 0;
}
