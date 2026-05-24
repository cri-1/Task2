#include <stdlib.h>
#include <string.h>
#include "header2.h"

void push(S* s, double x) {
    N* n = malloc(sizeof(N));
    if (!n) return;
    n->v = x;
    n->next = s->top;
    s->top = n;
}

double pop(S* s) {
    if (!s->top) return -1;
    N* t = s->top;
    double v = t->v;
    s->top = t->next;
    free(t);
    return v;
}

void add(R** h, R** t, int z, double d, const char* n) {
    R* r = malloc(sizeof(R));
    if (!r) return;
    r->z = z;
    r->d = d;
    strncpy(r->n, n, 49);
    r->n[49] = '\0';
    r->next = 0;
    
    if (!*t) {
        *h = *t = r;
    } else {
        (*t)->next = r;
        *t = r;
    }
}