#include<stdio.h>
int count(int pre, int currp, int currs, int req, int n)
{
		if(currp==n-1)
		{
				if(pre==0 && req==currs) return 1;
				else if(pre==1 && req-currs<=1) return 1;
				else return 0;
		}
		if(currs>req) return 0;
		
		if(pre==1) return count(1,currp+1,currs+1,req,n) + count(0,currp+1,currs,req,n);
		else return count(1,currp+1,currs,req,n) + count(0,currp+1,currs,req,n);

}
int main()
{
		int t;
		scanf("%d",&t);
		while(t--)
		{
				int p,n,k;
				scanf("%d %d %d",&p,&n,&k);
				printf("%d %d\n",p,count(0,1,0,k,n)+count(1,1,0,k,n));
		}
}
