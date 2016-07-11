#include<stdio.h>
#define MAX 1000005
int lp[MAX];
int ans[MAX];
int div[MAX];
int a;
int p;
void siever(void)
{
		int i,j;
		lp[1]=1;
		lp[0]=-1;
		for(i=2;i<MAX;++i)
		{
				if(lp[i]==0)
				{
						for(j=i;j<MAX;j+=i)
								lp[j]=i;
				}
		}

}
int cntdiv(int n)
{
		int i;
		int cnt=0;
		int res=1;
		int d=lp[n];
		while(n>1)
		{
				d=lp[n];
				cnt=0;
				while(n%d==0)
				{
						n/=d;
						cnt++;
				}
				res*=(cnt+1);
		}
		return res;
}
void divs(void)
{
		int i;
		div[1]=1;
		for(i=2;i<1000001;++i)
		{
				div[i]=cntdiv(i);


		}
}
void funk(void)
{
		int i;
		int tmp;
		int j,k;
		int flag;
		a=0;
		for(i=2;i<1000001;++i)
		{
				if(div[i]>3)
				{
						for(j=1;j*j<=i;++j)
						{
								flag=0;
								if(i%j==0 && div[i]%div[j]!=0)
								{
										flag=-1;
										break;
								}
								k=i/j;
								if(i%k==0 && div[i]%div[k]!=0)
								{
										flag=-1;
										break;
								}
						}
						if(flag==0) ans[a++]=i;

				}


		}
		for(i=0;i<10;++i)
				printf("%d ",ans[i]);
		puts("");
}
int main()
{
		siever();
		divs();
		funk();
		int i;
		for(i=0;i<a;i++)
				printf("%d\n",ans[i]);

		return 0;
}
