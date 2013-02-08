#include"stdio.h"

int main()
{
    int a,b,c,remain;
    int ans=0;
    scanf("%d %d %d",&a,&b,&c);
    while(a>=2&&c>0)   {a=a-2;c--;ans++;}
    while(a>=2&&b>0)   {a=a-2;b--;ans++;}
    remain=b+c;
    if(remain==0)
    {
        ans+=a/3;
        if(a%3) ans++;
    }
    else
    {
        if(a==0)
        {
            ans+=remain/2;
            ans+=remain%2;
        }
        else ans+=remain/2+1;
    }
    printf("%d\n",ans);
    return 0;
}
