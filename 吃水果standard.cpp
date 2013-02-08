#include <iostream>
using namespace std;
struct fruit
{
       int ti, wi;
       }d[1005];
int n, lasttime, ans;

bool cmp(const fruit &a, const fruit &b)
{
     if (a.ti != b.ti) return a.ti > b.ti;
     else return a.wi < b.ti;
     }
int main()
{
    scanf("%d", &n);
    lasttime = 0;
    for (int i=0; i<n; i++)
    {
      scanf("%d%d", &d[i].wi, &d[i].ti);
      lasttime >?= d[i].ti;
    }
    sort(d, d+n, cmp);
    int i=0, j=0;
    ans = 0;
    while (i<n)
      {
         for (j=i+1; j<n; j++)
           if (d[j].ti != d[i].ti) break;
         if (j==n) i++;
         for (int t=0; t<j-i-1; t++) ans += d[i+t].wi;
         i = j;
      }
    cout <<ans <<endl;

    return 0;
    }
