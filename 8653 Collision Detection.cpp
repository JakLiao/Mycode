#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    int x1,x2,y1,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    if(x1==x2&&y1==y2)
        printf("error\n");
    else if((abs(x1-x2)==0&&abs(y1-y2)==1)||(abs(x1-x2)==1&&abs(y1-y2)==0)||(abs(x1-x2)==1&&abs(y1-y2)==1))
        printf("collision\n");
    else
        printf("normal\n");
    return 0;
}
