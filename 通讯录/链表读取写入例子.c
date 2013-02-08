#include <stdio.h>
#include <stdlib.h>

struct Country//乡村信息结构体
{
	char counnum[5];
	char counname[21];
	int population;
	int family;//depositor存款人
	float relief;//救济金
	struct Country *next;
};

typedef struct Country *Lcountry;

//生成数据
int CreateData(Lcountry *head)
{
	Lcountry s,p;
	int i,num;

	printf("输入个数:");
	scanf("%d",&num);
	if(num < 1)
	{
		printf("个数不合法\n");
		return 0;
	}

	//录入数据
	for(i=1;i<=num;i++)
	{
		if((s=(Lcountry)malloc(sizeof(struct Country)))==NULL)
		{
			printf("内存申请出错\n");
			return 0;
		}

		printf("输入counnum counname population family relief,中间用空格隔开\n");
		if(scanf("%s%s%d%d%f",s->counnum,s->counname,&s->population,&s->family,&s->relief)!=5)
		{
			printf("录入数据有误\n");
			return 0;
		}
		s->next=NULL;

		if(i==1)
		{
			*head=p=s;
		}
		else
		{
			p->next=s;
			p=s;
		}
	}

	return 1;
}

//写入数据
int WriteData(Lcountry head)
{
	FILE *fp;
	Lcountry p;

	if((fp=fopen("test.txt","wb"))==NULL)//二进制只写方式打开
	{
		printf("打开文件出错\n");
		return 0;
	}

	p=head;
	while(p!=NULL)
	{
		if(fwrite(p,sizeof(struct Country),1,fp)!=1)
		{
			printf("写入数据出错\n");
			fclose(fp);
			return 0;
		}
		p=p->next;
	}

	fclose(fp);//关闭文件
	return 1;
}

//读入数据
int ReadData(Lcountry *head)
{
	Lcountry s,p;
	FILE *fp;
	if((fp=fopen("test.txt","rb"))==NULL)//二进制只读方式打开
	{
		printf("打开文件出错\n");
		return 0;
	}
	while(!feof(fp))//文件不到末尾
	{
		if((s=(Lcountry)malloc(sizeof(struct Country)))==NULL)
		{
			printf("内存申请出错\n");
			fclose(fp);
			return 0;
		}
		//怎么写就怎么读取
		if(fread(s,sizeof(struct Country),1,fp)!=1)//读到末尾或者出错,跳出循环
		{
			free(s);
			break;
		}
		if(*head==NULL)
			*head=p=s;
		else
		{
			p->next=s;
			p=s;
		}
	}
	fclose(fp);//关闭文件
	return 1;
}

//显示数据
void Print(Lcountry p)
{
	printf("counnum \t counname \t population \t family \t relief\n");
	while(p!=NULL)
	{
		printf("%s\t\t%s\t\t%d\t\t%d\t\t%0.1f\n",p->counnum,p->counname,p->population,p->family,p->relief);
		p=p->next;
	}
}
//释放资源
void Free(Lcountry *head)
{
	Lcountry p=*head;
	while(p!=NULL)
	{
		*head=(*head)->next;
		free(p);
		p=*head;
	}
	*head=NULL;
}

int main(void)
{
	Lcountry head=NULL;

	//生成数据
	if(CreateData(&head)!=1)
		return 1;

	//显示数据
	Print(head);

	//写入数据
	if(WriteData(head)!=1)
		return 1;

	//释放资源
	Free(&head);
	printf("写入完毕\n");

	printf("\n读取数据...\n");
	//读入数据
	if(ReadData(&head)!=1)
		return 1;

	//显示数据
	Print(head);

	//释放资源
	Free(&head);
	return 0;
}
