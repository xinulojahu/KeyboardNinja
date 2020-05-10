#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <wchar.h>

#define MAX_SYMBOL_COUNT 1024
#define PRACTICE_COUNT 30

static struct termios stored_settings;

void set_keypress(void) {
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

void reset_keypress(void) {
    tcsetattr(0, TCSANOW, &stored_settings);
    return;
}

int texts_end(wchar_t* str) {
    if ((str[0] == '&') && (str[1] == '&')) {
        return 1;
    }
    return 0;
}

int texts_get_count() {
    FILE* texts_file;
    wchar_t* str;
    int texts_count = 0;
    texts_file = fopen("RU/texts.txt", "r");
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
    return texts_count;
}

wchar_t** texts_get(unsigned int text_src) {
    //Инициализация переменных
    FILE* texts_file;  //Для работы с файлом
    wchar_t* str;      //Для считывания строк
    int text_number;   //Номер текста
    fpos_t pos;  //Для того, чтобы запомнить позицию в файле
    int newline_count;  //Количество переходов на новую строку
    wchar_t** text_out;  //Хранит текст под номером text_number
    str = malloc(MAX_SYMBOL_COUNT *
                 sizeof(wchar_t));  //выделение памяти для хранения строк
    if (str == NULL) {  //Выделилась ли память
        return NULL;
    }

    if (text_src == 0) {
        texts_file = fopen("RU/texts.txt", "r");  //Открытие файла
        if (texts_file == NULL) {  //Проверка, открылся ли файл
            return NULL;
        }
        srand(time(NULL));                         //Случайный сид
        text_number = rand() % texts_get_count();  //Открытия случайного текста

        //Поиск нужного текста
        while (text_number) {
            fgetws(str, MAX_SYMBOL_COUNT, texts_file);
            if (texts_end(str)) {
                text_number--;
            }
        }
    } else if (text_src < PRACTICE_COUNT) {
        char* temp;
        temp = malloc(28 * sizeof(char));
        sprintf(temp, "%s%d%s", "RU/practice/practice_", text_src, ".txt");
        texts_file = fopen(temp, "r");
        if (texts_file == NULL) {  //Проверка, открылся ли файл
            return NULL;
        }
        free(temp);
    } else {
        return NULL;
    }
    newline_count = 0;  //Обнуление счетчика переходов на новую строку

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

void texts_print(wchar_t** text) {
    for (int i = 0; !texts_end(text[i]); i++) {
        for (wchar_t* j = text[i]; *j != '\0'; j++) {
            printf("%lc", *j);
        }
    }
    printf("\n");
}

void texts_read(wchar_t** text) {
    wchar_t c;
    int errors = 0;
    int sym_count = 0;
    int seconds = time(NULL);
    set_keypress();
    for (int i = 0; !texts_end(text[i]); i++) {
        for (wchar_t* j = text[i]; *j != '\0'; j++) {
            sym_count++;
            c = getwchar();
            if (c != *j) {
                errors++;
                do {
                    c = getwchar();
                } while (c != *j);
            }
            printf("%lc", c);
        }
    }
    reset_keypress();
    seconds = time(NULL) - seconds;
    int minuts = seconds / 60;
    int sym_per_min = 0;
    if (seconds > 0) {
        sym_per_min = sym_count * 60 / seconds;
        seconds %= 60;
    }
    double errors_prcnt = 100 - errors * 100 / sym_count;
    printf("%5d|%02d:%02d|%5d|%5d|%4.1f%%\n", 1, minuts, seconds, sym_per_min,
           errors, errors_prcnt);
}

int main() {
    //Проверка рабоint main()
    setlocale(LC_ALL, "");
    wchar_t** text;
    text = texts_get(1);
    texts_print(text);
    texts_read(text);
    return 0;
}
