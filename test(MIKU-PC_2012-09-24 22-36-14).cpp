#include<stdio.h>
int main()
{
	int x,sum=0;
	char ch;
	while(1)
	{
	    scanf("%d",&x)
        getchar();
        ch=getchar();
        if(ch=='\n')  break;
        else
        sum=x+(int)ch-48;
	}
	sum+=x;
	printf("%d",sum);
	return 0;
}
