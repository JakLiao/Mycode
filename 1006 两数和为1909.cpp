#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    int a[10];
    int i,j;
    char ch='N';
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    while((ch!='Y')&&(i!=9))
    {
        for(i=0;i<9;i++)
            for(j=i+1;j<10;j++)
                if(a[i]+a[j]==1909)
                    ch='Y';
    }
    putchar(ch);
    return 0;
}
