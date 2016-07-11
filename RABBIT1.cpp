#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//#define MOD 1048576
int MOD;
void multiply(ll A[2][2], ll B[2][2])
{
		ll RES[2][2];
		int i,j,k;
		for(i=0;i<2;++i)
		{
				for(j=0;j<2;++j)
				{
						RES[i][j]=0;
						for(k=0;k<2;++k)
						{
								RES[i][j] = (RES[i][j]%MOD + (A[i][k] * B[k][j])%MOD)%MOD;
						}
				}
		}
		for(i=0;i<2;++i)
		{
				for(j=0;j<2;++j)
				A[i][j] = RES[i][j];
		}
}
void matexp(ll A[2][2], ll p)
{
		if(p==1) return;
		ll RES[2][2]={1,0,0,1};
		while(p)
		{
				if(p&1) multiply(RES,A);
				multiply(A,A);
				p/=2;
		}
		for(int i=0;i<2;++i)
		{
				for(int j=0;j<2;++j)
				A[i][j]=RES[i][j]%MOD;
		}
}
ll ans(ll n)
{
		if(n<=2) return n;
		ll  M[2][2]={1,1,1,0};
		matexp(M,n-2);
		return ((2*M[0][0])%MOD + M[0][1])%MOD;
}
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				int n,m;
				cin>>n>>m;
				MOD = 1<<m;
				//cout<<MOD<<endl;
				cout<<ans(n)%MOD<<endl;
		}
		return 0;
}
