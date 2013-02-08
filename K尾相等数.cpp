#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
int temp[1001];
int main()
{
    memset(temp,0,sizeof(temp));
    int k;
    int i=1,sum=1;
    int o=0;//用于判断k>=1000
    scanf("%d",&k);
    if(k>=1000)
    {
        o=1;
        k=k%1000;
    }
    for(i=1;i<=1001;i++)
    {
        sum*=k;
        if(o||sum>=1000)
        {
            o=1;
            sum=sum%1000;
            if(temp[sum]==0)
                temp[sum]=i;
            else
            {
                printf("%d",i+temp[sum]);
                break;
            }
        }
    }
    //for(i=1;i<=1001;i++)
       // printf("%d ",temp[i]);
    return 0;
}
/*
Sample Input
3
Sample Output
120
*/
