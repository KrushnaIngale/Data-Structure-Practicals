#include<stdio.h>
void main()
{
    int a[]={10,30,50,20,15};
    int n=5;
    int temp,i,j;
    printf("Array elements are : 10,30,50,20,15 \n");

    for(int i=0;i<n-1;i++){
        int smallest=i;
        for(int j=i+1;j<n;j++){
            if(a[smallest]>a[j]){
                smallest=j;
            }
        }
        temp=a[smallest];
        a[smallest]=a[i];
        a[i]=temp;
    }
    printf("Sorted array by selection sort: ");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
