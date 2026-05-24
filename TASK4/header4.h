#ifndef MARKOV_H
#define MARKOV_H

#include <stdio.h>
typedef struct {
    long long numarator;
    long long numitor;
} fractie;

long long cmmdc(long long x, long long y);
fractie creeazafr(long long x, long long y);
fractie adunare(fractie x, fractie y);
fractie inmultire(fractie x, fractie y);
void afisare(FILE *f2,fractie frac,int ultimul);
int interval(double pret, double delta,int *valori_x,int *nr_noduri);
#endif