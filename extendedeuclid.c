#include<stdio.h>
int ee(int a, int b, int *x, int *y)
{
		if(a==0) 
		{
				*x=0;
				*y=1;
				return b;
		}
		int x1,y1,gcd;
		gcd=ee(b%a,a,&x1,&y1);
		*x=y1 - (b/a)*x1;
		*y=x1;
		return gcd;
}
int main()
{
		int n,m,x,y;
		scanf("%d %d",&n,&m);
		printf("%d ",ee(n,m,&x,&y));
		printf("%d %d\n",x,y);
}
