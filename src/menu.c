#include "language.h"
#include "practice.h"
#include "stats.h"
#include "texts.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

//Функция для вывода главного меню
void menu_display()
{
    printf(" _____ _____ _____ _____ _____ _____ _____ _____ __________ ");
    printf("_____ _____ _____ _____ _____ \n");
    printf("|| K ||| e ||| y ||| b ||| o ||| a ||| r ||| d |||        ");
    printf("||| N ||| i ||| n ||| j ||| a ||\n");
    printf("||___|||___|||___|||___|||___|||___|||___|||___||");
    printf("|________|||___|||___|||___|||___|||___||\n");
    printf("|/___\\|/___\\|/___\\|/___\\|/___\\|/___\\|/___\\|/___\\|/");
    printf("________\\|/___\\|/___\\|/___\\|/___\\|/___\\|\n");
    printf("\n");
    printf("\t\t\t\t     Print any option\n");
    printf("\t\t\t\t     on your keyboard");
    printf("\n");
    printf("\t\t    ________ \t\t\t                 _________ \n");
    printf("\t\t   || test ||\t\t\t                || stats || \n");
    printf("\t\t   ||______||\t\t\t                ||_______||\n");
    printf("\t\t   |/______\\|\t\t\t                |/_______\\| \n");
    printf("\t\t    ____________\t\t\t\t ________________\n");
    printf("\t\t   || practice ||\t\t\t        || stats_export ||\n");
    printf("\t\t   ||__________||\t\t\t\t||______________|| \n");
    printf("\t\t   |/__________\\|\t\t\t\t|/______________\\|\n");
    printf("\t\t    _________________\t\t\t\t ________________\n");
    printf("\t\t   || practice_best ||\t\t\t        || stats_delete ||\n");
    printf("\t\t   ||_______________||\t\t\t\t||______________||\n");
    printf("\t\t   |/_______________\\|\t\t\t\t|/______________\\|\n");
    printf("\t\t    ____________\t\t\t\t ________\n");
    printf("\t\t   || language ||\t\t\t        || quit ||\n");
    printf("\t\t   ||__________||\t\t\t\t||______||\n");
    printf("\t\t   |/__________\\|\t\t\t\t|/______\\|\n");
    printf("\n");
}

//Самописная функция для проверки числа в строке
int isnumber(char* buf)
{
    char* cur = buf;
    while (*cur != '\0') {
        if (isdigit(*cur) == 0) {
            return -1;
        }
        cur++;
    }
    return 0;
}

void menu(void)
{
    practice_check();
    char language[3];
    get_language(language);
    char str[100];      //Входной поток данных
    char choice = 0;    //Переменная для свича
    char sep[10] = " "; //Значение передаваемое в strtok
    char* istr;         //Тот же же strtok
    char* istr1;        //Все еще strtok
    char istr2[100]; //Вы угадали, это все что я умею :/
    int arg = 0; //Интовый аргумент посылаемый в функцию
    int argtest = 0; //Переменная для аргумента
    do {
        fgets(str, 100, stdin); //Считываем строку
        str[strlen(str) - 1] = '\0';
        strncpy(istr2, str, 20); //Копируем содержимое str в str2
        istr1 = strtok(istr2, sep); //Вычленяем комманду из строки

        printf("Ваш выбор: %s\n", istr1); //Вспомогательная строка
        istr = strtok(str, sep); //Выделение первой части строки

        //Цикл для выделения следующей части (аргумента)
        while (istr != NULL) {
            istr = strtok(NULL, sep);
            break;
        }
        //Сравнение содержимого строки с командой
        if (strcmp(istr1, "test") == 0) {
            choice = '1'; //Присвоение соответствующего выбора для свичкейса
        }
        //Сравнение содержимого строки с командой
        else if (strcmp(istr1, "practice") == 0) {
            arg = practice();
            if ((istr != NULL) && (isnumber(istr) == 0)) {
                argtest = atoi(istr); //Вспомогательная переменная для аргумента
                if ((argtest >= 1)
                    && (argtest <= PRACTICE_COUNT)) { //Условие на аргумент
                    arg = argtest; //Конечный аргумент
                } else {
                    printf("Неверный аргумент!\n"); //Неверный аргумент
                }
            }
            choice = '2'; //Присвоение соответствующего выбора для свичкейса
        }
        //Сравнение содержимого строки с командой
        else if (strcmp(istr1, "practice_best") == 0) {
            choice = '3';  //Для свичкейса
        }
        //Сравнение содержимого строки с командой
        else if (strcmp(istr1, "language") == 0) {
            choice = '4'; //Нинтендо свич
            //Сравнение строки с аргументами
            if (istr != NULL) {
                if (strcmp(istr, "EN") == 0) {
                    if (strcmp(istr, language) != 0) {
                        arg = 1;
                    }
                } else if (strcmp(istr, "RU") == 0) {
                    if (strcmp(istr, language) != 0) {
                        arg = 1;
                    }
                } else {
                    arg = 0; //Это тоже оно
                }
            }          
        }
        //Сравнение содержимого строки с командой
        else if (strcmp(istr1, "stats") == 0) {
            arg = 9; //Дефолтное значение аргумента из ТЗ
            if ((istr != NULL) && (isnumber(istr) == 0)) {
                argtest = atoi(istr); //Перевод аргумента из строки в int
                if ((argtest >= 1) && (argtest <= 100)) {
                    arg = argtest; //Присвоение аргумента
                } else {
                    printf("Неверный аргумент!\n");
                }
            }
            choice = '5';  //Свичкейс
            //Сравнение содержимого строки с командой
        } else if (strcmp(istr1, "stats_export") == 0) {
            choice = '6';  //Я усталб((9(
            //Сравнение содержимого строки с командой
        } else if (strcmp(istr1, "stats_delete") == 0) {
            choice = '7';  //Свичкейс
            //Сравнение содержимого строки с командой
        } else if (strcmp(istr1, "quit") == 0) {
            choice = '8';  //Свичкейс
            //Если введенной команды не сущесвтует
        } else {
            printf("Некорректный ввод!\n");
        }
        setlocale(LC_ALL, "");
        wchar_t** text;
        int text_num = 0;
        if (isdigit(choice)) {
            switch (choice) {
            case '2':
                text_num = arg;
            case '1':
                text = texts_get(text_num);
                texts_print(text);
                texts_read(text, text_num);
                texts_free(text);
                break;
            case '3':
                printf("NUM: ATT| TIME| SPM|ERR|ERRATE\n");
                for (int i = 1; i <= PRACTICE_COUNT; i++) {
                    printf("%2d : ", i);
                    practice_print(i);
                }
                break;
            case '4':
                if (arg == 1) {
                    change_language(language);
                }
                printf("Выбранный язык: %s\n", language);
                break;
            case '5':
                stats(arg + 1);
                break;
            case '6':
                stats_export();
                break;
            case '7':
                stats_delete();
                printf("Данные были удалены\n");
                break;
            case '8':
                exit(0);
            default:
                printf("Неккоректный ввод. Попробуйте снова!\n");
                break;
            }
        } else {
            printf("Попробуйте снова!\n");
        }
    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4'
             && choice != '5' && choice != '6' && choice != '7');
    printf("\nНажмите Enter чтобы продолжить\n");
    getchar();
}
