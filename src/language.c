#include "language.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 64

FILE* openfile(char* filetxt, char* flag)
{
    FILE* file_ret;
    char language[3];
    get_language(language);
    char* path = malloc(64 * sizeof(char));
    sprintf(path, "%s/%s", language, filetxt);
    file_ret = fopen(path, flag);
    free(path);
    if (file_ret == NULL) {
        printf("Запустите файл из директории bin\n");
        exit(-1);
    }
    return file_ret;
}

int get_language(char* language)
{
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
                if (*(cur + 2) == '\n') {
                    *(cur + 2) = '\0';
                }
                if ((strcmp(cur, "RU") == 0) || (strcmp(cur, "EN") == 0)) {
                    strcpy(language, cur);
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

int change_language(char* language)
{
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
