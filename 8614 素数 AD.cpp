#include<stdio.h>
main()
{
     int n,ans[100001];
     int p[100001],i,j;
     for(i=3;i<=100001;i++) p[i]=i%2;
     p[2]=1;
     p[0]=p[1]=0;
     for(i=3;i<=100001>>1;i++)
       if(p[i])
       {
           j=i<<1;
           while(j<=100001)
           { p[j]=0; j+=i;} }
     ans[0]=0;
     for(i=1;i<=100001;i++)
       ans[i]=ans[i-1]+p[i];
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         scanf("%d",&j);
         printf("%d\n",ans[j]);
     }
}
