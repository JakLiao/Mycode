#include<stdio.h>

int tran(int a)
{
    a/=8;
    if(a)
     {
        tran(a);
        printf("%d",a%8);
     }
    return 0;
}
main()
{
    int a;
    scanf("%d",&a);
    a=a*8;
    tran(a);
    return 0;
}
