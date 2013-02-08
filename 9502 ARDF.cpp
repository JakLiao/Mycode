#include<stdio.h>
#include<string.h>
#include<math.h>
int B[10]={5,4,3,2,1,6,7,8,9,0};
char st2[10][10]={"-----",
                  ".----",
                  "..---",
                  "...--",
                  "....-",
                  ".....",
                  "-....",
                  "--...",
                  "---..",
                  "----."};
char st80[10][20]={"-----",
                  "-- ---.",
                  "-- ---..",
                  "-- ---...",
                  "-- ---....",
                  "-- ---.....",
                  "-....",
                  "--...",
                  "---..",
                  "----."};

int n80[10]={5,7,8,9,10,11,5,5,5,5};

double ex(int x)
{
     double y=1.0;
     int i;
     if(x==0) return 1;
     for(i=0;i<x;i++) y*=10;
     return y;
}
int find(char *s1,char *s2)
{
    int i,j,succ,len1,len2;
    i=0;
    succ=0;
    len1=strlen(s1);
    len2=strlen(s2);
    while((i<=len2-len1)&&(!succ))
    {
        j=0;
        succ=1;
        while((j<=len1-1)&&succ)
          if(s1[j]==s2[i+j]) j++;
          else succ=0;
        ++i;
    }
    if(succ) return (i-1);
    else return (-1);
}

double get2(char *s)
{
     int num[110];
     char ss[10];
     double ans=0;
     int p,i,j;
     for(i=0;i<110;i++) num[i]=-1;

     for(i=0;i<strlen(s);i+=5)
     {
         for(j=i;j<i+5;ss[j-i]=s[j++]);
         ss[j-i]='\0';
         for(j=0;j<=9;j++)
           if(strcmp(st2[j],ss)==0) num[i]=j;
     }
     j=0;
     for(i=109;i>=0;i--)
         if(num[i]!=-1)
         {
             ans+=num[i]*ex(j);
             j++;
         }
     return ans;
}

double get80(char *s)
{
     int num[110];
     double ans=0;
     int p,i,j;
     for(i=0;i<110;i++) num[i]=-1;

     for(i=0;i<=9;i++)
     {
         while((p=find(st80[B[i]],s))!=-1)
         {
             num[p]=B[i];
             for(j=p;j<p+n80[B[i]];j++) s[j]='*';
         }
     }
     j=0;
     for(i=109;i>=0;i--)
         if(num[i]!=-1)
         {
             ans+=num[i]*ex(j);
             j++;
         }
     return ans;
}

void print2(double x)
{
     int num[30],i,j;
     if(x-0==0) { printf("%s\n",st2[0]); return ; }
     for(i=0;i<30;i++) num[i]=0;
     j=0;
     do
     {
         num[j++]=fmod(x,10);
         x=floor(x/10);
     }while(x!=0);
     for(i=j-1;i>=0;i--)
       printf("%s",st2[num[i]]);
     printf("\n");
}

void print80(double x)
{
     int num[30],i,j;
     if(x-0==0) { printf("%s\n",st80[0]); return ; }
     for(i=0;i<30;i++) num[i]=0;
     j=0;
     do
     {
         num[j++]=fmod(x,10);
         x=floor(x/10);
     }while(x!=0);
     for(i=j-1;i>=0;i--)
       printf("%s",st80[num[i]]);
     printf("\n");
}

main()
{
      int t;
      double a;
      double b;
      char s1[110],s2[110];
      int boduan;

      scanf("%d",&t);
      while(t--)
      {
          scanf("%d",&boduan);
          getchar();
          gets(s1);
          gets(s2);
          if(boduan==2)
          {
              a=get2(s1);
              b=get2(s2);
              print2(a+b);
          }
          else
          {
              a=get80(s1);
              b=get80(s2);
              print80(a+b);
          }
      }
}
