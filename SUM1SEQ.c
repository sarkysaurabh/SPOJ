#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int arr[100005];
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
				int n;
				ll s;
				cin>>n>>s;
				long long int max_sum;
				max_sum = n*(n-1)/2;
				if(s > max_sum || s < -max_sum) puts("No");
				else
				{
						if((n+s)%2==0)
						{
								int i;
								ll csum = 0;
								int pre = 0;
								for(i=1;i<n;++i)
								{
										if((s-csum)>pre) 
										{
												pre++;
												arr[i]=pre;
												csum+=pre;
										}
										else
										{
												pre--;
												arr[i]=pre;
												csum+=pre;
										}
								}
								if(csum == s)
								{
										puts("0");
										for(i=1;i<n;++i)
												cout<<arr[i]<<endl;
								}
								else puts("No");
						}
						else puts("No");
				}
				puts("");
		}
}
