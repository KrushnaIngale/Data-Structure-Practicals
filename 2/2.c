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
    printf("1 for delete an element at beginning: \n");
    printf("2 for delete an element at end: \n");
    printf("3 for delete an element at specific location: \n");
    scanf("%d", &option);

    if(option ==1){
        for(int i=0;i<n;i++){
            a[i]=a[i+1];
        }
        n--;
    }else if(option ==2){
        n--; 
    }else if(option ==3){
        printf("enter the position of element to delete\n");
        scanf("%d",&position);
        for(int i=position;i<n;i++){
            a[i]=a[i+1];
        }
        n--;
    }else{
        printf("Invalid option");
    }

    printf("Updated array is: \n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    // printf("%d",a[4]);
    // printf("%d",a[5]);
}