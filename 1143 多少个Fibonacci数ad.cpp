#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

void add(char a[],char b[],char c[])
{
    int i,e,d;
    int n,m;
    char temp;
    n=strlen(a);
    m=strlen(b);
    for(i=0;i<n/2;i++) {temp=a[i];a[i]=a[n-1-i];a[n-1-i]=temp;}
    for(i=0;i<m/2;i++) {temp=b[i];b[i]=b[m-1-i];b[m-1-i]=temp;}

    e=0;
    for(i=0;i<n&&i<m;i++)
    {
        d=a[i]-'0'+b[i]-'0'+e;
        e=d/10;
        c[i]=d%10+'0';
    }
    if(i<m)
    {
        for(;i<m;i++)
        {
            d=b[i]-'0'+e;
            e=d/10;
            c[i]=d%10+'0';
        }
    }
    else
    {
        for(;i<n;i++)
        {
            d=a[i]-'0'+e;
            e=d/10;
            c[i]=d%10+'0';
        }
    }
    if(e) c[i++]=e+'0';
    c[i]=0;
    n=i;

    for(i=0;i<n/2;i++) {temp=c[i];c[i]=c[n-1-i];c[n-1-i]=temp;}
}
int main()
{
    char ch1[101],ch2[101];
    char f1[101],f2[101],fn[101];
    scanf("%s %s",ch1,ch2);
    while((strcmp(ch1,"0")!=0)&&(strcmp(ch2,"0")!=0))
    {
        int count=0;
        strcpy(f1,"0");
        strcpy(f2,"1");
        strcpy(fn,"1");
        printf("f1=%s f2=%s fn=%s\n",f1,f2,fn);
        while(strcmp(fn,ch1)<0)
        {
            strcpy(f1,f2);
            strcpy(f2,fn);
            add(f1,f2,fn);
            printf("########f1=%s f2=%s fn=%s\n",f1,f2,fn);
        }
        while(strcmp(fn,ch2)<0)
        {
            count++;
            strcpy(f1,f2);
            strcpy(f2,fn);
            add(f1,f2,fn);
            printf("********f1=%s f2=%s fn=%s\n",f1,f2,fn);
        }
        printf("%d\n",count);
        scanf("%s %s",ch1,ch2);
    }
    return 0;
}
