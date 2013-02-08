#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
	char buf[100],tmp;
	int i,n,k;
	int cnt=0;
	gets(buf);
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
	    if(buf[0]=='z')
            tmp='a';
	    else
            tmp=buf[0]+1;
        for(i=0;i<strlen(buf);i++)
        {
            buf[i]=buf[i+1];
        }
        buf[i-1]=tmp;
        cnt++;
        //printf("%s %d\n",buf,cnt);
	}
	printf("%s\n",buf);
	return 0;
}
