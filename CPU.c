#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int primes[MAX];
int sieve[MAX];
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
				//cout<<"done for i="<<i<<"\n";
		}
		//cout<<"completed"<<"\n";
		//for(i=0;i<100;++i)
		//cout<<primes[i]<<" ";
}
int ck(long long int n)
{
		int i,j,prm1,prm2;
		int cnt=0;
		for(i=0;i<pr && primes[i]*primes[i]<=n;++i)
		{
				if(n%primes[i]==0 && cnt==0)
				{
						cnt++;
						prm1=primes[i];
				}
				else if(n%primes[i]==0 && cnt==1)
				{
						cnt++;
						prm2=primes[i];
						break;
				}
		}
		//cout<<"prm1="<<prm1<<" prm2="<<prm2<<"\n";
		if(cnt==2)
		{
				n/=prm1;
				n/=prm2;
				long long int prm3,a,b;
				if((prm2 - prm1) % (prm1 - 1) != 0) return false;
				a=(prm2-prm1)/(prm1-1);
				b=prm1-a;
				while(n!=1)
				{
						prm3=a*prm2+b;
						if(n%prm3==0)
						{
								cnt++;
								n/=prm3;
						}
						else return false;
						prm2=prm3;
				}
				if(cnt>=3) return true;
				else return false;
		}
		else return false;
}
int main()
{
		long long int n=4505;
		siever();
		long long int i;
		for(i=30;i<100000000;++i)
		{
				if(ck(i)) cout<<i<<endl;
		}
}
