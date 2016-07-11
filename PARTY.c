#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > cf;
int usedw;
int kp(int W,int n,int *mwt)
{
		if(W*n==0) 
		{
				return 0;
				*mwt=W;
		}
		if(cf[n-1].first > W) return kp(W,n-1,mwt);
		int meow1,meow2;
		meow1=*mwt-cf[n-1].first;
		meow2=*mwt;
		int r1 = cf[n-1].second + kp(W-cf[n-1].first,n-1,&meow1);
		int r2 = kp(W,n-1,&meow2);
		if(r1>=r2) 
		{
				*mwt = meow1;
				return r1;
		}
		else 
		{
				*mwt = meow2;
				return r2;
		}
}
int kp2(int W, int n, int *mwt)
{
		int table[n+1][W+1];
		int table2[n+1][W+1];
		int i,j;
		for(i=0;i<=n;++i)
		{
				for(j=0;j<=W;++j)
				{
						if(j*i==0) 
						{
								table[i][j]=0;
								table2[i][j]=0;
						}
						else if(cf[i-1].first <= j)
						{
								int r1=cf[i-1].second+table[i-1][j-cf[i-1].first];
								int r2=table[i-1][j];
								if(r1>=r2)
								{
										table[i][j]=r1;
										table2[i][j] = table2[i-1][j-cf[i-1].first]+cf[i-1].first;
								}
								else
								{
										table[i][j]=r2;
										table2[i][j] = table2[i-1][j];
								}
						}
						else
						{
								table[i][j]=table[i-1][j];
								table2[i][j]=table2[i-1][j];

						}
				}
		}
		for(i=1;i<=n;++i)
		{
				for(j=1;j<=W;++j)
				cout<<table2[i][j]<<" ";
				cout<<endl;
		}
		*mwt-=table2[n][W];
		return table[n][W];
}
int main()
{

		int b,n;
		cin>>b>>n;
		while(b!=0 && n!=0)
		{	
				for(int i=0;i<n;++i)
				{
						int ft,sd;
						cin>>ft>>sd;
						cf.push_back(make_pair(ft,sd));
				}
				sort(cf.begin(),cf.end());
				int mwt,ans;
				mwt=b;
				ans=kp2(b,n,&mwt);
				cout<<b-mwt<<" "<<ans<<endl;
				cf.clear();
				cin>>b>>n;
		}

}

