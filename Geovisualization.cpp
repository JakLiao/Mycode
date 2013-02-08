#include"stdio.h"
#include"stdlib.h"
#include"math.h"

int H=20;
int W=30;

int max(int a,int b)
{
    return (a>b)?a:b;
}
int min(int a,int b)
{
    return (a<b)?a:b;
}
/*void swap(int *p1,int *p2)
{
   int temp;
   temp=*p1;
   *p1=*p2;
   *p2=temp;
}*/
int main()
{
     int x1, y1, x2, y2;
     while (scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!= EOF)
     {
        /*if(x1>x2||y1>y2)
        {
            swap(x1,x2);
            swap(y1,y2);
        }*/
        if(y1==y2)
            if(y1>=H||y1<=0||x2<=0||x1>=W)   printf("none\n");
                    else
                          printf("%d %d %d %d\n",max(x1,0),y1,min(x2,W),y2);
            else
                  if(x1>=W||x1<=0||y2<=0||y1 >= H)   printf("none\n");
                  else
                          printf("%d %d %d %d\n",x1,max(y1,0),x2,min(y2,H));
     }
     return 0;
}

