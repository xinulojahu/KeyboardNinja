#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "language.h"

// int practice();  //основная фукнция
// int char_to_int(char*, int, int);  // функция перевода числв char в число int

int char_to_int(char* str, char dec) {
    int res = 0;
    while (*str != dec) {
        res *= 10;
        res += *str - '0';
        str++;
    }
    return res;
}

int practice() {
    char language[3];
    get_language(language);
    FILE* practice_done;
    char* str;  // указатель на массив строк из файла
    int min;    // минимальное количество попыток
    int start_min;  // используется для финальной проверки
    int temp;  // переменная для записи количества попыток для сравнения
    int key = 1;  // переменная для запоминания номера текста
    int number_of_text = 0;  // переменная, в которой хранится
                             // необходимый номер текста
    char* path = malloc(32 * sizeof(char));  //массив для пути
    sprintf(path, "%s/practice_done.txt", language);  //создает текстовый путь
    practice_done = fopen(path, "r");  // открываем файл
    free(path);  //особождаем массив для пути
    if (practice_done == NULL) {  // проверка на открытие файла
        printf("Error with opening file");
        return -1;
    }

    str = malloc(152 * sizeof(char));  // выделяем динамическую память для str
    fgets(str, 150, practice_done);  // записываем в массив первую строку
    min = char_to_int(str, '|');  // запоминаем минимальным количеством
                                  // попыток количество в первом тексте
    start_min = min;  // присваеваем для дальнейшего сравнения

    for (int i = 1; !feof(practice_done); i++) {
        fgets(str, 150,
              practice_done);  //получаем строку (уже получаем вторую и так
                               //далее)
        if (i % 2 == 0) {  // если строка с количеством попыток
            temp = char_to_int(str, '|');  //то запоминаем эти попытки в temp
            key++;  // повышаем количество текстов в файле
            if (temp < min) {  // если temp больше min
                min = temp;    // присваемваем min temp
                number_of_text = key;  // запоминаем номер необзодимого текста
            }
        }
    }

    if (min == start_min) {  // если минимальное количество осталось прежним
        number_of_text = 1;  // запоминаем первый текст
    }
    fclose(practice_done);  // закрываем файл
    free(str);

    return number_of_text;  // возвращаем номер текста
}
