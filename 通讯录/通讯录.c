#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>

typedef struct peo    //定义结构体
{
     char name[20];  //姓名
     char street[20];//街道
     char city[20];//城市
     char eip[20];//邮编
     char state[20];//国家
     char group[20];//群组
     struct peo *next;       //定义结构体指针
}PEO,*Link;

 PEO *head;

int ReadData(Link *head) //创建通讯录
{
    FILE *fp;
    PEO *p1,*p2;//定义头指针，尾指针
    if((fp=fopen("people.txt","rb"))==NULL)
    {
        printf("\n****************这是一个新的通讯录管理系统******************\n");
        return;
    }
    while(!feof(fp))
    {
        p1=(PEO *)malloc(sizeof(PEO));
        if(p1==NULL)
        {
            printf("出错\n");
			fclose(fp);
			return 0;
        }
        if(fread(p1,sizeof(PEO),1,fp)!=1)
        {
            free(p1);
            break;
        }
        if(*head==NULL)
            *head=p2=p1;
        else
        {
            p2->next=p1;
            p2=p1;
        }
    }
    fclose(fp);
    return 1;
}

void initial(PEO *h)              //初始化函数
{
    h=NULL;                                //让头指针返回到第一个节点
}
void sort(PEO *h)                 //顺序读入
{
    PEO *p,*q,*s;
    char   t[20];                  //定义临时储存数据的数组
    p=h;                 //使p指向头指针
    while(p)                   //读到p时，按s->q->p顺序读取
    {
        s=p;
        q=p->next;
        while(q)                  //读到q时，比较s,p是否相同
        {
            if(strcmp(q->name,s->name)<=0)  //若相同，则将q指向的数据赋予s
                s=q;
            q=q->next;
        }
        if(s!=p)                         //当p读到下一个节点，即s与p不相同时
        {
            strcpy(t,p->name);                 //则重新对s赋值
            strcpy(p->name,s->name);
            strcpy(s->name,t);
        }
        p=p->next;
    }
}
PEO *enter(PEO *h)     //添加函数定义
{
    PEO *p,*p0;
    p=p0=(PEO *)malloc(sizeof(PEO));
    printf("请输入所要添加的人的姓名,街道,城市,邮编,国家，群组:\n");
    scanf("%s%s%s%s%s%s",p->name,p->street,p->city,p->eip,p->state,p->group);
    p->next=NULL;
    if(h==NULL)
    {
        h=p;
        printf("添加成功!\n");
        return h;
    }
    p0=h;
    if(strcmp(p0->name,p->name)>0)//判断输入的姓名是否相同
    {
        p->next=h;
        h=p;
        printf("添加成功!\n");
        return h;
    }
    while(p0->next!=NULL&&strcmp(p0->next->name,p->name)<0)
        p0=p0->next;
    if(p0->next==NULL)
    {
        p0->next=p;
        printf("添加成功!\n");
        return h;
    }
    else if(!strcmp(p0->next->name,p->name))
    {
        printf("记录已存在!\n");
        free(p);
        return h;
    }
    else
    {
        p->next=p0->next;
        p0->next=p;
        printf("添加成功!\n");
        return h;
    }
}
void display(PEO *ptr)
{
    if(ptr==NULL)
    {
        printf("没有记录!\n");
        return ;
    }
    printf("所有人情况如下：\n");
    printf("    姓名      街道      城市      邮编      国家      群组\n");
    while(ptr!=NULL)
    {
        printf("%6s%10s%10s%10s%10s%10s\n",ptr->name,ptr->street,ptr->city,ptr->eip,ptr->state,ptr->group);
        ptr=ptr->next;
    }
    printf("\n");
}


void data2(PEO *p,char find[])  //输出按班级查找的结果，供函数groupsearch(PEO *h)调用
{
    if(strcmp(p->group,find)==0)        //判断是否与要寻找的群组名吻合
    {
        printf("群组资料如下：\n");
        printf("    姓名      街道      城市      邮编      国家      群组\n");
        printf("%6s%10s%10s%10s%10s%10s\n",p->name,p->street,p->city,p->eip,p->state,p->group);
    }
    else  p=p->next;      //若不吻合，指针指向下一个节点进行判断
}//data2

void menu4()  //输出菜单上下限制符
{
        printf("================================================================================");
}//menu4

PEO *Locate(PEO *h,char find[],char match[]) //查找匹配函数定义,该函数用于定位链表中符合要求的节点，并返回该指针
{
    PEO *r;                //定义节点指针r
    if(strcmp(match,"group")==0)                //按群组查询
    {
        r=h;                //初始化r,指向第一个节点
        while(r!=NULL)                //r非空
        {
                if(strcmp(r->group,find)==0)                //查询成功
                        return r;
                r=r->next;                //节点后移
        }
    }
    return 0;
}

