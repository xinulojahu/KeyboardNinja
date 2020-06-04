#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "language.h"

int stats(int num) {
    FILE* stats_file = fopen("results.txt", "r");
    char str[100];
    char *estr;
    //char* language[3];
    //get_language(language);

    if (stats_file == NULL) {
        printf("Error openning the file!\n");
        return -1;
    }
    else if (fgets(str, 100, stats_file) != NULL) {
        if (num == NULL) {
            //Think about it
        }
        else {
            for (int i = 0; i < num; i++) {
                puts(str);
            }
        }
    }
    fclose(stats_file);
    printf("\n");
    return 0;
}
    

int main() {
    int arg;
    printf("\nEnter the argument:\n");
    scanf("%d", &arg);
    stats(arg);
    return 0;
}
