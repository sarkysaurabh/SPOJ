#include<stdio.h>
#include<string.h>
//int Graph[10001][10001];
int Graph[10005][10005];
int visited[10005];
struct stack 
{
		int st[10005],top;
};
void push(struct stack *Myst, int ele)
{
		(Myst->top)++;
		Myst->st[Myst->top] = ele;
}
int pop(struct stack *Myst)
{
		int tmp;
		tmp = Myst->st[Myst->top];
		(Myst->top)--;
		return tmp;
}
int isempty(struct stack *Myst)
{
		return Myst->top == -1;
}
int dfs_long(int n)
{
		int max=0;
		int dist[10005];
		int i;
		for(i=0;i<=n;++i)
		{
				dist[i]=0;
				visited[i]=3;
				//white= 3, black =0, gray=1
		}
		struct stack Myst;
		Myst.top=-1;
		push(&Myst,1);
		int curr;
		dist[1] = 0;
		int src;
		int t=2;
		src=1;
		int maxv=0;
		while(t--)
		{
				for(i=0;i<=n;++i)
				{
						dist[i]=0;
						visited[i]=3;
						//white= 3, black =0, gray=1
				}
				dist[src]=0;
				push(&Myst,src);

				while(!isempty(&Myst))
				{
						curr = pop(&Myst);
						//printf("curr = %d\n",curr);
						for(i=1;i<=n;++i)
						{
								//printf("i=%d & visited[i] = %d\n",i,visited[i]);
								if(Graph[curr][i] == 1 && visited[i] == 3)				
								{
										//printf("came in for i=%d\n",i);
										push(&Myst,i);
										dist[i] = dist[curr] + 1;
										if(dist[i] > max) 
										{
												max = dist[i];
												maxv = i;
										}
										visited[i] = 1;
								}
						}
						visited[curr] = 0; // turn black
				}
				src=maxv;
		}
		return max;
}
int main()
{
		int n;
		memset(Graph,0,sizeof(Graph));
		memset(visited,0,sizeof(visited));
		scanf("%d",&n);
		int i;
		int a,b;
		for(i=0;i<n-1;++i)
		{
				scanf("%d %d",&a,&b);
				Graph[a][b] = 1;
				Graph[b][a] = 1;
		}
		int j;
		/*for(i=1;i<=n;++i)
		  {		for(j=1;j<=n;++j)
		  printf("%d ",Graph[i][j]);
		  printf("\n");
		  }*/
		printf("%d\n",dfs_long(n));
}
