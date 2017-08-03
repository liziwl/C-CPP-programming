#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

    // printf("jump-%d-sp-{%c}end", sline, separator);

    int *exact;
    int size; // extract columm size
    size = argc - optind;
    // printf("\nsize%dargc%d\n", size, argc);
    if (optind < argc) {
        exact = (int *) malloc(sizeof(int) * size);
    }

    // printf("\n");
    int i = optind;
    for (; i < argc; ++i) {//copy argv to exact
        exact[i - optind] = atoi(argv[i]);
        // printf("argv%d ", atoi(argv[i]));
    }

    // time_t tt;
    // tt = time(NULL);
    // char fileName[32];
    // strftime(fileName, sizeof(fileName), "%Y%m%d%H%M%S_out.csv", localtime(&tt));
    //format the output fileName
    // FILE *foutp = fopen(fileName, "w+");
    // if (foutp == NULL) {
    //     return -1;
    // }

    // skip the first lines
    char cursor;// current cursor
    int spcount = 1;// separator count
    int counter = sline;// skip line count
    int quotes = 0;
    while ((cursor = getchar()) != EOF) {
        //skip lines
        if (counter > 0) {
            if (cursor == '\n') {
                --counter;
            }
            continue;
        }
        if (cursor == '\n') {
            // fputc(cursor, foutp);
            putchar(cursor);
            spcount = 1;
            continue;
        }
        if (cursor == '"') {
            quotes = quotes + 1;
            quotes = quotes % 2;
            if (isTheCol(spcount, exact, size) == 0) {// if the specific column
                // fputc(cursor, foutp);
                putchar(cursor);
            }
            continue;
        }
        if (cursor == separator) {
            if (0 == quotes) {
                if (isTheCol(spcount++, exact, size) == 0) {// if the specific column
                    // fputc(cursor, foutp);
                    putchar(cursor);
                }
            } else {
                if (isTheCol(spcount, exact, size) == 0) {// if the specific column
                    // fputc(cursor, foutp);
                    putchar(cursor);
                }
            }
            continue;
        }
        if (isTheCol(spcount, exact, size) == 0) {// if the specific column
            // fputc(cursor, foutp);
            putchar(cursor);
            continue;
        }
    }
    // fclose(foutp);
    free(exact);
    // printf("Output fileName: %s\n", fileName);
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
