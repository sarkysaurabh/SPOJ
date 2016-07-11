#include<stdio.h>
int count(int pre, int req, int n)
{
		if(n-1 < req) return 0;
		if(pre==0) return count(pre,req,n-1) + count(pre+1,req,n-1);
		if(pre==1) return count(pre,req-1,n-1) + count(pre-1,req,n-1);

}
int main()
{
		int t;
		scanf("%d",&t);
		while(t--)
		{
				int n,k;
				scanf("%d %d",&n,&k);
				printf("%d\n",count(0,k,n));
		}
}
