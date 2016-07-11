#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006
int win[MAX];
int k,l,m;
int main()
{
		cin>>k>>l>>m;
		int i;
		for(i=0;i<MAX;++i)
				win[i] = -1;
		//-1 = undecided yet, 1 = winiing and 0 = losing
		win[1] = 1;
		win[k] = 1;
		win[l] = 1;
		win[0] = 0;
		for(i=0;i<MAX;++i)
		{
				if(win[i] == -1)
				{
						int wi,lo;
						wi = lo =0;
						if(i-1 >= 0)
						{
								if(win[i-1] == 0) lo++;
								else wi++;
						}
						if(i-k >= 0)
						{
								if(win[i-k] == 0) lo++;
								else wi++;
						}
						if(i-l >= 0)
						{
								if(win[i-l] == 0) lo++;
								else wi++;
						}
						if(lo == 0) win[i] = 0;
						else win[i] = 1;
				}
		}
		while(m--)
		{
				int n;
				cin>>n;
				if(win[n] == 1) printf("A");
				else printf("B");
		}
		printf("\n");
}
