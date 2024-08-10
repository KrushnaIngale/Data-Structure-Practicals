#include<stdio.h>
void main(){
    
    int x[]={1,2,3,4,5};
    int *xarr=x;
    printf("int value of ptr is :%d\n",*xarr);
    printf("address of ptr is %d\n",xarr);

    xarr++;
    printf("now after increment :\n");
    printf("int value of ptr is :%d\n",*xarr);
    printf("address of ptr is :%d\n",xarr);
    printf("\n");
    
    float y[]={1.2,2.3,3.4,4.5,5.6};
    float *yarr=y;
    printf("float value of ptr is :%f\n",*yarr);
    printf("address of ptr is :%d\n",yarr);

    yarr++;
    printf("now after increment :\n");
    printf("float value of ptr is :%f\n",*yarr);
    printf("address of ptr is :%d\n",yarr);
    printf("\n");

    char z[]={'a','b','c','d','e'};
    char *zarr=z;
    printf("char value of ptr is :%c\n",*zarr);
    printf("address of ptr is :%d\n",zarr);

    zarr++;
    printf("now after increment :\n");
    printf("char value of ptr is :%c\n",*zarr);
    printf("address of ptr is :%d\n",zarr);

}