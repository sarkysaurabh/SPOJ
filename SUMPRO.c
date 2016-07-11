#include<stdio.h>
long long int MOD = 1000000007;
long long int series(long long int N,long long int d1, long long int d2)
{
		long long int a,b,n_terms;
		a=N/d1;
		b=N/d2;
		n_terms=b-a;
		return ((n_terms*(a+b+1)/2)%MOD*d2)%MOD;
}
int main()
{
		int t;
		scanf("%d",&t);
		while(t--)
		{
				long long int n,tmp;
				scanf("%lld",&n);
				int i;
				long long int sum=0;
				for(i=1;i*i<=n;++i)
				{
						tmp=n/i;
						sum=(sum+tmp*i)%MOD;
				}
				for(i=1;i*i<n;++i)
				{
						sum=(sum+series(n,i+1,i))%MOD;
				}
				printf("%lld\n",sum);
		}
		return 0;
}
