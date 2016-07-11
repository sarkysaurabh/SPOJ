#include<bits/stdc++.h>
using namespace std;
void pstar(int n)
{
		if(n==1) return;
		while(n--)
		{
				printf("*");
		}
}
void pdot(int n)
{
		while(n--)
		{
				printf(".");
		}
}

int main()
{
		int t;

		cin>>t;
		while(t--)
		{
				int r,c,s;
				scanf("%d %d %d",&r,&c,&s);
				int rr,cc,ss;
				rr=r;
				cc=c;
				ss=s;
				int i,j,k,m,p,tmp,l;
				while(rr--)
				{
						for(l=1;l<=s;++l)
						{
								cc=c;
								while(cc--)
								{
										if(s-l>0) 
										{
												pdot(s-l);
										}
										{
												printf("/");
												pstar(2*(l-1));
												printf("\\");
												if(s-l>0) pdot(s-l);
										}
								}
								printf("\n");	
						}
						for(l=s;l>=1;--l)
						{
								cc=c;
								while(cc--)
								{
										if(s-l>0) 
										{
												pdot(s-l);
										}
										printf("\\");
										pstar(2*(l-1));
										printf("/");
										if(s-l>0) pdot(s-l);
								}
								printf("\n");	
						}
				}
				printf("\n");
		}

		return 0;
}
