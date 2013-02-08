#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    char current,original;
    int x;
    current=getchar();
    putchar(current);
    while(current!=EOF)
    {
        original=current;
        current=getchar();
        if(current==EOF) break;
        x=current+128-original;
        if(x>127)
            x=current+32-original;
        putchar((char)x);
    }
    return 0;
}
