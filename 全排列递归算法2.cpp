#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

#define MAX 10
int used[MAX];
int result[MAX];
int N;

void print()
{
    int i;
    for(i=0;i<N-1;i++)
        printf("%d,",result[i]);
    printf("%d\n",result[i]);
}

void proc(int step)
{
    int i;
    if(step == N)
    print();
    else
    {
        for(i=0;i<N;i++)
        {
            if(!used[i])
            {
                used[i]=1;
                result[step]=i+1;
                proc(step+1);
                used[i]=0;
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    proc(0);
    return 0;
}
