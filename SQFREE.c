#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 10000000
int lp[MAX];
int primes[MAX];
int pr;
void siever(void)
{
		int i,j;
		pr=0;
		for(i=2;i<MAX;++i)
		{
				if(lp[i]==0)
				{
						primes[pr++]=i;
						for(j=i;j<MAX;j+=i)
								lp[j]=1;
				}
		}
		//for(i=0;i<100;++i)
		//cout<<primes[i]<<" ";
}
ll calc(ll n)
{
		ll prm = 1;
		ll sum = 0;
		ll init;
		ll res = 0; 
		int d;
		int i;
		int j;
		int flag = 0;
		for(d = 1; d < 9; ++d)
		{
				for(i = 0; i < pr - d; ++i)
				{
						init = 1;
						for(j = i; j < i + d - 1; ++j)
						{
								init *= primes[j]; 
								
						}
						if((init * primes[j]) * (init * primes[j]) > n) 
						{
								//flag = -1;
								break;
						}
						cout<<"d="<<d<<" init="<<init<<endl;
						sum = 0;
						for(; j < pr; ++j)
						{
								prm = init * primes[j];
								if(prm * prm > n) break;
								cout<<"prm="<<prm<<" prm2="<<prm*prm<<endl;
								sum += n / (prm * prm);
						}
						res += (ll)pow(-1,d-1)*sum;
						if(d==1) break;
				}
				//if(flag == -1) break;
		}
		return n - res;

}
int main()
{
		siever();
		int t;
		cin>>t;
		while(t--)
		{
				ll n;
				cin>>n;
				cout<<calc(n)<<endl;
		}
		return 0;
}

