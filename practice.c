#include <stdio.h>
#include <stdlib.h>
int practice();

int practice() {
    FILE* practice_texts;
    char* str;
    practice_texts = fopen("RU/texts.txt", "r");
    if (practice_texts == NULL) {
        printf("Error with opening file");
        return -1;
    }

    str = malloc(300 * sizeof(int));
    while (!feof(practice_texts)) {
        fgets(str, 300, practice_texts);
        printf("%s", str);
    }
    fclose(practice_texts);

    return 0;
}

int main() {
    practice();
    return 0;
}
