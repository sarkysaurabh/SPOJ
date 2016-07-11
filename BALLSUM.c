#include<bits/stdc++.h>
using namespace std;
long long int sum(long long int n)
{
		return n*(n+1);
}
long long int fre(long long int n)
{
		return (n-1)/2;
}
long long int fred(long long int n, long long int lim)
{
		return (2*lim - n + 1)/2;
}
int main()
{
		long long int n,k,p,all,t1,t2,g;
		cin>>n>>k;
		while(1)
		{
				if(n==-1 && k==-1) break;
				
				if((n+1)%2==1) 
				{
						t1=sum(fre(n+1))-fre(n+1);
				}
				else 
				{
						t1=sum(fre(n+1));
				}
				
				if((n+2)%2==1)
				t2=sum(fred(n+2,n))-fred(n+2,n);
				else		
				t2=sum(fred(n+2,n));
				
				all=t1+t2;
				

				
				if(k < 3) p = 0;
				else if(k >= 2*n -1) p=all;
				else
				{
						if(k<=n+1)
						{
								if(k%2==1)
								{
										p=sum(fre(k)) - fre(k);
								}
								else
								{
										p=sum(fre(k));
								}
						}
						else
						{
								k++;
								if(k%2==1)
								{
										p = all - (sum(fred(k,n)) - fred(k,n));
								}
								else
								{
										p = sum(fred(k,n));
								}
						}
						
				}

				if(p==all) cout<<"1"<<endl;
				else if(p==0) cout<<"0"<<endl;
				else 
				{
						g=__gcd(p,all);
						p/=g;
						all/=g;

						cout<<p<<"/"<<all<<endl;
				}
				cin>>n>>k;



		}
		return 0;
}
