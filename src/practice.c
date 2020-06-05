#include "practice.h"
#include "language.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int practice();  //основная фукнция
// int char_to_int(char*, int, int);  // функция перевода числв char в число int
// int practice_print(int); // Функция вывода лучших результатов

void practice_check()
{
    FILE* practice_file;
    practice_file = openfile("practice_done.txt", "r");
    if (practice_file == NULL) {
        practice_file = openfile("practice_done.txt", "w");
    }
    for (int i = 0; i < PRACTICE_COUNT; i++) {
        fprintf(practice_file, "000|00:00|0000|000|000,0%%\n");
    }
    fclose(practice_file);
}

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
    practice_best = openfile("practice_done.txt", "r");
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
            break;
        }
        num = num - 1; //Уменьшение аргумента с каждой итерацией
        count++; //Счетчик
    }
    //Условие на проверку конца цикла или конец файла
    if ((count == numcount) && (feof(practice_best) == 0)) {
        fputs(str, stdout); //Вывод нужной строки
    } else {
        printf("Invalid input!\n");
    }
    //Закрытие файла
    fclose(practice_best);
    return 0;
}

int practice()
{
    char* str; // указатель на массив строк из файла
    int min;   // минимальное количество попыток
    int start_min; // используется для финальной проверки
    int temp; // переменная для записи количества попыток для сравнения
    int key = 1; // переменная для запоминания номера текста
    int number_of_text = 0; // переменная, в которой хранится
                            // необходимый номер текста
    FILE* practice_done; //Переменная с указателем на поток данных
    practice_done = openfile("practice_done.txt", "r");
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
        temp = char_to_int(str, '|'); //то запоминаем эти попытки в temp
        key++; // повышаем количество текстов в файле
        if (temp < min) { // если temp больше min
            min = temp;   // присваемваем min temp
            number_of_text = key; // запоминаем номер необзодимого текста
        }
    }

    if (min == start_min) { // если минимальное количество осталось прежним
        number_of_text = 1; // запоминаем первый текст
    }
    fclose(practice_done); // закрываем файл
    free(str);
    return number_of_text; // возвращаем номер текста
}

int practice_done(
        int num, int seconds, int sym_per_min, int errors, double errors_prcnt)
{
    char* str;
    int temp;
    int att_num;
    FILE* out; //Переменная с указателем на поток данных
    out = openfile("practice_done.txt", "r+");
    if (out == NULL) { // проверка на открытие файла
        printf("Error with opening file");
        return -1;
    }
    fpos_t pos;
    str = malloc(152 * sizeof(char));
    for (int i = 0; i < num - 1; i++) {
        fgets(str, 150, out);
    }
    fgetpos(out, &pos);
    fgets(str, 150, out);
    char* cur = str;
    for (int i = 0; i < 2; i++) {
        while (*cur != '|') {
            cur++;
        }
        cur++;
    }
    temp = char_to_int(cur, '|');
    att_num = char_to_int(str, '|');
    if (temp < sym_per_min) {
        att_num++;
        fsetpos(out, &pos);
        fprintf(out,
                "%03d|%02d:%02d|%04d|%03d|%05.1f%%\n",
                att_num,
                seconds / 60,
                seconds % 60,
                sym_per_min,
                errors,
                errors_prcnt);
    }
    free(str);
    fclose(out);
    return att_num;
}
