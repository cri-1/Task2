#include <stdio.h>
#include <stdlib.h>
#include "header4.h"

    int valori[1000];
    int a[1000][1000]={0};
    int iesiri[1000]={0};
    fractie probabil[1000][1000];
    fractie probabilprezent[1000];
    fractie probabilviitor[1000];

int main(int argc,char** argv) {
    if (argc<3){
        return 1;
    }
    FILE *f1= fopen(argv[1],"r");
    FILE *f2= fopen(argv[2],"w"); 
   
    int n,k, nr_noduri=0;
    double d,p_start, p_target;

    fscanf(f1,"%d",&n);
    fscanf(f1,"%lf",&d);
    fscanf(f1,"%d",&k);
    fscanf(f1,"%lf",&p_start);
    fscanf(f1,"%lf",&p_target);

    int start=interval(p_start,d,valori,&nr_noduri);
    int target=interval(p_target, d,valori,&nr_noduri);

    if (n>0){
        double pretvechi,pretnou;
        fscanf(f1,"%lf",&pretvechi);
        int vechi=interval(pretvechi, d,valori, &nr_noduri);
        
        for (int x=1;x<n; x++) {
            fscanf(f1,"%lf",&pretnou);
            int nou = interval(pretnou, d,valori,&nr_noduri);
            
            a[vechi][nou]++;
            iesiri[vechi]++;
            
            vechi = nou;
        }
    }

    for (int x = 0; x<nr_noduri; x++){
        for (int y = 0; y < nr_noduri; y++){
            if (a[x][y]>0){
                probabil[x][y]=creeazafr(a[x][y],iesiri[x]);
            } else {
                probabil[x][y]=creeazafr(0,1);
            }
        }
    }

    for (int x=0;x<nr_noduri;x++) {
        probabilprezent[x]=creeazafr(0,1);
    }
    probabilprezent[start]=creeazafr(1, 1);

    for (int k_zi=0;k_zi<k;k_zi++) {
        
        int ultimul=(k_zi==k-1);
        afisare(f2, probabilprezent[target], ultimul);

        for (int x=0;x<nr_noduri;x++) {
            probabilviitor[x]=creeazafr(0, 1);
        }

        for (int x =0; x <nr_noduri;x++) {
            if (probabilprezent[x].numarator>0) { 
                for (int y=0; y<nr_noduri;y++) {
                    if (probabil[x][y].numarator>0) {
                        fractie p = inmultire(probabilprezent[x], probabil[x][y]);
                        probabilviitor[y] = adunare(probabilviitor[y],p);
                    }
                }
            }
        }

        for (int x=0;x<nr_noduri;x++) {
            probabilprezent[x]=probabilviitor[x];
        }
    }

    fclose(f1);
    fclose(f2);
    
    return 0;
}