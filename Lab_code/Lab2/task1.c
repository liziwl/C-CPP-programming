#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int isTheCol(int column, int *col, int len);
    int opt;
    char separator = ' ';
    int sline = 0;

    while ((opt = getopt(argc, argv, "s:i:")) != -1) {
        switch (opt) {
            case 's':
                separator = *optarg;
                if ('-' == separator && '\0' != (separator)++) {
                    fprintf(stderr,
                            "Missing argument(s)\nUsage: %s [-s <separator_used>] [-i <ignore_lines>] <extract_lines_number>\n",
                            argv[0]);
                    exit(1);
                }
                break;
            case 'i':
                sline = atoi(optarg);
                // printf("sline%d\n", sline);
                if ('-' == separator && '\0' != (separator)++) {
                    fprintf(stderr,
                            "Missing argument(s)\nUsage: %s [-s <separator_used>] [-i <ignore_lines>] <extract_lines_number>\n",
                            argv[0]);
                    exit(1);
                }
                break;
            default: /* '?' */
                fprintf(stderr, "Usage: %s [-s <separator_used>] [-i <ignore_lines>] <extract_lines_number>\n",
                        argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    printf("jump-%d-sp-{%c}end", sline, separator);

    int *exact;
    int size; // extract columm size
    size = argc - optind;
    printf("\nsize%dargc%d\n", size, argc);
    if (optind < argc) {
        exact = (int *) malloc(sizeof(int) * size);
    }

    printf("\n");
    int i = optind;
    for (; i < argc; ++i) {
        exact[i - optind] = atoi(argv[i]);
        printf("argv%d ", atoi(argv[i]));
    }


    FILE *fp = fopen("unidata.csv", "r");
    if (fp == NULL) {
        return -1;
    }

    FILE *foutp = fopen("unidata_out.csv", "w+");
    if (foutp == NULL) {
        return -1;
    }

    //skip the first lines
    char cursor;
    int spcount = 1;//separator count
    int counter = sline;//skip line count
    int quotes = 0;
    while ((cursor = fgetc(fp)) != EOF) {
        // printf("%d\n",counter );
        if (counter > 0) {
            if (cursor == '\n') {
                --counter;
            }
            continue;
        }
        if (cursor == '\n') {
            fputc(cursor, foutp);
            spcount = 1;
            continue;
        }
        if (cursor == '"') {
            quotes = quotes + 1;
            quotes = quotes % 2;
            continue;
        }
        if (cursor == separator) {
            if (0 == quotes) {
                ++spcount;
                if (isTheCol(spcount, exact, size) == 0) {// find the specific column
                    fputc(cursor, foutp);
                }
            } else {
                if (isTheCol(spcount, exact, size) == 0) {// find the specific column
                    fputc(cursor, foutp);
                }
            }
            continue;
        }
        if (isTheCol(spcount, exact, size) == 0) {// find the specific column
            fputc(cursor, foutp);
            continue;
        }
        if ((cursor != '\0') && (1 == quotes) && (isTheCol(spcount, exact, size) == 0)) {
            fputc(cursor, foutp);
            continue;
        }
    }
    fclose(foutp);
    fclose(fp);
    exit(EXIT_SUCCESS);
}

int isTheCol(int column, int *col, int len) {
    //0 means column is in *col, else is not.
    int i;
    int *itp = col;
    for (i = 0; i < len; i++) {
        // printf("itp%d\n",*itp);
        if (column == *itp) {
            return 0;
        } else {
            itp++;
        }
    }
    return 1;
}
