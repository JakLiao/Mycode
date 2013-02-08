#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
	int n;
	char a[100];
	int i,j,flag;
    gets(a);
	n=strlen(a);
	i=0;
	j=n-1;
	flag=0; // characters qty need inserted
	while (   (flag<2)       // only need 0 or 1 character
		   && ((i+1)<=(j-1)) // have character to compare
		  )
	{
		if (a[i]==a[j]) {i++; j--;}
		   else if (a[i]==a[j-1]) {flag++; i++; j-=2;}
			  else if (a[i+1]==a[j]) {flag++; i+=2; j--;}
				else flag=2;
	}
	if (flag<2) printf("Y");
	  else printf("N");
	return 0;
}
