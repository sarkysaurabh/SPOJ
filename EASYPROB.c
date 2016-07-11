#include<bits/stdc++.h>
using namespace std;
void print(int n)
{
		int i,j,tmp,cnt;
		cnt=0;
		for(i=log2(n)+1;i>=0;--i)
		{
				if((1<<i)&n)
				{
						if(i<=2)
						{
								if(cnt==0)
								{
										if(i==0) printf("2(0)");
										else if(i==1) printf("2");
										else printf("2(2)");
								}
								else
								{
										if(i==0) printf("+2(0)");
										else if(i==1) printf("+2");
										else printf("+2(2)");
								}
						}
						else
						{
								if(cnt==0)
								{
										printf("2(");
										print(i);
										printf(")");
								}
								else
								{
										printf("+2(");
										print(i);
										printf(")");

								}
						}
						cnt++;
				}
		}
}
int main()
{
		int arr[]={137, 1315, 73, 136, 255, 1384, 16385};
		for(int i=0;i<7;++i)
		{
				printf("%d=",arr[i]);
				print(arr[i]);
				printf("\n");
		}
		return 0;
}
