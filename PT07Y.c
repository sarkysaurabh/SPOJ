#include<stdio.h>
int parent[10001];
int size[10001];
void makeset(int i)
{
		parent[i]=i;
		size[i]=1;
}
int findset(int i)
{
		if(parent[parent[i]] != parent[i])
				parent[i] = findset(parent[i]);
		return parent[i];
}
int union_set(int a, int b)
{
		int parent_a = findset(a);
		int parent_b = findset(b);
		if(parent_a == parent_b) return -1; 
		if(size[parent_a] > size[parent_b])
		{
				parent[parent_b] = parent_a;
				size[parent_a] += size[parent_b];
		}
		else
		{
				parent[parent_a] = parent_b;
				size[parent_b] += size[parent_a];
		}
		return 1;
}
int main()
{
		int n,m;
		int a,b;
		int i;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;++i)
		{
				makeset(i);
		}
		int flag = 0;
		for(i=0;i<m;++i)
		{
				scanf("%d %d",&a,&b);
				flag = union_set(a,b);
				if(flag == -1) break;
		}
		if(flag == -1) printf("NO\n");
		else printf("YES\n");
		
}
