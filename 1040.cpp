#include"stdio.h"
void SelectSort(int r[],int n){
    int i,j=1,tmp,k;
    int min=0,p;
    for(i=0;i<n-1;++i)
    {
        p=i;
        min=r[i];
        for(j=i+1;j<n;++j)
            if(min>r[j])
            {
                min=r[j];
                p=j;
            }
        tmp = r[i];
        r[i]= r[p];
        r[p]= tmp;
    }
}
int main()
{
	int a[20],n=20,i;
	for(i=0;i<20;i++)
        scanf("%d",&a[i]);
    SelectSort(a,20);
	for(i=0;i<20;i++)
	if(a[i]==a[i+1])
		n--;
	printf("%d",n);
    return 0;
}
