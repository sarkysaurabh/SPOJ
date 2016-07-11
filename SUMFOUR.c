#include<bits/stdc++.h>
#define MAX 10000005
#define MAX2 4005
#define ll long long int
using namespace std;
int va[MAX2],vb[MAX2],vc[MAX2],vd[MAX2],vp1[2*MAX],vp2[2*MAX];
int vt[2][2*MAX];
int main()
{
		int n,tmp,s1,s2;
		cin>>n;
		int a,b,c,d;
		for(int i=0;i<n;++i)
		{
				scanf("%d %d %d %d",&va[i],&vb[i],&vc[i],&vd[i]);
		}
		tmp=0;
		for(int i=0;i<n;++i)
		{
				for(int j=0;j<n;++j)
				{
						vp1[tmp++]=va[i]+vb[j];			
				}
		}
		s1=tmp;
		tmp=0;
		for(int i=0;i<n;++i)
		{
				for(int j=0;j<n;++j)
				{
						vp2[tmp++]=-(vc[i]+vd[j]);				
				}
		}
		s2=tmp;
		sort(vp1,vp1+s1);
		sort(vp2,vp2+s2);
		int cnt = 1;
		int i=0;
		int s3;
		tmp = 0;
		vp1[s1] = vp1[s1-1] + 1;
		for(i=1;i<=s1;++i)
		{
				if(vp1[i] == vp1[i-1]) 
						cnt++;
				else {
						vt[1][tmp] = vp1[i-1];
						vt[2][tmp++] = cnt;
						cnt = 1;
				}
		}
		s3=tmp;
		long long int sum=0;
		int j=0;
		i=0;
		while(i < s3 && j < s2)
		{
				if(vt[1][i] > vp2[j])
						j++;
				else if(vt[1][i] < vp2[j])
						i++;
				else
				{
						sum += vt[2][i];
						j++;
				}
		}
		cout<<sum<<endl;
}

