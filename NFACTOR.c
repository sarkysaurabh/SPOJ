#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
int arr[]={0 , 2 , 2*3 , 2*3*5 , 2*3*5*7 , 2*3*5*7*11 , 2*3*5*7*11*13 , 2*3*5*7*11*13*17};
int sieve[MAX];
int vt[8][MAX];
void siever(void)
{
		int i,j;
		for(i=2;i<MAX;++i)
		{
				if(sieve[i]==0)
				{
						for(j=i;j<MAX;j+=i)
						sieve[j]++;;
				}
		}
}
void gen()
{
		int i,j;
		for(i=1;i<8;++i)
		{
				vt[i][1]=0;
				vt[i][0]=0;
				for(j=arr[i];j<MAX;++j)
				{
						vt[i][j]=vt[i][j-1] + (sieve[j]==i);
				}
		}

}
int main()
{
		siever();
		gen();
		int t;
		cin>>t;
		while(t--)
		{
				int a,b,n;
				cin>>a>>b>>n;
				if(n>7) cout<<"0"<<endl;
				else if(n==0 && a==1) cout<<"1"<<endl;
				else if(n==0 && a>1) cout<<"0"<<endl;
				else
				{
						cout<<vt[n][b]-vt[n][a-1]<<endl;
				}
		}
}
