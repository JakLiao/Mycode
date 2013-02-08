#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    char str[50],*ptr=NULL;
    int max=0,i,n;
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        for(n=0;str[i+n]!='\0'&&(str[i+n]>='a'&&str[i+n]<='z'||str[i+n]>='A'&&str[i+n]<='Z');n++);
            if(n>max)
            {
                max=n;
                ptr=str+i;
            }
    }
    for(i=0;(ptr[i]>='a'&&ptr[i]<='z'||ptr[i]>='A'&&ptr[i]<='Z')&&ptr[i]!='\0';i++)
        printf("%c",ptr[i]);
    return 0;
}
