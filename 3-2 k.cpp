#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#define TRUE  1
#define FALSE  0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
#define MAXSTRLEN  255 	//�û�����255���ڶ�����󴮳�
typedef unsigned char SString[MAXSTRLEN+1];	//0�ŵ�Ԫ��Ŵ��ĳ���

void get_next(SString T,int next[]){
// �㷨4.7
// ��ģʽ��T��next����ֵ����������next
    int i=1,j=0;
    while(i<T[0])
    if(j == 0 || T[j] == T [i] ){
        i++;j++;next[i]=j;
    }
    else j=next[j];
}

int Index_KMP(SString S,SString T,int pos){
// �㷨4.6
// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ��
// KMP�㷨���벹ȫ����
    int next[MAXSTRLEN];
    int i=pos,j=1;
    get_next(T,next);
    while( i <= S[0] && j <= T[0] )
    if( j == 0 || S[i] == T[j] ){
        i++; j++;
    }
    else    j=next[j];
    if( j > T[0] )  return i-T[0];
    return 0;
}

int main()
{
    SString T,S;
    int i,j,n;
    char ch;
    int pos;
    scanf("%d",&n);
    ch=getchar();
    for(j=1;j<=n;j++)
    {
        ch=getchar();
        for( i=1;i<=MAXSTRLEN&&(ch!='\n');i++)    // ¼������
        {
            S[i]=ch;
            ch=getchar();
        }
        S[0]=i-1;    // S[0]���ڴ洢�������ַ�����
        ch=getchar();
        for( i=1;i<=MAXSTRLEN&&(ch!='\n');i++)    // ¼��ģʽ��
        {
            T[i]=ch;
            ch=getchar();
        }
        T[0]=i-1;    // T[0]���ڴ洢ģʽ�����ַ�����
        pos=Index_KMP(S,T,1);    // �����
        printf("%d\n",pos);
    }
    return 0;
}