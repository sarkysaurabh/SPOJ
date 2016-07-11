#include<bits/stdc++.h>
using namespace std;
#define MAX 4005
int arr2[MAX*MAX];
int arr[4][MAX];
int main()
{
		int n;
		int i;
		int j;
		unsigned long long int  cnt = 0;
		int val;
		int p;
		p = 0;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
				scanf("%d%d%d%d",&arr[0][i],&arr[1][i],&arr[2][i],&arr[3][i]);
		}
		for(i=0;i<n;++i)
		{
				for(j=0;j<n;++j)
				{
						arr2[p++] = arr[0][i]+arr[1][j];
				}
		}
		sort(arr2,arr2+p);
		for(i=0;i<n;++i)
		{
				for(j=0;j<n;++j)
				{
						val = -(arr[2][i]+arr[3][j]);
						cnt += upper_bound(arr2,arr2+p,val) - lower_bound(arr2,arr2+p,val);
				}

		}
		printf("%llu\n",cnt);
}
