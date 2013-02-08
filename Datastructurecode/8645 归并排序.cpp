#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"
int main()
{
    int a[100],i,j=2,k,p,q,length,t,flag=0;
    scanf("%d",&length);
    for(i=0;i<length;i++)
    {
        scanf("%d",&a[i]);
    }
    if(length==1)   printf("%d\n",a[0]);
    else
    {
        while(j<=length)    //归并进行次数，按2的平方进行
        {
            k=0;
            if(flag<=1)          //防止最后一行输出出现死循环的专用标记
            {
                for(i=k;i<length;i=i+j)   //分配子列排序
                {
                    if(i+j-1<length)       //子列间隔最后一个数的号码不超过原数组长度
                    {
                        for(p=i;p<i+j;p++)
                        {
                            for(q=i+j-1;q>p;q--)
                                if(a[p]>=a[q]) {t=a[p];a[p]=a[q];a[q]=t;}
                        }
                        for(p=i;p<i+j;p++)
                            printf("%d ",a[p]);
                    }
                    else              //子列间隔最后一个数的号码超过了原数组长度
                    {
                        for(p=i;p<length-1;p++)
                        {
                            for(q=length-1;q>p;q--)
                                if(a[p]>=a[q]) {t=a[p];a[p]=a[q];a[q]=t;}
                        }
                        for(p=i;p<length;p++)
                            printf("%d ",a[p]);
                    }
                }

            }
            else break;           //防死循环
            j=2*j;
            if(j>=length) {j=length;flag++;}     //最后一次的2次方数强制转换成原数组长度
            printf("\n");
        }
    }
    return 0;
}
