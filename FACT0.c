#include<bits/stdc++.h>
using namespace std;
#define MAX 40000000
int sieve[MAX];
int primes[MAX];
int pr;
void siever(void)
{
		int i,j;
		pr=0;
		for(i=2;i<MAX;++i)
		{
				if(sieve[i]==0)
				{
						primes[pr++]=i;
						for(j=i*2;j<MAX;j+=i)
						sieve[j]=1;
				}
		}

}
void factor(long long int n)
{
		int i,cnt;
		for(i=0;primes[i]*primes[i]<=n && i<pr;++i)
		{
				cnt=0;
				while(n%primes[i]==0)
				{
						n/=primes[i];
						cnt++;
				}
				if(cnt>0) cout<<primes[i]<<"^"<<cnt<<" ";
		}
		if(n>1) cout<<n<<"^"<<"1";
		cout<<endl;
}
int main()
{
		siever();
		long long int n;
		cin>>n;
		while(n)
		{
				factor(n);	
				cin>>n;
		}
}
