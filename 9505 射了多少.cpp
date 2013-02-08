#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"
int gcd(int a,int b){
    return a%b?gcd(b,a%b):b;}
int main()
{
    int a,b,gcd1,x0,y0,x1,y1,ans;
    scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
    a=abs(x0-x1);
    b=abs(y0-y1);
    //printf("%d %d",a,b);
    gcd1=gcd(a,b);
    ans=a+b-gcd1;
    printf("%d",ans);
    return 0;
}
