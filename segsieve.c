#include<bits/stdc++.h>
using namespace std;
void sieve(int lim, vector<int> &vt)
{
		int i,j;
		int mark[lim+1];
		memset(mark,0,sizeof(mark));
		for(i=2;i*i<=lim;++i)
		{
				if(mark[i]==0)
				{
						for(j=i*2;j<=lim;j+=i)
						{
								mark[j]=1;		
						}
				}
		}
		for(i=2;i<=lim;++i)
		if(!mark[i]) vt.push_back(i);
}
void segsieve(int n)
{
		int low,high,tmp,llim,lim;
		lim=floor(sqrt(n))+1;
		vector<int> vt;
		sieve(lim,vt);

		low=lim;
		high=2*lim;

		while(low<high)
		{
				bool mark[lim+1];
				memset(mark,true,sizeof(mark));
				int i;
				for(i=0;i<vt.size();++i)
				{
						llim=floor(low/vt[i])*vt[i];
						if(llim<low) llim+=vt[i];

						for(int j=llim;j<=high;j+=vt[i])
						mark[j-low]=false;

				}
				for(i=0;i<lim+1;++i)
				{
						if(mark[i]) cout<<i<<" ";
				}
				cout<<endl;
				low=low+lim;
				high=high+lim;
				if(high>n) high=n;
		}

}
int main()
{
		vector<int> vt;
		int lim=100;
		segsieve(lim);
		return 0;
}
