#include<stdio.h>
void main(){
    //initialize array & variables
    int a[10],n,found;

    //array input and output 

    printf("Enter 10 array elements : ");
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    printf("Entered array elements are: \n");
     for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    //linear searching array
    
    printf("Enter the number to check if present: \n");
    scanf("%d",&n);
    for ( int i = 0; i < 10; i++)
    {
        if (a[i]==n){
            found = 1;
        }
        
    }
    if (found==1) {
            printf("%d is present in array ",n);
    }
    else{
        printf("%d is not present\n",n);
    }
    
}