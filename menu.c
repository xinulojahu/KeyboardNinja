#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
//#include "practice.h"
//#include "texts.h"
#include <locale.h>

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
    char str[100]; //Входной поток данных
    char choice; //Переменная для свича
    char sep[10] = " "; //Значение передаваемое в strtok
    char *istr; //Тот же же strtok
    char *istr1; //Все еще strtok
    char istr2[100]; //Вы угадали, это все что я умею :/
    int arg = 0; //Интовый аргумент посылаемый в функцию
    int argtest = 0; //Переменная для аргумента
    do {
        //fgets(str, 100, stdin);
        gets(str);
        strncpy(istr2, str, 20);
        istr1 = strtok(istr2, sep);
        
        printf("Your choice it's; %s\n", istr1); 
        istr = strtok(str, sep);
        
        while (istr != NULL) {            
            istr = strtok (NULL, sep);
            break;
        }
        //printf("Argument it's %s\n", istr);
        if (strcmp(istr1, "test") == 0) {
            choice = '1';
            printf("1\n");
        }
        else if (strcmp(istr1, "practice") == 0) {
            if ((istr != NULL) && (isnumber(istr) == 0)) { 
                argtest = atoi(istr);
                if ((argtest >= 1) && (argtest <= 20)) {
                    arg = argtest;
                    printf("Argument it's; %d\n", arg);
                } else {
                    printf("Invalid argument!\n");
                }
                
            }
            choice = '2';
            printf("2\n");
        }
        else if (strcmp(istr1, "practice_best") == 0) {
            choice = '3';
            printf("3\n");
        }
        else if (strcmp(istr1, "language") == 0) {
            choice = '4';
             if (istr != NULL) {                
                    if (strcmp(istr, "EN") == 0) {
                        arg = 1;
                    }
                    else if (strcmp(istr, "RU") == 0) {
                        arg = 2;
                    }
                    else {
                        arg = 0;
                    }
                printf("Argument it's; %d\n", arg);  
                }
            printf("4\n");
        }
        else if (strcmp(istr1, "stats") == 0) {
            if ((istr != NULL) && (isnumber(istr) == 0)) { 
                argtest = atoi(istr);
                if ((argtest >= 1) && (argtest <= 100)) {
                    arg = argtest;
                    printf("Argument it's; %d\n", arg);
                } else {
                    printf("Invalid argument!\n");
                    arg = 9;
                }
            }
            choice = '5';
            printf("5\n");
        }
        else if (strcmp(istr1, "stats_export") == 0) {
            choice = '6';
            printf("6\n");
        }
        else if (strcmp(istr1, "stats_delete") == 0) {
            choice = '7';
            printf("7\n");
        }
        else if (strcmp(istr1, "quit") == 0) {
            choice = '8';
            printf("8\n");
        }
        else {
            printf("Incorrent input!\n");
        }
        setlocale(LC_ALL, "");
        wchar_t** text;
        
        if (isdigit(choice)) {
            switch (choice) {
            case '1':
                //text = texts_get(0);
                //texts_print(text);
                // texts_read(text);
                 printf("a\n");
                break;
            case '2':
                //text = texts_get(practice());
                //texts_print(text);
                //texts_read(text);
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
int isnumber(char* buf){
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
int main() {
    menu_display();
    menu();
    return 0;
}

