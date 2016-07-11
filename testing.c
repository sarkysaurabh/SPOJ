#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int main()
{
		int arr[MAX];
		int i;
		for(i=0;i<MAX;++i)
				arr[i] = -1;
		// -1= undecide, 1 =winning, 0= lossing
		arr[0]=0;
		arr[1]=1;
		arr[2]=1;
		arr[3]=1;
		arr[4]=1;
		arr[5]=1;
		arr[6]=0;
		for(i=0;i<MAX;++i)
		{
				if(arr[i] == -1)
				{
						int wi,lo;
						wi = lo = 0;
						if(arr[i/2] == 0) lo++;
						else wi++;
						if(arr[i/3] == 0) lo++;
						else wi++;
						if(arr[i/4] == 0) lo++;
						else wi++;
						if(arr[i/5] == 0) lo++;
						else wi++;
						if(arr[i/6] == 0) lo++;
						else wi++;

						if(lo == 0) arr[i] = 0;
						else arr[i] = 1;
				}
		}
		for(i=0;i<MAX;++i)
				if(arr[i] == 0) cout<<i<<endl;
		cout<<endl;
}
