#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    int n,s,m,i,j;
	int *p;
	cin>>n>>s>>m;
	p=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		p[i]=i+1;
	i=s-1;
	while(n>0)
	{
		i=(i+m-1)%n;
		cout<<p[i]<<' ';
		for(j=i+1;j<n;j++)
			p[j-1]=p[j];
		n--;
		if(i==n)
			i=0;
	}
	free(p);
    return 0;
}
