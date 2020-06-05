#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOL_COUNT 1024

void practice_done(int, int, int, float);

int attempt_number(char* str, int i, int j, int k) {
    int a;
    int b = str[j];
    int c = str[k];
    a = str[i] - '0';
    if (b != '|') {
        b = str[j] - '0';
        a *= 10;
        b += a;
        a = b;
        if (c != '|') {
            c = str[k] - '0';
            a *= 10;
            c += a;
            a = c;
        }
    }
    return a;
}

int symbols_per_min(char* str) {
    int a = str[10] - '0';
    int b = str[11];
    int c = str[12];
    int d = str[13];
    if (b != '|') {
        b = str[11] - '0';
        a *= 10;
        b += a;
        a = b;
        if (c != '|') {
            c = str[12] - '0';
            a *= 10;
            c += a;
            a = c;
            if (d != '|') {
                d = str[13] - '0';
                a *= 10;
                d += a;
                a = d;
            }
        }
    }
    return a;
}

void practice_done(int seconds, int sym_per_min, int errors,
                   float errors_prcnt) {
    char* str;
    int temp;
    int att_num;
    FILE* out = fopen("RU/practice_done.txt", "r+t");
    fpos_t pos;
    str = malloc(152 * sizeof(char));
    fgetpos(out, &pos);
    fgets(str, 150, out);
    temp = attempt_number(str, 0, 1, 2);
    temp = symbols_per_min(str);
    if (temp < sym_per_min) {
        att_num = attempt_number(str, 0, 1, 2);
        att_num++;
        fsetpos(out, &pos);
        fprintf(out, "%03d|%02d:%02d|%04d|%03d|%05.1f%%\n", att_num,
                seconds / 60, seconds % 60, sym_per_min, errors, errors_prcnt);
    }
    fclose(out);
    printf("Writing complete!\n");
}
