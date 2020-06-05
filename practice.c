#include "language.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int practice();  //основная фукнция
// int char_to_int(char*, int, int);  // функция перевода числв char в число int
// int practice_print(int); // Функция вывода лучших результатов

int char_to_int(char* str, char dec)
{
    int res = 0;
    while (*str != dec) {
        res *= 10;
        res += *str - '0';
        str++;
    }
    return res;
}

int practice_print(int num)
{
    char str[100]; //Переменная для записи строк
    char* estr; //Указатель с адресом массива со строкой
    int numcount;
    int count = 1; //Счетчик итераций цикла

    FILE* practice_best; //Переменная с указателем на поток данных
    char language[3];
    get_language(language);
    char* path = malloc(32 * sizeof(char)); //массив для пути
    sprintf(path, "%s/practice_done.txt", language); //создает текстовый путь
    practice_best = fopen(path, "r"); // открываем файл
    free(path); //особождаем массив для пути
    if (practice_best == NULL) { // проверка на открытие файла
        printf("Error with opening file");
        return -1;
    }

    numcount = num;
    num = num - 1;

    //Чтение построчно данных из файла в бесконечном цикле
    while (1) {
        // Чтение одной строки  из файла
        estr = fgets(str, 100, practice_best);
        //Проверка на конец файла или конец аргумента
        if ((estr == NULL) || (num == 0)) {
            if (feof(practice_best) != 0) {
                printf("Reading is complete!\n");
                break;
            } else {
                printf("Reading is complete.\n");
                break;
            }
        }
        num = num - 1; //Уменьшение аргумента с каждой итерацией
        count++; //Счетчик
    }
    //Условие на проверку конца цикла или конец файла
    if ((count == numcount) && (feof(practice_best) == 0)) {
        puts(str); //Вывод нужной строки
    } else {
        printf("Invalid input!\n");
    }
    //Закрытие файла
    printf("\n");
    fclose(practice_best);
    return 0;
}

int practice()
{
    FILE* practice_done;
    char* str; // указатель на массив строк из файла
    int min;   // минимальное количество попыток
    int start_min; // используется для финальной проверки
    int temp; // переменная для записи количества попыток для сравнения
    int key = 1; // переменная для запоминания номера текста
    int number_of_text = 0; // переменная, в которой хранится
                            // необходимый номер текста
    char language[3];
    get_language(language);
    char* path = malloc(32 * sizeof(char)); //массив для пути
    sprintf(path, "%s/practice_done.txt", language); //создает текстовый путь
    practice_done = fopen(path, "r"); // открываем файл
    free(path); //особождаем массив для пути
    if (practice_done == NULL) { // проверка на открытие файла
        printf("Error with opening file");
        return -1;
    }

    str = malloc(152 * sizeof(char)); // выделяем динамическую память для str
    fgets(str, 150, practice_done); // записываем в массив первую строку
    min = char_to_int(str, '|'); // запоминаем минимальным количеством
                                 // попыток количество в первом тексте
    start_min = min; // присваеваем для дальнейшего сравнения

    for (int i = 1; !feof(practice_done); i++) {
        fgets(str,
              150,
              practice_done); //получаем строку (уже получаем вторую и так
                              //далее)
        if (i % 2 == 0) { // если строка с количеством попыток
            temp = char_to_int(str, '|'); //то запоминаем эти попытки в temp
            key++; // повышаем количество текстов в файле
            if (temp < min) { // если temp больше min
                min = temp;   // присваемваем min temp
                number_of_text = key; // запоминаем номер необзодимого текста
            }
        }
    }

    if (min == start_min) { // если минимальное количество осталось прежним
        number_of_text = 1; // запоминаем первый текст
    }
    fclose(practice_done); // закрываем файл
    free(str);

    return number_of_text; // возвращаем номер текста
}
