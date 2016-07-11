#include<bits/stdc++.h>
using namespace std;
int arr[1000006];
int main()
{
		int t;
		//cin>>t;
		scanf("%d",&t);
		while(t--)
		{
				int n;
				int i;
				int b;
				//cin>>n>>b;
				scanf("%d %d",&n,&b);
				for(i=0;i<n;++i)
						scanf("%d",arr+i);
						//cin>>arr[i];
				int sum = 0;
				int j;
				int cnt = 0;
				int mdis = INT_MIN;
				int msum = INT_MAX;
				for(i=0,j=0;i<n&&j<n&&i<=j;)
				{
						if(sum >= b)
						{
								sum-=arr[i];
								++i;
								cnt--;
						}
						else if(sum < b)
						{
								sum+=arr[j];
								++j;
								cnt++;
						}
						if(sum <= b)
						{
								if(mdis < cnt)
								{
										mdis = cnt;
										msum = sum;
								}
								if(mdis == cnt)
								{
										msum = min(msum,sum);
								}
						}
				}
				printf("%d %d\n",msum,mdis);
				//cout<<msum<<" "<<mdis<<endl;
				
		}
}
