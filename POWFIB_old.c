#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
#define MAX 900000000
//int arr[MAX];
int modmul(int a, int b)
{
		if(b==1) return a;
		int res=0;
		while(b)
		{
				if(b%2) res=(res+a)%MOD;
				a=(a*2)%MOD;
				b/=2;
		}
		return res;

}
void matmul(int A[2][2], int B[2][2])
{
		int C[2][2];
		int i,j,k;
		for(i=0;i<2;++i)
		{
				for(j=0;j<2;++j)
				{
						C[i][j]=0;
						for(k=0;k<2;++k)
						{
								C[i][j] = (C[i][j] + modmul(A[i][k],B[k][j]))%MOD;
						}
				}
		}
		for(i=0;i<2;++i)
		{
				for(j=0;j<2;++j)
						A[i][j] = C[i][j];
		}

}
void modpow(int A[2][2], int p)
{
		if(p<=1) return;
		int RES[2][2]={{1,0},{0,1}};
		int i,j;
		while(p)
		{
				if(p%2==1) matmul(RES,A);
				matmul(A,A);
				p/=2;
		}
		for(i=0;i<2;++i)
		{
				for(j=0;j<2;++j)
						A[i][j] = RES[i][j];
		}
}
int matex(int n)
{
		if(n<=2) return 1;
		int A[2][2] = {{1,1},{1,0}};
		modpow(A,n);
		return A[0][1]%MOD;

}
int modexp(int a, int b)
{
		if(b==1) return a;
		int res=1;
		while(b)
		{
				if(b%2==1) res=modmul(res,a);
				a=modmul(a,a);
				b/=2;
		}
		return res;
}
int nonfibo(int n)        //nth non-fibonacci number
{
		ll a = 1, b = 2, c = 3;
		while(n>0)
		{
				a = b;
				b = c;
				c = (a+b)%MOD;
				n-=(c-b-1);
				
		}
		n+=(c-b-1);
		return (n + b)%MOD;
}
/*void fibo(void)
{
		int i;
		arr[1]=arr[2]=1;
		for(i=3;i<MAX;++i)
		arr[i]=(arr[i-1]+arr[i-2])%MOD;
}*/
int main()
{
		int t;
		//fibo();
		cin>>t;
		while(t--)
		{
				int n,a,b;
				cin>>n;
				//a=arr[n]%MOD;
				a=matex(n)%MOD;
				b=nonfibo(n)%MOD;
				//cout<<"a="<<a<<" b="<<b<<endl;
				cout<<modexp(b,a)%MOD<<endl;

		}
		//cout<<matex(t)<<endl;
		/*ll A[2][2]={1,2,1,-1};
		  matmul(A,A);
		  for(int i=0;i<2;++i)
		  {
		  for(int j=0;j<2;++j)
		  cout<<A[i][j]<<" ";
		  cout<<endl;
		  }*/
		return 0;
}
