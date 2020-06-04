#include <stdio.h>
#include <stdlib.h>
#include "language.h"
#include "practice.h"

int stats_fprint(int seconds, int sym_per_minuts, int errors,
                 double errors_prcnt) {
    FILE* stats_file;
    char language[3];
    get_language(language);
    char* path = malloc(32 * sizeof(char));
    sprintf(path, "%s/results.txt", language);
    stats_file = fopen(path, "r+t");
    if (stats_file == NULL) {
        stats_file = fopen(path, "w+t");
    }
    free(path);

    fpos_t pos;
    char* str;
    int num = 1;
    str = malloc(64 * sizeof(char));

    fgetpos(stats_file, &pos);
    if (fgets(str, 64, stats_file) != NULL) {
        num = char_to_int(str, 0, 1, 2);
    }
    fsetpos(stats_file, &pos);
    fprintf(stats_file, "%d|%02d:%02d|%d|%d|%4.1f%%\n", num, seconds / 60,
            seconds % 60, sym_per_minuts, errors, errors_prcnt);
    fclose(stats_file);
    return 0;
}

int stats() {
    FILE* stats_file;
    char str;
    char language[3];
    get_language(language);

    char* path = malloc(32 * sizeof(char));
    sprintf(path, "%s/results.txt", language);
    stats_file = fopen(path, "r");
    free(path);
    if (stats_file == NULL) {
        printf("Error openning the file!\n");
        return -1;
    }

    str = fgetc(stats_file);
    while (str != EOF) {
        putchar(str);
        str = getc(stats_file);
    }
    printf("\n");
    fclose(stats_file);

    return 0;
}

