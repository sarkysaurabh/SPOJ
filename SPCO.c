#include<stdio.h>
#define ll long long int
#define MAX 1000000
int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
int mark[100];
ll ncr[65][65];
ll memo[MAX+5][65];
ll memo_cnt[65][65];
void makeTriangle(void)
{
		int i,j;
		ncr[0][0] = 1;
		for(i = 0; i < 65; ++i)
				ncr[i][0] = 1;
		for(i = 1; i < 65; ++i)
		{
				for(j = 1; j < 65; ++j)
						ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
		}

}
ll count(int cnt, int sum)
{
		if(memo_cnt[cnt][sum] != -1) return memo_cnt[cnt][sum];
		int prm[18];
		int i;
		int p = 0;
		int tmp;
		for(i=0;i<18;++i)
		{
				tmp = primes[i] - sum;
				if(tmp > 0 && tmp <= cnt) prm[p++] = primes[i] - sum;
		}
		ll sums  = 0;
		for(i = 0; i < p; ++i)
		{
				sums += ncr[cnt][prm[i]];
		}
		return memo_cnt[cnt][sum] = sums;

}
ll ans(ll n, ll sum)
{
		//if(n <= 0) return 0;
		if(n< MAX)
		{
				if(memo[n][sum] != -1) return memo[n][sum];
		}
		if(n <= 1)
		{
				if(mark[sum+n] == 1) return 1;
				else return 0;
		}
		ll one;
		int i;
		int cnt = 0;
		for(one = 1; one < n; one<<=1)
				cnt++;
		if(one == n+1 || one == n)
		{
				if(n < MAX)
				{
						if(one == n+1) return memo[n][sum] = count(cnt,sum);
						else return memo[n][sum] = count(cnt,sum) + ans(0,sum+1);
				}
				else
				{
						if(one == n+1) return count(cnt,sum);
						else return count(cnt,sum) + ans(0,sum+1);
						
				}
		}
		if(one >= n) cnt--;
		if(one > n) one>>=1;
		ll a1 = count(cnt,sum);
		ll a2 = ans(n&(one - 1),sum+1);
		if(n < MAX) memo[n][sum] = a1+a2;
		return a1+a2;
}
int main()
{
		int t;
		ll n;
		ll r;
		ll ans1;
		ll ans2;
		makeTriangle();
		for(int i=0;i<18;++i)
				mark[primes[i]]++;
		for(int i=0;i<MAX+4;++i)
		{
				for(int j = 0;j <= 64; ++j)
						memo[i][j] = -1;
		}
		for(int i=0;i<65;++i)
		{
				for(int j = 0;j < 65; ++j)
						memo_cnt[i][j] = -1;
		}
		scanf("%d",&t);
		while(t--)
		{

				//cin>>n>>r;
				scanf("%lld %lld",&n,&r);
				ans1 = ans(r,0);
				ans2 = ans(n-1,0);
				//cout<<"ans1="<<ans1<<" ans2="<<ans2<<endl;
				//cout<<ans1 - ans2<<endl;
				printf("%lld\n",ans1-ans2);
		}
}
