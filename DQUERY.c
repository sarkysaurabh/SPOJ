#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define gc getchar_unlocked

inline void write_int(int x)
{
#ifdef USE_SIGN
		if (x < 0)
		{
				putchar('-');
				x = -x;
		}
#endif

		char buf[10], *p = buf;
		do
		{
				*p++ = '0' + x % 10;
				x /= 10;
		}
		while (x);
		do
		{
				putchar(*--p);
		}
		while (p > buf);
}

inline int read_int()
{
		char c;

		while (c = getchar(), c <= ' ');

#ifdef USE_SIGN
		bool sign = c == '-';
		if (sign)
		{
				c = getchar();
		}
#endif

		int res = c - '0';
		while (c = getchar(), c >= '0' && c <= '9')
		{
				res = res * 10 + (c - '0');
		}
		// One character is gobbled here

#ifdef USE_SIGN
		return sign ? -res : res;
#else
		return res;
#endif
}
inline void scanint(int &x)
{
		register int c = gc();
		x = 0;
		int neg = 0;
		for(;((c<48 || c>57) && c != '-');c = gc());
		if(c=='-') {neg=1;c=gc();}
		for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
		if(neg) x=-x;
}
int arr[MAX];
int block;
struct node
{
		int s,e,ind;
} que[20*MAX];
bool mo(node a, node b)
{
		int block_a = a.s/block;
		int block_b = b.s/block;
		if(block_a != block_b)
				return a.e < b.e;
		return block_a < block_b;
}
int mark[MAX];
int answer[MAX*20];
int main()
{	
		optimizar_io
				int n;
		int i;
		int q;
		int mo_left,mo_right,left,right;
		int ind;
		int dis = 0;
		int a_idx;
		scanint(n);
		for(i=0;i<n;++i)
				scanint(arr[i]);
		scanint(q);
		for(i=0;i<q;++i)
		{
				scanint(que[i].s);
				scanint(que[i].e);
				que[i].ind = i;
		}
		block = 555;
		sort(que,que+q,mo);
		mo_left = 0;
		mo_right = -1;
		memset(mark,0,sizeof(mark));
		for(i=0;i<q;++i)
		{
				left = que[i].s-1;
				right = que[i].e-1;
				a_idx = que[i].ind;
				while(mo_right < right)
				{
						mo_right++;
						mark[arr[mo_right]]++;
						if(mark[arr[mo_right]] == 1) dis++;
				}
				while(mo_right > right)
				{
						mark[arr[mo_right]]--;
						if(mark[arr[mo_right]] == 0) dis--;
						mo_right--;
				}
				while(mo_left < left)
				{
						mark[arr[mo_left]]--;
						if(mark[arr[mo_left]] == 0) dis--;
						mo_left++;
				}
				while(mo_left > left)
				{
						mo_left--;
						mark[arr[mo_left]]++;
						if(mark[arr[mo_left]] == 1) dis++;
				}
				answer[a_idx] = dis;
		}
		for(i=0;i<q;++i)
		{
				write_int(answer[i]);	
				putchar('\n');
		}

}
