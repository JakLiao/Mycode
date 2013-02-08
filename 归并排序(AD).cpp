#include <iostream>
using namespace std;
int data[10]={8,7,2,6,9,10,3,4,5,1};
int cp[10];
void Merge(int a[],int b[],int first,int mid,int last)  //合并两个有序序列
{
    int p=first,q=mid+1;
    int pos=first;
    while(p<=mid&&q<=last)
    {
        if(a[p]<a[q])
        {

            b[pos++]=a[p++];
        }
        else
        {

            b[pos++]=a[q++];
        }
    }
    if(p>mid)
    {
        while(q<=last)
        {
            b[pos++]=a[q++];
        }
    }
    else
    {
        while(p<=mid)
        {
            b[pos++]=a[p++];
        }
    }
}
void MergePass(int a[],int b[],int gap,int n) //以一定的步长对数据进行合并
{
    int i=0;
    int j;
    while(i<=n-2*gap+1)
    {
        Merge(a,b,i,i+gap-1,i+2*gap-1);
        i=i+2*gap;
    }
    if(i<(n-gap))
        Merge(a,b,i,i+gap-1,n-1);
    else
        for(j=i;j<n;j++)
            b[j]=a[j];
}
void Merge_sort(int a[],int b[],int n)  //归并排序的非递归  并且不进行回写
{
    int gap=1;
    while(gap<n)
    {
        MergePass(a,b,gap,n);
        gap=2*gap;
        MergePass(b,a,gap,n);
        gap=2*gap;
    }
}
int main()
{

    Merge_sort(data,cp,10);
    for(int i=0;i<=9;i++)
        cout<<data[i]<<endl;
    return 0;
}
