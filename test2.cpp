#include <cstring>
#include"stdio.h"
using namespace std;
const int N = 55;
int num[N][N][N];
void input(int m,int n,int k);
int maxSum(int a[], int n);
int maxSum2(int a[N][N],int m,int n);
int maxSum3(int a[N][N][N],int m,int n,int k);
int main()
{
    int m, n, k;
        scanf("%d %d %d",&m, &n, &k);
        input(m, n, k);
        int sum = maxSum3(num, m, n, k);
        printf("%d\n", sum);
    return 0;
}
void input(int m,int n,int k)
{
    int i, j, l;
    for(i = 0 ; i < m ; i++)
        for(j = 0 ; j < n ; j++)
            for(l = 0 ; l < k ; l++)
                scanf("%d", &num[i][j][l]);
    return;
}
int maxSum(int a[],int n)
{
    int sum = a[0], b = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(b > 0)
            b += a[i];
        else
            b = a[i];
        if(sum < b)
            sum = b;
    }
    return sum;
}
int maxSum2(int a[N][N],int m,int n)
{
    int sum = a[0][0];
    int b[N], i, j, k;
    for(i = 0 ; i < m ; i++)
    {
        memset(b, 0, sizeof(b));
        for(j = i ; j < m ; j++)
        {
            for(k = 0 ; k < n ; k++)
                b[k] += a[j][k];
            int max = maxSum(b, n);
            if(max > sum)
                sum = max;
        }
    }
    return sum;
}
int maxSum3(int a[N][N][N],int m,int n,int k)
{
    int b[N][N];
    int i, j, l;
    int sum = a[0][0][0], max = 0;
    for(i = 0 ; i < m ; i++)
    {
        memset(b, 0, sizeof(b));
        for(j = i ; j < m ; j++)
        {
            for(l = 0 ; l < n ; l++)
                for(int t = 0 ; t < k ; t++)
                    b[l][t] += a[j][l][t];
            max = maxSum2(b, n, k);
            if(max > sum)
                sum = max;
        }
    }
    return sum;
}
