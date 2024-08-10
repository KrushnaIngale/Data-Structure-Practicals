#include<stdio.h>
void main()
{
    int a[]={10,20,30,40,50,60,70,80,90,100};
    int n=10;
    int key;
    int found=0;
    printf("Array elements are : 10,20,30,40,50,60,70,80,90,100 \n");

    printf("enter the element you want to search ");
    scanf("%d",&key);

    int low=0;
    int high=n-1;
    int mid=(low+high)/2;

    for(int i=0; i<n; i++){
        if(key==a[mid]){
            found==1;
            printf("%d element is found at %d position",key,mid);
            break;
        }
        if(key<a[mid]){
            high=mid-1;
        }
        if(key>a[mid]){
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    if(found!=1){
        printf("item not found");
    }

}