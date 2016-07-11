#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 12345678901
ll mull(ll a, ll b)
{
		ll res = 0;
		while(b)
		{
				if(b&1) res = (res+a)%MOD;
				a = (a+a)%MOD;
				b /= 2;
		}
		return res;
}
ll modexp(ll a, ll b)
{
		if(a == 1 || b == 1) return a;
		ll res = 1;
		while(b)
		{
				if(b&1) res = mull(res,a);
				a = mull(a,a);
				b/=2;
		}
		return res;
}
void mul(ll A[2][2] , ll B[2][2])
{
		int i,j,k;
		ll C[2][2];
		for(i=0;i<2;++i)
		{
				for(j=0;j<2;++j)
				{
						C[i][j] = 0;
						for(k=0;k<2;++k)
								C[i][j] = (C[i][j] + mull(A[i][k],B[k][j]))%MOD;
				}
		}
		for(i=0;i<2;++i)
		{
				for(j=0;j<2;++j)
						A[i][j]=C[i][j];
		}
}
void matexp(ll M[2][2], ll b)
{
		if(n == 1) return;
		ll RES[2][2] = {1,0,0,1};
		while(b)
		{
				if(b&1) mul(RES,M);
				mul(M,M);
				b/=2;
		}
		int i,j;
		for(i=0;i<2;++i)
		{
				for(j=0;j<2;++j)
						M[i][j] = RES[i][j];
		}
}
ll ans(ll n)
{
		if(n <= 2) return n;
		ll M[2][2] = {1,1,1,0};
		matexp(M,n-1);
		ll ab = (M[0][0]*2 + M[0][1])%MOD;
		if(ab < 0) ab+=MOD;
		return ab;
}
int main()
{
		/*ll A[2][2]={1,2,0,1};
		  matexp(A,2);
		  int i,j;
		  for(i=0;i<2;++i)
		  {
		  for(j=0;j<2;++j)
		  cout<<A[i][j]<<" ";
		  cout<<endl;
		  }*/
		int t;
		cin>>t;
		ll n;
		while(t--)
		{
				scanf("%lld",&n);
				printf("%lld\n",ans(n));
		}
}
