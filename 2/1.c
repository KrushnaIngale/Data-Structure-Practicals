#include<stdio.h>
void main(){
    int n ,option,option1,option2,option3,position;
    int a[100];
    printf("Enter how many elements you want in array: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("Entered array elements are : ");
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Available Options are :\n");
    printf("1 Insert an element in beginning; \n");
    printf("2 Insert an element in end; \n");
    printf("3 Insert an element at specific position ; \n");
    scanf("%d", &option);
    
    if(option ==1){
        printf("enter value to insert at beginning:");
        scanf("%d", &option1);
        for (int i = n; i > 0; i--)
        {
            a[i]=a[i-1];
        }
        a[0]=option1;   
        n++;     

    }else if(option ==2){
        printf("enter value to insert at end:");
        scanf("%d", &option2);
        a[n]=option2;   
        n++;

    }else if(option ==3){
        printf("enter position to insert");
        scanf("%d",&position);
        printf("enter value to insert at specific position:");
        scanf("%d", &option3);
        for (int i = n; i > position; i--)
        {
            a[i]=a[i-1];
        }
        a[position]=option3;   
        n++; 

    }else{
        printf("Invalid option");
    }

    printf("Updated array elements are: \n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    

}