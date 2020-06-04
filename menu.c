#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include <locale.h>
#include "practice.h"
#include "stats.h"
#include "texts.h"

void menu_display() {
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

void menu(void) {
    char str[100];
    char choice;
    do {
        fgets(str, 100, stdin);
        choice = str[0];
        setlocale(LC_ALL, "");
        wchar_t** text;
        int text_num = 0;
        if (isdigit(choice)) {
            switch (choice) {
                case '2':
                    text_num = practice();
                case '1':
                    text = texts_get(text_num);
                    texts_print(text);
                    texts_read(text, text_num);
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
                    stats_export();
                    printf("Данные были экспортированы\n");
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

    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4' &&
             choice != '5' && choice != '6' && choice != '7');
}
//Принт букв для проверки работоспособности функции, при готовности функций
//буквы стереть

