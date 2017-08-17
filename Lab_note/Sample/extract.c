#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define OPTIONS     "i:s:"

static char G_separator = ' ';
static int  G_skip = 0;

static void usage(char *progname) {
   fprintf(stderr, "Usage: %s [flags] field# [ field# ...]\n", progname);
   fprintf(stderr, " flags: -i n  :  ignore n first lines (default 0)\n");
   fprintf(stderr, "        -s c  :  use c as separator (default space)\n");
}

int main(int argc, char **argv) {
    int   ch;
    int  *fields = NULL;
    int   fieldcnt;
    int   linenum;
    int   fieldnum;
    int   i;
    int   k;
    char  quoted;

    while ((ch = getopt(argc, argv, OPTIONS)) != -1) {
       switch (ch) {
          case 'i':
               if (sscanf(optarg, "%d", &G_skip) != 1) {
                 fprintf(stderr, "Invalid number of lines to skip \"%s\"\n",
                                 optarg);
                 usage(argv[0]);
                 return 1;
               }
               break;
          case 's':
               if (strlen(optarg) > 1) {
                 fprintf(stderr, "Separator must be a single character\n");
                 usage(argv[0]);
                 return 1;
               }
               G_separator = *optarg;
               break;
          case '?':
          default:
               usage(argv[0]);
               return 1;
               break; /*NOTREACHED*/
       }
    }
    if ((fieldcnt = (argc - optind)) == 0) {
       usage(argv[0]);
       return 1;
    }
    if ((fields = (int *)malloc(sizeof(int) * fieldcnt)) == NULL) {
       perror("malloc()");
       return 1;
    }
    // Check fields
    k = 0;
    for (i = optind; i < argc; i++) {
      if (sscanf(argv[i], "%d", &(fields[k])) != 1) {
         fprintf(stderr, "Invalid field number \"%s\"\n", argv[i]);
         usage(argv[0]);
         free(fields);
         return 1;
      }
      if (k && (fields[k] <= fields[k-1])) {
         fprintf(stderr,
                 "Field numbers must be increasing and not repeating\n");
         free(fields);
         return 1;
      }
      k++;
    }
    // Now read the file
    linenum = 1;
    fieldnum = 1;
    quoted = 0;
    i = 0;  // Index in the fields array
    while ((ch = getchar()) != EOF) {
      // printf("line %d, field %d, next tp show %d\n",
      //         linenum, fieldnum, fields[i]); fflush(stdout);
      if (linenum > G_skip) {
        if (quoted) {
          if (fieldnum == fields[i]) {
            putchar(ch);
          }
          if (ch == '"') {
            quoted = 0;
          }
        } else {
          switch (ch) {
            case '\n':
                putchar(ch);
                linenum++;
                fieldnum = 1;
                i = 0;
                break;
            case '"':
                if (fieldnum == fields[i]) {
                   putchar(ch);
                }
                quoted = 1;
                break;
            default:
                if (ch == G_separator) {
                  if (fieldnum == fields[i]) {
                    if (i == fieldcnt - 1) {
                      i = 0;  // No longer need to worry
                    } else {
                      putchar(G_separator);
                      i++;
                    }
                  }
                  fieldnum++;
                } else {
                  if (fieldnum == fields[i]) {
                    putchar(ch);
                  }
                }
                break;
          }
        }
      } else {
        // Skip the line. Just look at \n
        if (ch == '\n') {
          linenum++;
        }
      }
    }
    if (fields) {
      free(fields);
    }
    return 0;
}
