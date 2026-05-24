#ifndef HEADER2_H
#define HEADER2_H

typedef struct N {
    double v;
    struct N* next;
} N;

typedef struct {
    N* top;
    char nume[50];
} S;

typedef struct R {
    int z;
    double d;
    char n[50];
    struct R* next;
} R;

void push(S* s, double x);
double pop(S* s);
void add(R** h, R** t, int z, double d, const char* n);

#endif