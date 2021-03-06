#include"malloc.h"
#include"stdio.h"
#include"stdlib.h"

typedef int ElemType;
typedef struct /*静态查找表的顺序存储结构 */
{
	ElemType *elem; /* 数据元素存储空间基址，建表时按实际长度分配，0号单元留空 */
	int length; /* 表长度 */
}SSTable;

void Creat_Seq(SSTable &ST,int n)
{ /* 操作结果: 构造一个含n个数据元素的静态顺序查找表ST(数据来自数组r) */
	int i,temp;
	ST.elem=(ElemType *)malloc((n+1) * sizeof(ElemType)); /* 动态生成n个数据元素空间(0号单元不用) */
	if(!(ST).elem)
	{
		printf("ERROR\n");
		exit(0);
	} /*内存分配失败结束程序*/
	for(i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		*(ST.elem+i)=temp; /* 依次赋值给ST */
	}
	ST.length=n;
}

int PR(SSTable &ST)
{
    int i;
    for(i=1;i<=ST.length;i++)
    printf("%d ",ST.elem[i]);
    printf("\n");
}

void BInserSort(SSTable &ST)
{
    int i,j,m,low,high;
    for(i=2;i<=ST.length;i++)
    {
        ST.elem[0]=ST.elem[i];
        low=1;high=i-1;
        while(low<=high)
        {
            m=(low+high)/2;
            if(ST.elem[0]<ST.elem[m]) high=m-1;
            else low=m+1;
        }
        for(j=i-1;j>=high+1;j--)
        ST.elem[j+1]=ST.elem[j];
        ST.elem[high+1]=ST.elem[0];
        PR(ST);
    }

}

main()
{
	SSTable ST;
	int loc,key;
	int n;
	scanf("%d",&n);
	Creat_Seq(ST,n);
	BInserSort(ST);
}
