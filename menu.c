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
    char str[100];
    char str1[100];
    char str2[100];
    char str3[100];
    char str4[100];
    char str5[100];
    char str6[100];
    char str7[100];
    char str8[100];
    str1[100] = "test";
    str2[100] = "practice";
    str3[100] = "practice_best";
    str4[100] = "language";
    str5[100] = "stats";
    str6[100] = "stats_export";
    str7[100] = "stats_delete";
    str8[100] = "quit";
    char choice;
    do {
        //fgets(str, 100, stdin);
        gets(str);
        if (strcmp(str, str1)) {
            choice = 1;
            printf("1\n");
        }
        if (strcmp(str, str2)) {
            choice = 2;
            printf("2\n");
        }
        if (strcmp(str, str3)) {
            choice = 3;
            printf("3\n");
        }
        if (strcmp(str, str4)) {
            choice = 4;
            printf("4\n");
        }
        if (strcmp(str, str5)) {
            choice = 5;
            printf("5\n");
        }
        if (strcmp(str, str6)) {
            choice = 6;
            printf("6\n");
        }
        if (strcmp(str, str7)) {
            choice = 7;
            printf("7\n");
        }
        if (strcmp(str, str8)) {
            choice = 8;
            printf("8\n");
        }
        else {
            printf("Incorrent input. Please, try again!\n");
        }
        setlocale(LC_ALL, "");
        wchar_t** text;
        if (isdigit(choice)) {
            switch (choice) {
            case '1':
                //text = texts_get(0);
              //  texts_print(text);
               // texts_read(text);
                 printf("a\n");
                break;
            case '2':
                //text = texts_get(practice());
                //texts_print(text);
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
            printf("Incorrect input. Try again!\n");
        }

    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4'
             && choice != '5' && choice != '6' && choice != '7');
}


int main() {
    menu_display();
    menu();
    return 0;
}

