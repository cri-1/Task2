#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct N
{
    double v;
    struct N*next;
} N;
typedef struct
{
    N*top;
    char nume[50];
} S;
typedef struct R
{
    int z;
    double d;
    char n[50];
    struct R*next;
} R;

void push(S*s,double x)
{
    N*n=malloc(sizeof(N));
    if(!n)return;
    n->v=x;
    n->next=s->top;
    s->top=n;
}

double pop(S*s)
{
    if(!s->top)return -1;
    N*t=s->top;
    double v=t->v;
    s->top=t->next;
    free(t);
    return v;
}

void add(R**h,R**t,int z,double d,char*n)
{
    R*r=malloc(sizeof(R));
    if(!r)return;
    r->z=z;
    r->d=d;
    strcpy(r->n,n);
    r->next=0;
    if(!*t)*h=*t=r;
    else (*t)->next=r,*t=r;
}

int main(int c,char**v)
{
    if(c<3)return 1;
    FILE *fi=fopen(v[1],"r"),*fo=fopen(v[2],"w");
    if(!fi||!fo)return 1;

    S s[3]= {0};
    char line[128];
    int k=-1;

    while(fgets(line,128,fi))
    {
        line[strcspn(line,"\r\n")]=0;
        if (strlen(line)==0)
        {
            continue;
        }
        if(isdigit(line[0]))
        {
            if(k>=0&&k<3)push(&s[k],atof(line));
        }
        else
        {
            k++;
            if(k<3)strcpy(s[k].nume,line);
        }
    }

    R *h=0,*t=0;
    int z=1;

    while(s[0].top&&s[1].top&&s[2].top)
    {
        double a=pop(&s[0]),b=pop(&s[1]),c3=pop(&s[2]);
        if(a==b&&a!=c3)add(&h,&t,z,fabs(a-c3),s[2].nume);
        else if(a==c3&&a!=b)add(&h,&t,z,fabs(a-b),s[1].nume);
        else if(b==c3&&b!=a)add(&h,&t,z,fabs(b-a),s[0].nume);
        z++;
    }

    for(R*p=h; p;)
    {
        fprintf(fo,"ziua %d - %.2f - %s\n",p->z,p->d,p->n);
        R*q=p;
        p=p->next;
        free(q);
    }

    fclose(fi);
    fclose(fo);
    return 0;
}
