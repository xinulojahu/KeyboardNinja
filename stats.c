#include <stdio.h>
#include <stdlib.h>

int stats() {
    FILE* stats_file;
    char str;
    stats_file = fopen("results.txt", "r");
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