void groupsearch(PEO *h)                //查询函数定义
{
    char temp;                //定义单字符temp
    char find[20];              //定义字符串find[]
    int n=0;
    PEO *p,*p0;                //定义节点p,p0
    if(h==NULL)
    {
        printf("\n\a对不起,无信息可查询!\n");
        return;
    }
    else
    {
        printf("\n请输入您要查询的群组:");
        scanf("%s",find);
        p=Locate(h,find,"group");   //调用Locate 函数，按群组名进行查找匹配
    }//else if
    if(p)
    {
        printf("\n                    ==============>查询结果<==============\n");
        menu4();
        while(p)
        {
            p0=p;
            data2(p0,find);                //输出按群组名查找的结果

            p=p->next;                //节点后移
            if((strcmp(find,p0->group)==0))    //当有重复群组名时，n加1
                n++;
        }//while
        printf("该群组有  %d 个联系人。 \n",n);
        menu4();
    }//if
    else    printf("\n\a对不起,无信息可查询!\n");
}

PEO *delet(PEO *h)
{
    char s[20];
    PEO *p,*p0;
    if(h==NULL)
    {
        printf("没有记录!\n");
        return h;
    }
    printf("请输入所要删除人的姓名：\n");
    scanf("%s",s);
    p0=h;
    if(!strcmp(p0->name,s))
    {
        h=p0->next;
        free(p0);
        printf("删除成功!\n");
        return h;
    }
    p=p0->next;
    while(p!=NULL)
    {
        if(!strcmp(p->name,s))
        {
            p0->next=p->next;
            free(p);
            printf("删除成功!\n");
            return h;
        }
        p0=p;
        p=p->next;
    }
    printf("没有此人的记录!\n");
    return h;
}
int save(PEO *head)
{
    PEO *p;
    FILE *fp;
    if((fp=fopen("people.txt","wb"))==NULL)
    {
        printf("\n打不开文件!\n");
        return;
    }
    p = head;
    while(p!=NULL)
    {
        if(fwrite(p,sizeof(PEO),1,fp)!=1)
		{
			printf("写入数据出错\n");
			fclose(fp);
			return 0;
		}
		p=p->next;
    }
    fclose(fp);
	return 1;
}
void search(PEO *h)
{
    char s[20];
    PEO *ptr;
    ptr=h;
    if(ptr==NULL)
    {
        printf("没有记录!\n");
        return ;
    }
    printf("请输入所要查找人的姓名：\n");
    scanf("%s",s);
    for( ;ptr!=NULL;ptr=ptr->next)
    {
        if(!strcmp(ptr->name,s))
        {
            printf("此人情况如下：\n");
            printf("    姓名      街道      城市      邮编      国家\n");
            printf("%6s%10s%10s%10s%10s\n",ptr->name,ptr->street,ptr->city,ptr->eip,ptr->state);
            return ;
        }
    }
    Beep(1060,500);//i
    Beep(784,500);//5
    Beep(523,500);//1
    printf("查无此人!\n");
}

void Free(Link *head)//释放资源
{
	Link p = *head;
	while(p!=NULL)
	{
		*head = (*head)->next;
		free(p);
		p =* head;
	}
	*head = NULL;
}

void main()
{
    int k;
    char s[20],c[20]={'1'};
    char p[20];
    Link head = NULL;
    printf("Welcome to CY's NOTEBOOK!\n");
    printf("Please enter you password:\n");
    gets(p);
    printf("\n Please wait...\n");
    Sleep(1000);
    system("cls");
    if(!strcmp("Chen Yi",p))
    {
        printf("\n\n Welcome!\n");
        printf(" []             *   *    *                 @              *                 *   ");
        printf("\n");
        printf(" []          *             *               @                *              *    ");
        printf("\n");
        printf(" []         *               *              @                  *          *      ");
        printf("\n");
        printf(" []         *                              @                    *      *       ");
        printf("\n");
        printf(" []         *                              @                        *          ");
        printf("\n");
        printf(" []          *                             @                        *           ");
        printf("\n");
        printf(" []            *           *               @                        *           ");
        printf("\n");
        printf(" []               *  *  *                  @                        *           ");
        ReadData(&head);
        do
        {
            printf("分类查询请按1，添加记录请按2,删除记录请按3,显示全部请按4,保存记录请按5,个人信息查询请按6,退出系统请按0\n");
            scanf("%d",&k);
            while(k!=1&&k!=2&&k!=3&&k!=4&&k!=5&&k!=6&&k!=0)
            {
                printf("输入错误！请输入数字1至6!\n");
                scanf("%d",&k);
            }
            switch(k)
            {
                case 1:
                    do
                    {
                        groupsearch(head);//查寻群组信息
                        printf("继续查询请按1,按其他键退出查询!\n");
                        scanf("%s",s);
                    }while(!strcmp(s,c));
                    break;
                case 2:
                    do
                    {
                        sort(head);
                        head=enter(head);//添加个人信息
                        printf("继续添加请按1,按其他键退出添加!\n");
                        scanf("%s",s);
                    }while(!strcmp(s,c));
                    break;
                case 3:
                    do
                    {
                        sort(head);
                        head=delet(head);//删除个人信息
                        printf("继续删除请按1,按其他键退出删除!\n");
                        scanf("%s",s);
                    }while(!strcmp(s,c));
                    break;
                case 4:sort(head);display(head);break;
                case 5:sort(head);save(head);printf("保存成功");break;//保存个人信息
                case 6:sort(head);search(head);break;//查询个人信息
                case 0:Free(&head);return;
            }
        }while(1);
    }
    else printf("密码错误，系统将自动退出！");
    Beep(1060,500);//i
    Beep(784,500);//5
    Beep(523,500);//1
}
