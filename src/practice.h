#ifndef PRACTICE_H
#define PRACTICE_H

#define PRACTICE_COUNT 30

void practice_check();

int char_to_int(char* str, char dec);

int practice();

int practice_print(int num);

int practice_done(
        int num, int seconds, int sym_per_min, int errors, double errors_prcnt);
#endif
