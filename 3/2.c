#include<stdio.h>
void main()
{
    int a[]={10,30,50,20,15};
    int n=5;
    printf("array elements are : 10,30,50,20,15\n");

    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    printf("Sorted array by bubble sort: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", a[i]);
    }

}