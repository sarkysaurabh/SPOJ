#include<stdio.h>
#include<string.h>
int Graph[10005][10005];
int visited[10005];
int dist[10005];
#define SIZE 10000
struct que
{
		int q[10005],head,tail;
};
int isempty(struct que *Myq)
{
		return Myq->head == -1;
}
int isfull(struct que *Myq)
{
		return ((Myq->tail + 1 == Myq->head) || (Myq->head == 0 && Myq->tail == SIZE-1));
}
void enq(struct que *Myq, int ele)
{
		if(!isfull(Myq))
		{
				if(Myq->head == -1) Myq->head = 0;
				Myq->tail = (Myq->tail + 1)%SIZE;
				Myq->q[Myq->tail] = ele;
		}
		else
		{
				printf("Overflow!\n");
		}
}
int deq(struct que *Myq)
{
		if(!isempty(Myq))
		{
				int tmp;
				tmp = Myq->q[Myq->head];
				if(Myq->head == Myq->tail) Myq->head = Myq->tail = -1;
				else Myq->head = (Myq->head + 1)%SIZE;
				return tmp;
		}
		else
		{
				printf("Underflow!\n");
				return -1;
		}
}
int bfs_dia(int n)
{
		int i,curr,src;
		struct que Myq;
		Myq.head = Myq.tail = -1;
		for(i=0;i<=n;++i)
		{
				dist[i] = 0;
				visited[i] = 3;
				//black = 0, white = 3, gray = 1
		}
		int lastv,maxd;
		maxd = 0;
		int t=2;
		lastv = 1;
		while(t--)
		{
				for(i=0;i<=n;++i)
				{
						dist[i] = 0;
						visited[i] = 3;
						//black = 0, white = 3, gray = 1
				}
				//printf("goin to just enq %d\n",lastv);

				enq(&Myq,lastv);
				//printf("just enq %d\n",lastv);
				while(!isempty(&Myq))
				{
						curr = deq(&Myq);
						for(i=1;i<=n;++i)
						{
								if(Graph[curr][i] == 1 && visited[i] == 3)
								{
										visited[i] = 1;

										//printf("goin to just enq %d\n",i);
										enq(&Myq,i);
										//printf("just enq %d\n",i);
										dist[i] = dist[curr] + 1;
										if(dist[i] > maxd) maxd = dist[i];
								}
						}
						visited[curr] = 0;
						lastv = curr;
				}
		}
		return maxd;

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
		printf("%d\n",bfs_dia(n));
}
