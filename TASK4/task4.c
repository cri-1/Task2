#include <stdlib.h>
#include <math.h>
#include "header4.h"

long long cmmdc(long long x,long long y) {
    long long temp;
    while(y!=0){
        temp=x%y;
        x=y;
        y=temp;
    }
    return x;
}

fractie creeazafr(long long x,long long y) {
    fractie f;
    if(x==0){
        f.numarator=0;
        f.numitor=1;
        return f;
    }
    long long div =cmmdc(x,y);
    f.numarator = x/div;
    f.numitor = y/div;
    return f;
}
fractie adunare(fractie x,fractie y) {
    if (x.numarator==0)
    return y;
    if(y.numarator==0) 
    return x;
    long long new_numa =x.numarator*y.numitor+y.numarator*x.numitor;
    long long new_numi=x.numitor*y.numitor;
    return creeazafr(new_numa,new_numi);
}

fractie inmultire(fractie x,fractie y) {
    if (x.numarator==0||y.numarator==0) return creeazafr(0,1);
    long long new_numa=x.numarator*y.numarator;
    long long new_numi=x.numitor*y.numitor;
    return creeazafr(new_numa,new_numi);
}

void afisare(FILE *f2,fractie frac,int ultimul) {
    if (frac.numarator==0) 
    {
        fprintf(f2,"0");
    } 
    else if (frac.numitor==1){
        fprintf(f2,"%lld", frac.numarator);
    } 
    else {
        fprintf(f2,"%lld/%lld",frac.numarator,frac.numitor);
    }
    if (!ultimul){
        fprintf(f2,"\n");
    }
}

int interval(double pret,double delta,int *valori_x,int *nr_noduri) {
    int val=(int)floor(pret/delta);
    for (int x=0;x<*nr_noduri;x++) {
        if (valori_x[x]==val) {
            return x; 
        }
    }
    valori_x[*nr_noduri]=val;
    (*nr_noduri)++;
    return (*nr_noduri)-1;
}