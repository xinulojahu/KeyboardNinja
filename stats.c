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
    printf("Argument is %d\n", num);
    if (stats_file == NULL) {
        printf("Error openning the file!\n");
        return -1;
    }

    while (1) {
            estr = fgets (str, 100, stats_file);
            if ((estr == NULL) || (num == 0)) {
                if (feof (stats_file) != 0) {
                    printf("Reading is complete!\n");
                    break;
                }
                else {
                    printf("Reading is complete.\n");
                    break;
                }
            }
            puts(str);
            num--;
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
