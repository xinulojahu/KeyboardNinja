#include "language.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 64

int get_language(char* language) {
    FILE* settings_file;
    settings_file = fopen("settings", "r");
    if (settings_file == NULL) {
        return -1;
    }
    char* str = malloc(MAX_SIZE * sizeof(char));
    while (fgets(str, MAX_SIZE, settings_file) != NULL) {
        char* cur = strtok(str, "=");
        if (cur != NULL) {
            if (strcmp(cur, "language") == 0) {
                cur = strtok(NULL, "=");
                if (strcmp(cur, "RU\n") == 0) {
                    strcpy(language, "RU");
                    fclose(settings_file);
                    free(str);
                    return 0;
                }
                if (strcmp(cur, "EN\n") == 0) {
                    strcpy(language, "EN");
                    fclose(settings_file);
                    free(str);
                    return 0;
                }
            }
        }
    }
    free(str);
    fclose(settings_file);
    return -1;
}

int change_language(char* language) {
    FILE* settings_file;
    settings_file = fopen("settings", "w");
    if (settings_file == NULL) {
        return -1;
    }
    if (strcmp(language, "RU") == 0) {
        fputs("language=EN", settings_file);
        strcpy(language, "EN");
        fclose(settings_file);
        return 0;
    }
    if (strcmp(language, "EN") == 0) {
        fputs("language=RU", settings_file);
        strcpy(language, "RU");
        fclose(settings_file);
        return 0;
    }
    fclose(settings_file);
    return -1;
}
