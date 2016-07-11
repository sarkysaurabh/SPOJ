#include<bits/stdc++.h>
using namespace std;
int lp[9000];
int primes[9000];
int pr;
vector<int> vt;
int dps[8000][4];
void siever(void)
{
		int i,j;
		pr = 0;
		for(i=2;i<9000;++i)
		{
				if(lp[i] == 0)
				{
						primes[pr++]=i;
						for(j=i;j<9000;j+=i)
						{
								lp[j] = 1;		
						}
				}
		}
}
void gen(void)
{
		int i,j;
		for(i=1;i<=100;++i)
		{
				for(j=i;j<=100;++j)
				{
						if(binary_search(primes,primes+pr,i*i+j*j)) vt.push_back(i*i+j*j);
				}
		}
		sort(vt.begin(),vt.end());
}
int pint(int n, int m)
{
		if(dps[n][m] != -1) return dps[n][m];
		if(n == 0) return dps[n][m] = 1;
		if(m == 0) return dps[n][m] = 0;
		if(n < 0) return dps[n][m] = 0;
		return dps[n][m] = pint(n-m,m)+pint(n,m-1);
}
int funk(int n, int k)
{
		if(n<=0) return 0;
		if(k == 2 && n > 1)
		{
				return max(1+funk(n-1,k),1+funk(n-2,k));		
		}
		else if(k == 3 && n > 2)
		{
				return max(max(1+funk(n-1,k),1+funk(n-2,k)),1+funk(n-3,k));		

		}
}
int main()
{
		siever();
		gen();
		int i;
		int t;
		int n;
		int b;
		cin>>t;
		memset(dps,-1,sizeof(dps));
		while(t--)
		{
				cin>>n>>b;
				//cout<<pint(n,b)<<endl;
				cout<<pint(vt[n-1],b)<<endl;
		}
}
