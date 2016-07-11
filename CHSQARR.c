#include<bits/stdc++.h>
using namespace std;
#define MAX 1002
#define ll long long int
int mat[MAX][MAX];
ll bits[MAX][MAX];
int bitm[MAX][MAX];
void updatem(int x, int y, int val)
{
		int y1;
		while(x <= MAX)
		{
				y1 = y;
				while(y1 <= MAX)
				{
						bitm[x][y1] = 
				}
		}
}
int main()
{
		int n,m;
		int i;
		int j;
		cin>>n>>m;
		for(i=1;i<=n;++i)
		{
				for(j=1;j<=m;++j)
				{
						cin>>mat[i][j];
						updates(mat[i][j],i,j);
						updatem(mat[i][j],i,j);
				}
		}

}
