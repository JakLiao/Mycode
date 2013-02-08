#include <stdio.h>

int main()
{
    int i=0,j=0,n=0,k=0,count=0;
    int N,num;
    scanf("%d",&num);
    while(count<num)
    {
        scanf("%d",&N);
        char s[N+1];
        for(i=1;i<=N;i++)   s[i]=0;
        for(n=4;n<=N;n+=2)  {s[n]=1;}
        for(i=3;i<=N/2;i+=2)
        {
            if(s[i])continue;
            for(n=i+i;n<=N;n+=i)
            {
                s[n]=1;
            }
        }
        for(i=2,n=0;i<=N;i++)
        {
            if(s[i]==0)
            {
                //printf("%d\n",i);
                n++;
            }
        }
        printf("%d\n",n);
        count++;
    }
    return 0;
}
