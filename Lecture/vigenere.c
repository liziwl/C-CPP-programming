#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 250

int main(int argc, char *argv[]) {
    int   i;
    char  ch;
    char  key[MAXLEN];
    char *p;
    int   len;
    int   pos;

    if (argc == 2) {
      strncpy(key, argv[1], MAXLEN);
    } else {
      printf("Key ? ");
      fgets(key, MAXLEN, stdin);
      len = strlen(key);
      while (isspace(key[len - 1])) {
        len--;
      }
      key[len] = '\0';
    }
    // Process the key
    i = 0;
    p = key;
    while (*p) {
      if (isalpha(*p)) {
        key[i++] = toupper(*p);
      } 
      p++;
    }
    key[i] = '\0';
    //
    i = 0;
    while ((ch = getchar()) != EOF) {
      if (isalpha(ch)) {
        pos = toupper(ch) - 'A';
        ch = toupper(key[i]) + pos;
        if (ch > 'Z') {
          ch = 'A' + (ch - 'Z' - 1);
        }
        putchar(ch);
        i++;
        if (i == strlen(key)) {
          i = 0;
        }
      } else {
        putchar(ch);
      }
    }
    return 0;
}
