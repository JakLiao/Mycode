/*设老字符串为s;   要求在s中查找s1 ;若找到s1:   则用字符串s2来替代它
例如: s=abcdxyzabxyz        s1=xyz      s2=mn
执行程序后 s=abcdmnabmn
代码如下:*/
#include "string.h"
#include "stdio.h"
#define N 255
typedef struct string
{
    char ch[N];
    int len;
}STRING;
int Leng(STRING s)
{
    int i=0;
    int j=0;
    while(s.ch[i]!='\0')
    {
        i++;
        j++;
    }
    return(j);
}

STRING Substring(STRING s,int n1,int n2)
{
    STRING str;
    int i;
    for(i=0;i<=n2;i++)
    str.ch[i]=s.ch[n1+i-1];
    str.len=n2;
    str.ch[i]='\0';
    return(str);
}

STRING Delete(STRING s,int i,int j)           /* 调用Delete删除函数删除来删除字符串s1 */
{
    int k;
    for(k=i+j-1;k<=s.len;k++)
    s.ch[k-j]=s.ch[k];
    s.len=s.len-j;
    return(s);
}

STRING Insert(STRING s,STRING s2,int i)       /*    调用插入函数Insert来插入字符串s2 */
{
    int j;
    for(j=s.len;j>=i;j--)
    s.ch[j+s2.len-1]=s.ch[j-1];
    for(j=0;j<s2.len;j++)
    s.ch[j+i-1]=s2.ch[j];
    s.len=s.len+s2.len;
    s.ch[s.len]='\0';
    return(s);
}

int equal(STRING s1,STRING s2)    /*   调用比较函数equal来比较串s中是否有与s1相等的串 */
{
    int i;
    for(i=0;i<s1.len;i++)
    if(s1.ch[i]!=s2.ch[i])
    return(0);
    return(1);
}

STRING Change(STRING s,STRING s1,STRING s2)   /* 调用总的替换函数Change来实现替换的目的 */
{
    int Leng(STRING s);
    STRING Substring(STRING s,int i,int Lens1);
    STRING Delete(STRING s,int i,int j);
    STRING Insert(STRING s,STRING s2,int i);
    int equal(STRING s1,STRING s2);
    int i=1;
    /* int j,k; */
    STRING str;
    int Lens;
    int Lens1;
    int Lens2;
    Lens=Leng(s); Lens1=Leng(s1); Lens2=Leng(s2);
    s.len=Lens; s1.len=Lens1; s2.len=Lens2;
    while(i+s1.len-1<=s.len)
    {
        str=Substring(s,i,s1.len);
        if(equal(str,s1)==1)
        {
            s=Delete(s,i,s1.len);
            s=Insert(s,s2,i);
            i=i+s2.len;
        }
        else
        i++;
    }
    return(s);
}

main()
{
    STRING s,s1,s2;
    int Lens,Lens1,Lens2;
    STRING Change(STRING S,STRING S1,STRING S2);
    int Leng(STRING s);
    printf("\nPlease input s:\n");
    gets(s.ch);   s.len=0; Lens=Leng(s);
    printf("Please input s1:\n");
    gets(s1.ch);    s1.len=0; Lens1=Leng(s1);
    printf("Please input s2:\n");
    gets(s2.ch);   s2.len=0;
    Lens2=Leng(s2);
    printf("Lens=%d    Lens1=%d     Lens2=%d\n",Lens,Lens1,Lens2);
    s=Change(s,s1,s2);
    Lens=Leng(s);
    printf("\ns=%s\nLens=%d\n",s.ch,Lens);

}
