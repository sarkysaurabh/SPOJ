#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000006
int dis[MAX];
int fr[MAX];
int bk[MAX];
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				ll sum = 0;
				ll tmp;
				ll beg;
				ll end;
				int n;
				cin>>n;
				int i;
				for(i=0;i<n;++i)
				{
						cin>>dis[i];
						if(i>0 && i<n-1)
								sum+=dis[i];
				}
				fr[0] = dis[0];
				for(i=1;i<n;++i)
				{
						fr[i]=fr[i-1]+dis[i];
				}
				ll a,b;
				ll mind = INT_MAX;
				for(i=1;i<n-1;++i)
				{
						a = fr[i-1];
						b = fr[n-2] - fr[i] + dis[n-1];
						mind = min(mind,a+2*b);
						mind = min(mind,b+2*a);
						//cout<<"a="<<a<<" b="<<b<<endl;
				}
				beg = dis[0];
				end = dis[n-1];
				mind = min(sum+beg,mind);
				mind = min(sum+end,mind);
				cout<<mind<<endl;

		}
}
