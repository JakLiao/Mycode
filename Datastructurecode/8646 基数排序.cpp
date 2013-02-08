#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"
#define insize 100
#define sizeup 10

typedef struct
{
    int *front;
    int *rear;
    int queuesize;
}queuecode,*queue;

int creat(queue &L)
{
	int i;
    for(i=0;i<10;i++)
    {
        L[i].front=(int*)malloc(insize* sizeof(int));
        if(!L[i].front) return 0;
        L[i].rear=L[i].front;
        L[i].queuesize=insize;
    }
	return 1;
}

int main()
{
    int a[100],i,j=0,k,key,length,flag=0,max=0;
    queue L;
    scanf("%d",&length);
    L=(queue)malloc((10)*sizeof(queuecode));
    creat(L);
    for(i=0;i<length;i++)
    {
        scanf("%d",&a[i]);
        flag=0;
        if(a[i]>=10)
        {
            flag=2;
            if(a[i]>=100)
            {
                flag=3;
                if(a[i]>=1000) flag=4;
            }
        }
        if(flag>=max)   max=flag;
    }
    for(k=1;k<=max;k++)
    {
        for(i=0;i<length;i++)
        {
            key=a[i]%((int)pow(10,k))/((int)pow(10,k-1));
            *L[key].rear=a[i];
            L[key].rear++;
        }
        for(key=0;key<10;key++)
        {
            while(L[key].front!=L[key].rear)
            {
                a[j]=*L[key].front++;
                if(a[j]>=100)
                {printf("%d ",a[j]);j++;}
                else if(a[j]>=10)
                {printf("0%d ",a[j]);j++;}
                else if(a[j]>=0)
                {printf("00%d ",a[j]);j++;}
            }
        }
        j=0;
        printf("\n");
    }
    return 0;
}
