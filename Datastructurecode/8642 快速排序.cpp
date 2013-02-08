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

int Partition(SSTable &ST,int low,int high)
{
    ElemType pivotkey;
    ST.elem[0]=ST.elem[low];
    pivotkey=ST.elem[low];
    while(low<high)
    {
        while(low<high&&ST.elem[high]>=pivotkey) --high;
        ST.elem[low]=ST.elem[high];
        while(low<high&&ST.elem[low]<=pivotkey) ++low;
        ST.elem[high]=ST.elem[low];
    }
    ST.elem[low]=ST.elem[0];
    PR(ST);
    return low;
}



void QSort(SSTable &ST,int low,int high)
{
    int pivotloc;
    if(low<high)
    {
        pivotloc=Partition(ST,low,high);
        QSort(ST,low,pivotloc-1);
        QSort(ST,pivotloc+1,high);
    }
}

main()
{
	SSTable ST;
	int loc,key;
	int n;
	scanf("%d",&n);
	Creat_Seq(ST,n);
	QSort(ST,1,n);
}

