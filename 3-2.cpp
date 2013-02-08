#include"stdio.h"
#include"stdlib.h"
#include"iostream"
#define MAXSTRLEN 255
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
typedef unsigned char SString[MAXSTRLEN+1];

void get_next(SString T,int next[])
{// 算法4.7
// 求模式串T的next函数值并存入数组next
    int i=1,j=0;
    next[1]=0;
    while(i<T[0])// T[0]用于存储字符串中字符个数
    {
        if(j==0||T[i]==T[j])
        {
            ++i;++j;
            if(T[i]!=T[j])
                next[i]=j;
            else
                next[i]=next[j];
        }
        else j=next[j];
    }
}

int Index_KMP(SString S,SString T,int pos)
{
// 算法4.6
// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置
// KMP算法。   其中，T非空，1<=pos<=StrLength(S)
    int i=pos,j=1;
    //printf("%d %d\n",i,j);
    int next[MAXSTRLEN];
    get_next(T,next);
    while(i<=S[0]&&j<=T[0])// T[0]用于存储字符串中字符个数
    {
        if(j==0||S[i]==T[j])
        {
            i++;
            j++;
            //printf("%d %d\n",i,j);
        }
        else j=next[j];//模式串向右移动
    }
    //printf("%d %d\n",i,j);
    if(j>T[0]) return i-T[0];
    else return 0;
}

int main()
{
    SString S,T;
    int n,i,j;
    char ch;
    int pos;
    scanf("%d",&n);
    ch=getchar();
    for(i=1;i<=n;i++)
    {
        ch=getchar();
        for(j=1;j<=MAXSTRLEN&&(ch!='\n');j++)
        {
            S[j]=ch;
            ch=getchar();
        }
        S[0]=j-1;// S[0]用于存储字符串中字符个数
        /*get_next(S,next);
        printf("NEXT S is:");
        for(j=1;j<=S[0];j++)
            printf("%d",next[j]);
        printf("\n");*/

        ch=getchar();
        for(j=1;j<=MAXSTRLEN&&(ch!='\n');j++)//录入模式串
        {
            T[j]=ch;
            ch=getchar();
        }
        T[0]=j-1;// T[0]用于存储模式串中字符个数
        pos=Index_KMP(S,T,1);
        printf("%d\n",pos);
    }
    return 0;
}









