#include<bits/stdc++.h>
using namespace std;
#define MAX 2005
int gs;
int ts;
int dps[MAX][MAX];
int girl[MAX];
int tom[MAX];
int funk(int i, int j)
{
		if(i >= gs || j >= ts) return 0;
		if(dps[i][j] != -1) return dps[i][j];
		if(girl[i] == tom[j]) 
				return dps[i][j] = 1+funk(i+1,j+1);
		return dps[i][j] = max(dps[i][j+1] = funk(i,j+1), dps[i+1][j] = funk(i+1,j));

}
int main()
{
		int t;
		cin>>t;
		int i;
		int mval;
		while(t--)
		{
				i = 0;
				mval = INT_MIN;
				while(true)
				{
						cin>>girl[i++];
						if(girl[i-1] == 0) break;
				}
				gs = i-1;
				while(true)
				{
						i=0;
						cin>>tom[i];
						if(tom[i] == 0) break;
						i++;
						while(true)
						{
								cin>>tom[i++];
								if(tom[i-1] == 0) break;
						}
						ts = i-1;
						memset(dps,-1,sizeof(dps));
						int fk = funk(0,0);
						//cout<<"fk="<<fk<<endl;
						mval=max(mval,fk);
				}
				cout<<mval<<endl;

		}
}
