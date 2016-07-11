#include<stdio.h>
#define MOD 1000000007
void mult(unsigned long long int M[2][2],unsigned long long int Md[2][2])
{
		unsigned long long int R[2][2];
		R[0][0]=((M[0][0]*Md[0][0])%MOD+(M[0][1]*Md[1][0])%MOD)%MOD;
		R[0][1]=((M[0][0]*Md[0][1])%MOD+(M[0][1]*Md[1][1])%MOD)%MOD;
		R[1][0]=((M[1][0]*Md[0][0])%MOD+(M[1][1]*Md[1][0])%MOD)%MOD;
		R[1][1]=((M[1][0]*Md[0][1])%MOD+(M[1][1]*Md[1][1])%MOD)%MOD;

		M[0][0]=R[0][0];
		M[0][1]=R[0][1];
		M[1][0]=R[1][0];
		M[1][1]=R[1][1];

}
void mpow(unsigned long long int M[2][2], long long int p)
{
		if(p==1) return;
		unsigned long long int Md[2][2]={{1,1},{1,0}};

		mpow(M,p/2);
		mult(M,M);
		if(p%2==1)
		{
				mult(M,Md);
		}
}
unsigned long long int fib(long long int n)
{
		if(n==0 || n==1) return n;
		else if(n==2) return 1;

		unsigned long long int M[2][2]={{1,1},{1,0}};
		mpow(M,n-1);
		return M[0][0];
}
int main()
{
		int t;
		scanf("%d",&t);
		while(t--)
		{
				/*int n,m;
				scanf("%d %d",&n,&m);
				unsigned long long tmp1,tmp2,res;
				tmp1=fib(m+2)%MOD;
				tmp2=fib(n+1)%MOD;
				res=tmp1-tmp2;
				if(res<0) res+=MOD;
				res%=MOD;
				printf("%llu\n",res);*/
				long long int n;
				scanf("%lld",&n);
				printf("%llu\n",fib(n+1));
				
		}
		return 0;
}

