#include<iostream>
using namespace std;

//输出fibonacci数列第N个数（N<=1000)

void print(int *s)
{
    for (int i = s[0]; i > 0; i--)
    cout<<s[i];
    cout<<endl;
}

void change(int a[], int b[])
{
    for (int i = 1, c = 0; i <= a[0]+1; i++)
    {
        b[i] += a[i] + c;
        if (b[i] >= 10)
        {
            b[i] %= 10;
            c = 1;
        }
        else c = 0;
    }
    if (b[b[0]+1]) b[0]++;
}

int *fibonacci(int a[], int b[], int n)
{
    switch(n)
    {
        case 2: return a;
        case 1: return b;
    }
    change(a, b);
    fibonacci(b, a, n-1);
}

int main()
{
    int a[10000], b[10000], n, *s;
    b[0] = a[1] = a[0] = 1;
    b[1] = 0;
    for(int i = 2; i < 10000; i++)
    a[i] = b[i] = 0;
    cout<<"\n n = "; cin>>n;
    s = fibonacci(a, b, n);
    cout<<" fibonacci数列的第 "<<n<<" 个数为: ";
    print(s);
    return 0;
}
