#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int choose(int n,int p)
{
    if(p-1>=n-p)//中间偏右的数
    {
      if(p-1<=2) return 0;
      return p-3;
    }
    else//中间偏左的数
    {
        if(n-p<=2) return 0;
        return n-p-2;
    }
}
int main()
{
      int n,q;
      int p,i,ans[31];
      while(scanf("%d %d",&n,&q)!=EOF)
      {
          for(i=1;i<=q;i++)
          {
              scanf("%d",&p);
              if(n==3)
              { if(p==1) ans[i]=1;
                if(p==2) ans[i]=0;
                if(p==3) ans[i]=1;
              }
              else ans[i]=choose(n,p);
          }
          for(i=1;i<q;i++)
                printf("%d ",ans[i]);
          printf("%d\n",ans[i]);
      }
      return 0;
}
