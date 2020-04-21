#include <stdio.h>
#include <stdlib.h>
char practice();

char practice() {
    FILE* practice_texts;
    char* str;
    int try_count = 0;
    practice_texts = fopen("RU/texts.txt", "r");

    str = malloc(30 * sizeof(char));
    fgets(str, 30, practice_texts);
    for (int i = 23; i < 300; i = i + 23) {
        // предположительно необходимое число попыток
        // будет каждые 23 символа
        if (str[i] == try_count) {
            printf("Oh hi there!\n");
            return str[i - 3];
            // а номер текста будет на 3 символа меньше
        } else
            i = i + 23;
        // в случае любого количества попыток
        // отличного от нуля
        // продолжаем цикл
    }
    // если цикл завершился и не вывел return
    // то повышаем необходимое количество попыток на вывод на 1
    try_count++;
    practice();

    return -1;
}

int main() {
    practice();
    return 0;
}
