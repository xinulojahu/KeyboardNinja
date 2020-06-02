#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// int practice();  //основная фукнция
// int char_to_int(char*, int, int);  // функция перевода числв char в число int

int char_to_int(char* str, int i, int j, int k) {
    int a;
    int b = str[j];
    int c = str[k];
    a = str[i] - '0';
    if (b != '|') {
        b = str[j] - '0';
        a *= 10;
        b += a;
        a = b;
        if (c != '|') {
            c = str[k] - '0';
            a *= 10;
            c += a;
            a = c;
        }
    }
    return a;
}

int practice() {
    FILE* practice_done;
    char* str;  // указатель на массив строк из файла
    int min;    // минимальное количество попыток
    int start_min;  // используется для финальной проверки
    int temp;  // переменная для записи количества попыток для сравнения
    int key = 1;  // переменная для запоминания номера текста
    int number_of_text = 0;  // переменная, в которой хранится
                             // необходимый номер текста
    practice_done = fopen("RU/practice_done.txt", "r");  // открываем файл
    if (practice_done == NULL) {  // проверка на открытие файла
        printf("Error with opening file");
        return -1;
    }

    str = malloc(152 * sizeof(char));  // выделяем динамическую память для str
    fgets(str, 150, practice_done);  // записываем в массив первую строку
    min = char_to_int(str, 0, 1, 2);  // запоминаем минимальным количеством
                                      // попыток количество в первом тексте
    start_min = min;  // присваеваем для дальнейшего сравнения

    for (int i = 1; !feof(practice_done); i++) {
        fgets(str, 150,
              practice_done);  //получаем строку (уже получаем вторую и так
                               //далее)
        if (i % 2 == 0) {  // если строка с количеством попыток
            temp =
                char_to_int(str, 0, 1, 2);  //то запоминаем эти попытки в temp
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
