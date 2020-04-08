#include <stdio.h>
#include <stdlib.h>
void menu(void)
{
    int choice;
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            // test();
            printf("a\n");
            break;
        case 2:
            printf("b\n");
            // practice(0);
            break;
        case 3:
            // practice_best();
            printf("c\n");
            break;
        case 4:
            // language();
            printf("d\n");
            break;
        case 5:
            // stats();
            printf("f\n");
            break;
        case 6:
            // stats_exp();
            printf("g\n");
            break;
        case 7:
            // stats_del();
            printf("h\n");
            break;
        case 8:
            exit(0);
        default:
            printf("Incorrect input. Try again!\n");
            break;
        }
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4
             && choice != 5 && choice != 6 && choice != 7);
}
//Принт букв для проверки работоспособности функции, при готовности функций
//буквы стереть.
