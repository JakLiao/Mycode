#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    int i,j,f[2000],n,m,gethappy[50],losspow[50];
    memset(f,0,sizeof(f));
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&gethappy[i]);
    for(i=0;i<n;i++) scanf("%d",&losspow[i]);
    for(i=0;i<n;i++)
        for(j=2000;j>=losspow[i]+1;j--)
            f[j-losspow[i]]+gethappy[i]>f[j]?f[j]=f[j-losspow[i]]+gethappy[i]:1;
    printf("%d\n",f[1999]+1);
    return 0;
}
