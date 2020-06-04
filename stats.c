#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "language.h"

int stats(int num) {
    FILE* stats_file;
    char str[100];
    char *estr;
    //char* language[3];
    //get_language(language);
    //char* path = malloc(32 * sizeof(char));
    //sprintf(path, "%s/results.txt", language);
    //stats_file = fopen(path, "r");
    //free(path);

    stats_file = fopen("results.txt", "r");
    printf("Argument is %d\n", num); //Вспомогательная строка
    if (stats_file == NULL) {
        printf("Error openning the file!\n");
        return -1;
    }
    //Чтение построчно данных из файла в бесконечном цикле
    while (1) {
            // Чтение одной строки  из файла
            estr = fgets (str, 100, stats_file);
            //Проверка на конец файла или конец аргумента
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
            num = num - 1;
     }       
    //Закрытие файла
    fclose(stats_file);
    printf("\n");
    return 0;
}
    
//Функция для проверки работы файла
int main() {
    int arg;
    printf("\nEnter the argument:\n");
    scanf("%d", &arg);
    stats(arg);
    return 0;
}
