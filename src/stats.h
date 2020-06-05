#ifndef STATS_H
#define STATS_H

int stats(int num);

int stats_fprint(
        int seconds, int sym_per_minuts, int errors, double errors_prcnt);
int stats_export();

int stats();

#endif
