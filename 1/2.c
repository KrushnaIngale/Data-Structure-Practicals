#include<stdio.h>
void main(){
    int n,index,newValue;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter array elements: \n");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("entered elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("Enter the array index to change(0 to %d):",n-1);
    scanf("%d",&index);

    if(index<0 || index>=n){
        printf("Invalid index: %d",index);
    }
    else{
        printf("Enter the new value:");
        scanf("%d",&newValue);
        a[index]=newValue;

        printf("Updated array elements are: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ",a[i]);
        }
        

    }
}