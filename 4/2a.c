#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};

void main() {
    struct node *s,*p,*q,*first;
    char ch;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter first node data :\n");
    scanf("%d",&p->data);
    s=p;              // s points to the first node
    first =s ;       // first keeps track of the start of the list
    do{
        q=(struct node *)malloc(sizeof(struct node));
        printf("Enter next node data :\n");
        scanf("%d",&q->data);
        p->next=q;
        p=q;
        printf("press y for next node :\n");
        ch=getch();
    }while(ch=='y'|| ch=='Y');
    p->next=NULL;

    //check if node is null
    if(s==NULL){
        printf("UNderflow");
        return;
    }
    //deletion of first node
    s=first;
    first=first->next;
    free(s);

    //printing of final linked-list
    s=first;
    printf("Linked list after deletion at beginning:\n");
    while(s!=NULL){
        printf("Element = %d \n",s->data);
        s=s->next;
    }
}