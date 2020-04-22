#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SYMBOL_COUNT 3072

int texts_end(char* str) {
    if ((str[0] == '&') && (str[1] == '&')) {
        return 1;
    }
    return 0;
}

int texts_get_count() {
    FILE* texts_file;
    char* str;
    int texts_count = 0;
    texts_file = fopen("RU/texts.txt", "r");
    if (texts_file == NULL) {
        return -1;
    }
    str = malloc(MAX_SYMBOL_COUNT * sizeof(char));
    if (str == NULL) {
        return -1;
    }
    while (fgets(str, MAX_SYMBOL_COUNT, texts_file) != NULL) {
        if (texts_end(str)) {
            texts_count++;
        }
    }
    return texts_count;
}

char** texts_get() {
    //Инициализация переменных
    FILE* texts_file;  //Для работы с файлом
    char* str;         //Для считывания строк
    int text_number;   //Номер текста
    fpos_t pos;  //Для того, чтобы запомнить позицию в файле
    int newline_count;  //Количество переходов на новую строку
    char** text_out;  //Хранит текст под номером text_number

    //Объявление переменных
    texts_file = fopen("RU/texts.txt", "r");  //Открытие файла
    if (texts_file == NULL) {  //Проверка, открылся ли файл
        return NULL;
    }
    str = malloc(MAX_SYMBOL_COUNT *
                 sizeof(char));  //выделение памяти для хранения строк
    if (str == NULL) {  //Выделилась ли память
        return NULL;
    }
    srand(time(NULL));  //Случайный сид
    text_number =
        3;  // rand() % texts_get_count();  //Открытия случайного текста
    newline_count = 0;  //Обнуление счетчика переходов на новую строку

    //Поиск нужного текста
    while (text_number) {
        fgets(str, MAX_SYMBOL_COUNT, texts_file);
        if (texts_end(str)) {
            text_number--;
        }
    }

    //Подсчет количества переходов на новую строку
    fgetpos(texts_file, &pos);
    do {
        newline_count++;
        fgets(str, MAX_SYMBOL_COUNT, texts_file);
    } while (!texts_end(str));
    fsetpos(texts_file, &pos);

    //Выделения памяти. Каждому абзацу своя переменная.
    text_out = (char**)malloc(newline_count * sizeof(char*));
    if (text_out == NULL) {
        return NULL;
    }

    //Считывание текста в память
    for (int i = 0; i < newline_count; i++) {
        text_out[i] = malloc(MAX_SYMBOL_COUNT * sizeof(char));
        fgets(text_out[i], MAX_SYMBOL_COUNT, texts_file);
    }

    //освобождение
    free(str);
    fclose(texts_file);

    //Возвращаем указатель на наш текст
    return text_out;
}

void texts_print(char** text) {
    for (int i = 0; !texts_end(text[i]); i++) {
        for (char* j = text[i]; *j != '\0'; j++) {
            printf("%c", *j);
        }
    }
}

void texts_read(char** text) {
    char c;
    int errors = 0;
    int sym_count = 0;
    int seconds = time(NULL);
    for (int i = 0; !texts_end(text[i]); i++) {
        for (char* j = text[i]; *j != '\0'; j++) {
            sym_count++;
            c = getchar();
            if (c != *j) {
                errors++;
            }
        }
    }
    seconds = time(NULL) - seconds;
    int minuts = seconds / 60;
    int sym_per_min = 0;
    if (seconds > 0) {
        sym_per_min = sym_count * 60 / seconds;
        seconds %= 60;
    }
    double errors_prcnt = errors * 100 / sym_count;
    printf("%5d|%02d:%02d|%5d|%5d|%4.1f%%\n", 1, minuts, seconds, sym_per_min,
           errors, errors_prcnt);
}

int main() {
    //Проверка работоспособности
    char** text;
    text = texts_get();
    texts_print(text);
    texts_read(text);
    return 0;
}
