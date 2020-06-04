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

    FILE* temp_file;
    temp_file = fopen("res_temp.txt", "w+");

    char* str;
    int num = 1;
    str = malloc(64 * sizeof(char));

    if (fgets(str, 64, stats_file) != NULL) {
        num = (char_to_int(str, 0, 1, 2) + 1) % 1000;
        fputs(str, temp_file);
    }
    while (fgets(str, 64, stats_file) != NULL) {
        fputs(str, temp_file);
    }
    fseek(stats_file, 0, SEEK_SET);
    fprintf(stats_file, "%03d|%02d:%02d|%4d|%3d|%5.1f%%\n", num, seconds / 60,
            seconds % 60, sym_per_minuts, errors, errors_prcnt);
    fseek(temp_file, 0, SEEK_SET);
    while (fgets(str, 64, temp_file) != NULL) {
        fputs(str, stats_file);
    }
    remove("res_temp.txt");
    fclose(temp_file);
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

