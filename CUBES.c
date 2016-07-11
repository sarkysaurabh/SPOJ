#include<bits/stdc++.h>
using namespace std;
int main()
{
		int a,b,c,d;
		int i,j,k,m;
		for(i=6;i<101;++i)
		{
				a=i*i*i;
				for(j=2;j<i;++j)
				{
						b=j*j*j;
						if(a-b>0)
						{
								for(k=2;k<i;++k)
								{
										c=k*k*k;
										if(a-b-c>0)
										{
												for(m=2;m<i;++m)
												{
														d=m*m*m;
														if(a==b+c+d && b<=c && c<=d)
														{
																printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,m);	
														}
												}
										}
								}
						}
				}
		}
}
