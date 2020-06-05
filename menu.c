#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
//#include "practice.h"
//#include "texts.h"
#include <locale.h>
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
    printf("\t\t1) || test ||\t\t\t             5) || stats || \n");
    printf("\t\t   ||______||\t\t\t                ||_______||\n");
    printf("\t\t   |/______\\|\t\t\t                |/_______\\| \n");
    printf("\t\t    ____________\t\t\t\t ________________\n");
    printf("\t\t2) || practice ||\t\t\t     6) || stats_export ||\n");
    printf("\t\t   ||__________||\t\t\t\t||______________|| \n");
    printf("\t\t   |/__________\\|\t\t\t\t|/______________\\|\n");
    printf("\t\t    _________________\t\t\t\t ________________\n");
    printf("\t\t3) || practice_best ||\t\t\t     7) || stats_delete ||\n");
    printf("\t\t   ||_______________||\t\t\t\t||______________||\n");
    printf("\t\t   |/_______________\\|\t\t\t\t|/______________\\|\n");
    printf("\t\t    ____________\t\t\t\t ________\n");
    printf("\t\t4) || language ||\t\t\t     8) || quit ||\n");
    printf("\t\t   ||__________||\t\t\t\t||______||\n");
    printf("\t\t   |/__________\\|\t\t\t\t|/______\\|\n");
    printf("\n");
}

void menu(void)
{
    char str[100];      //Входной поток данных
    char choice;        //Переменная для свича
    char sep[10] = " "; //Значение передаваемое в strtok
    char* istr;         //Тот же же strtok
    char* istr1;        //Все еще strtok
    char istr2[100]; //Вы угадали, это все что я умею :/
    int arg = 0; //Интовый аргумент посылаемый в функцию
    int argtest = 0; //Переменная для аргумента
    do {
        // fgets(str, 100, stdin);
        gets(str);               //Считываем строку
        strncpy(istr2, str, 20); //Копируем содержимое str в str2
        istr1 = strtok(istr2, sep); //Вычленяем комманду из строки

        printf("Your choice it's; %s\n", istr1); //Вспомогательная строка
        istr = strtok(str, sep); //Выделение первой части строки

        //Цикл для выделения следующей части (аргумента)
        while (istr != NULL) {
            istr = strtok(NULL, sep);
            break;
        }
        // printf("Argument it's %s\n", istr);
        //Сравнение содержимого строки с командой
        if (strcmp(istr1, "test") == 0) {
            choice = '1'; //Присвоение соответствующего выбора для свичкейса
            printf("1\n"); //Вспомогательная строка
        }
        //Сравнение содержимого строки с командой
        else if (strcmp(istr1, "practice") == 0) {
            if ((istr != NULL) && (isnumber(istr) == 0)) {
                argtest = atoi(istr); //Вспомогательная переменная для аргумента
                if ((argtest >= 1) && (argtest <= 20)) { //Условие на аргумент
                    arg = argtest; //Конечный аргумент
                    printf("Argument it's; %d\n", arg); //Вспомогательная строка
                } else {
                    printf("Invalid argument!\n"); //Неверный аргумент
                }
            }
            choice = '2'; //Присвоение соответствующего выбора для свичкейса
            printf("2\n"); //Вспомогательная строка
        }
        //Сравнение содержимого строки с командой
        else if (strcmp(istr1, "practice_best") == 0) {
            choice = '3';  //Для свичкейса
            printf("3\n"); //Вспомогательная строка
        }
        //Сравнение содержимого строки с командой
        else if (strcmp(istr1, "language") == 0) {
            choice = '4'; //Нинтендо свич
            //Сравнение строки с аргументами
            if (istr != NULL) {
                if (strcmp(istr, "EN") == 0) {
                    arg = 1; //Присвоение
                } else if (strcmp(istr, "RU") == 0) {
                    arg = 2; //Аргумента
                } else {
                    arg = 0; //Это тоже оно
                }
                printf("Argument it's; %d\n", arg); //Вспомогательная строка
            }
            printf("4\n"); //Вспомогательная строка
        }
        //Сравнение содержимого строки с командой
        else if (strcmp(istr1, "stats") == 0) {
            if ((istr != NULL) && (isnumber(istr) == 0)) {
                argtest = atoi(istr); //Перевод аргумента из строки в int
                if ((argtest >= 1) && (argtest <= 100)) {
                    arg = argtest; //Присвоение аргумента
                    printf("Argument it's; %d\n", arg); //Вспомогательная строка
                } else {
                    printf("Invalid argument!\n");
                    arg = 9; //Дефолтное значение аргумента из ТЗ
                }
            }
            choice = '5';  //Свичкейс
            printf("5\n"); //Вспомогательная строка
            //Сравнение содержимого строки с командой
        } else if (strcmp(istr1, "stats_export") == 0) {
            choice = '6';  //Я усталб((9(
            printf("6\n"); //Вспомогательная строка
            //Сравнение содержимого строки с командой
        } else if (strcmp(istr1, "stats_delete") == 0) {
            choice = '7';  //Свичкейс
            printf("7\n"); //Вспомогательная строка
            //Сравнение содержимого строки с командой
        } else if (strcmp(istr1, "quit") == 0) {
            choice = '8';  //Свичкейс
            printf("8\n"); //Вспомогательная строка
            //Если введенной команды не сущесвтует
        } else {
            printf("Incorrent input!\n");
        }
        setlocale(LC_ALL, "");
        wchar_t** text;
        //Свичкейс нужно комментить?
        if (isdigit(choice)) {
            switch (choice) {
            case '1':
                // text = texts_get(0);
                // texts_print(text);
                // texts_read(text);
                printf("a\n");
                break;
            case '2':
                // text = texts_get(practice());
                // texts_print(text);
                // texts_read(text);
                printf("b\n");
                break;
            case '3':
                // practice_best();
                printf("c\n");
                break;
            case '4':
                // language();
                printf("d\n");
                break;
            case '5':
                // stats();
                printf("f\n");
                break;
            case '6':
                // stats_exp();
                printf("g\n");
                break;
            case '7':
                // stats_del();
                printf("h\n");
                break;
            case '8':
                exit(0);
            default:
                printf("Incorrect input. Please, try again!\n");
                break;
            }
        } else {
            printf("Try again!\n");
        }

    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4'
             && choice != '5' && choice != '6' && choice != '7');
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
//Функция для тестирования файла
int main()
{
    menu_display();
    menu();
    return 0;
}

