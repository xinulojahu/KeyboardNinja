#include <stdio.h>
#include <stdlib.h>
#include "language.h"

int stats() {
    FILE* stats_file;
    char str;
    char* language[3];
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

