#include "language.h"
#include "practice.h"
#include "stats.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <wchar.h>

#define MAX_SYMBOL_COUNT 1024
#define PRACTICE_COUNT 30

static struct termios stored_settings;

void set_keypress(void)
{
    struct termios new_settings;

    tcgetattr(0, &stored_settings);

    new_settings = stored_settings;

    new_settings.c_lflag &= (~ICANON);
    new_settings.c_lflag &= (~ECHO);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;

    tcsetattr(0, TCSANOW, &new_settings);
    return;
}

void reset_keypress(void)
{
    tcsetattr(0, TCSANOW, &stored_settings);
    return;
}

int texts_end(wchar_t* str)
{
    if ((str[0] == '&') && (str[1] == '&')) {
        return 1;
    }
    return 0;
}
int texts_get_count()
{
    wchar_t* str;

    int texts_count = 0;
    FILE* texts_file = openfile("texts.txt", "r");
    if (texts_file == NULL) {
        return -1;
    }

    str = malloc(MAX_SYMBOL_COUNT * sizeof(wchar_t));
    if (str == NULL) {
        return -1;
    }
    while (fgetws(str, MAX_SYMBOL_COUNT, texts_file) != NULL) {
        if (texts_end(str)) {
            texts_count++;
        }
    }
    free(str);
    return texts_count;
}

wchar_t** texts_get(unsigned int text_src)
{
    //Инициализация переменных
    wchar_t* str;    //Для считывания строк
    int text_number; //Номер текста
    fpos_t pos; //Для того, чтобы запомнить позицию в файле
    int newline_count; //Количество переходов на новую строку
    wchar_t** text_out; //Хранит текст под номером text_number
    FILE* texts_file;
    str = malloc(
            MAX_SYMBOL_COUNT
            * sizeof(wchar_t)); //выделение памяти для хранения строк
    if (str == NULL) { //Выделилась ли память
        return NULL;
    }

    if (text_src == 0) {
        texts_file = openfile("texts.txt", "r");
        if (texts_file == NULL) {
            return NULL;
        }
        srand(time(NULL));                        //Случайный сид
        text_number = rand() % texts_get_count(); //Открытия случайного текста

        //Поиск нужного текста
        while (text_number) {
            fgetws(str, MAX_SYMBOL_COUNT, texts_file);
            if (texts_end(str)) {
                text_number--;
            }
        }
    } else if (text_src < PRACTICE_COUNT) {
        char* file_name = malloc(32 * sizeof(char));
        sprintf(file_name, "practice/practice_%d.txt", text_src);
        texts_file = openfile(file_name, "r");
        free(file_name);
        if (texts_file == NULL) {
            return NULL;
        }
        if (texts_file == NULL) { //Проверка, открылся ли файл
            return NULL;
        }
    } else {
        return NULL;
    }
    newline_count = 0; //Обнуление счетчика переходов на новую строку

    //Подсчет количества переходов на новую строку
    fgetpos(texts_file, &pos);
    do {
        newline_count++;
        fgetws(str, MAX_SYMBOL_COUNT, texts_file);
    } while (!texts_end(str));
    fsetpos(texts_file, &pos);

    //Выделения памяти. Каждому абзацу своя переменная.
    text_out = (wchar_t**)malloc(newline_count * sizeof(wchar_t*));
    if (text_out == NULL) {
        return NULL;
    }

    //Считывание текста в память
    for (int i = 0; i < newline_count; i++) {
        text_out[i] = malloc(MAX_SYMBOL_COUNT * sizeof(wchar_t));
        fgetws(text_out[i], MAX_SYMBOL_COUNT, texts_file);
    }

    //освобождение
    free(str);
    fclose(texts_file);

    //Возвращаем указатель на наш текст
    return text_out;
}

void texts_print(wchar_t** text)
{
    for (int i = 0; !texts_end(text[i]); i++) {
        for (wchar_t* j = text[i]; *j != '\0'; j++) {
            printf("%lc", *j);
        }
    }
    printf("\n");
}

int texts_read(wchar_t** text, unsigned int text_src)
{
    wchar_t c;
    int errors = 0;
    int sym_count = 0;
    int seconds = time(NULL);
    set_keypress();
    for (int i = 0; !texts_end(text[i]); i++) {
        for (wchar_t* j = text[i]; *j != '\0'; j++) {
            sym_count++;
            scanf("%C", &c);
            if (c != *j) {
                errors++;
                do {
                    scanf("%C", &c);
                } while (c != *j);
            }
            printf("%lc", c);
        }
    }
    reset_keypress();
    seconds = time(NULL) - seconds;
    double errors_prcnt = 100 - errors * 100 / sym_count;
    int sym_per_min = 0;
    int num;
    if (seconds > 0) {
        sym_per_min = sym_count * 60 / seconds;
    }
    printf("\nRSLTS ATT| TIME| SPM|ERR|ERRATE\nBEST: ");
    if (text_src == 0) {
        stats(1);
        num = stats_fprint(seconds, sym_per_min, errors, errors_prcnt);
    } else if (text_src < PRACTICE_COUNT) {
        practice_print(text_src);
        num = practice_done(
                text_src, seconds, sym_per_min, errors, errors_prcnt);
    } else {
        return -1;
    }
    printf("CUR:  %03d|%02d:%02d|%04d|%03d|%05.1f%%\n",
           num,
           seconds / 60,
           seconds % 60,
           sym_per_min,
           errors,
           errors_prcnt);
    return 0;
}
