#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int number(unsigned int N)
{
    if(N==1||N==2)
        return 0;
    if(N==3)
        return 1;
    if(N%2==0)
        return 2*number(N/2);
    if(N%2==1)
        return number((N-1)/2)+number((N+1)/2);
}
int main()
{
    unsigned int N;
    scanf("%d",&N);
    while(N!=0)
    {
        printf("%d\n",number(N));
        scanf("%d",&N);
    }
    return 0;
}
