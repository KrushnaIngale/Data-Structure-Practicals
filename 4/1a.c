#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void main() {
    struct node * s,*p,*q;
    char ch;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter data of first node :\n");
    scanf("%d",&p->data);
    s=p;
    do{
        q=(struct node *)malloc(sizeof(struct node));
        printf("Enter data of next node :\n");
        scanf("%d",&q->data);
        p->next=q;
        p=q;
        printf("press y to add next node :\n");
        ch=getch();
    }while(ch=='y'||ch=='Y');
    p->next=NULL;

    struct node * a;
    a=(struct node *)malloc(sizeof(struct node));
    printf("Enter new node data to insert at beginning :\n");
    scanf("%d",&a->data);
    a->next=s;
    s=a;

    while(s!=NULL){
        printf("Element = %d\n",s->data);
        s=s->next;
    }
}