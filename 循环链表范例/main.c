#include <stdio.h>
#include <stdlib.h>
typedef struct node* link;
struct node{int item;link next;};
void main(int argc,char *argv[])
{
    int i,N=atoi(argv[1]),M=atoi(argv[2]);
    link t=malloc(sizeof *t),x=t;
    t->item=1;t->next=t;
    for(i=2;i<=N;i++)
    {
        x=(x->next=malloc(sizeof *x));
        x->item=i;x->next=t;
    }
    while(x!=x->next)
    {
        for(i=1;i<M;i++) x=x->next;
        t=x->next;
        x->next=t->next;
        free(t);
        N--;
    }
    printf("%d\n",x->item);
}
