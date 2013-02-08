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

void ShellInsert(SSTable &ST,int dk)
{
    int i,j;
    for(i=dk+1;i<=ST.length;i++)
    {
        if(ST.elem[i]<ST.elem[i-dk])
        {
            ST.elem[0]=ST.elem[i];

            for(j=i-dk;j>0&&ST.elem[0]<ST.elem[j];j-=dk)
            ST.elem[j+dk]=ST.elem[j];
            ST.elem[j+dk]=ST.elem[0];
        }
    }PR(ST);
}

main()
{
	SSTable ST;
	int loc,key;
	int i,dk;
	scanf("%d",&dk);
	Creat_Seq(ST,dk);
	for(dk/=2;dk>=1;dk/=2)
    ShellInsert(ST,dk);
}
