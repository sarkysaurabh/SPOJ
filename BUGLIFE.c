#include<stdio.h>
#include<string.h>
#define SIZE 2005
int Graph[SIZE][SIZE];
int color[SIZE];
struct stack
{
		int st[SIZE],top;		
};
int isempty(struct stack *Myst)
{
		return Myst->top == -1;
}
int isfull(struct stack *Myst)
{
		return Myst->top == SIZE - 1;
}
void push(struct stack *Myst, int ele)
{
		if(!isfull(Myst))
		{
				(Myst->top)++;
				Myst->st[Myst->top] = ele;
		}
		else
		{
				printf("Overflow\n");
		}
}
int pop(struct stack *Myst)
{
		if(!isfull(Myst))
		{
				int tmp = Myst->st[Myst->top];
				(Myst->top)--;
				return tmp;
		}
		else
		{
				printf("Underflow\n");
				return -1;
		}
}
int bp(int n)
{
		memset(color,0,sizeof(color));
		int i,j;
		//red = 1, green = 3, uninitialize = 0
		int curr;
		int visited[SIZE];//={3};
		for(i=0;i<SIZE;++i)
		{
				visited[i]=3;
		}
		//white=3 gray=1, black=0
		struct stack Myst;
		Myst.top = -1;
		push(&Myst,1);
		color[1] = 1; //red
		int vt=0;
		while(!vt)
		{
				while(!isempty(&Myst))
				{
						curr = pop(&Myst);
						//printf("curr=%d\n",curr);
						for(i=1;i<=n;++i)
						{
								if(Graph[curr][i] == 1)
								{
										//printf("found edge at %d\n",i);
										if(color[curr] == color[i]) 
										{
												//printf("going to return -1 for curr=%d and i=%d\n",curr,i);
												return -1;
										}
										else if(color[curr] == 1)
												color[i] = 3;
										else color[i] = 1;
										if(visited[i] == 3) push(&Myst,i);
								}
						}
						visited[curr] = 0;
				}
				for(i=1;i<=n;++i)
				{
						if(visited[i] == 3)
						{
								vt=0;
								push(&Myst,i);
								color[i]=1;
								break;
						}
						else
						{
								vt++;						
						}
				}
		}
		return 1;
}
int main()
{
		int t;
		int n,m;
		int i;
		int a,b;
		scanf("%d",&t);
		int cp;
		cp=1;
		while(t--)
		{
				memset(Graph,0,sizeof(Graph));
				scanf("%d %d",&n,&m);
				for(i=0;i<m;++i)
				{
						scanf("%d %d",&a,&b);	
						Graph[a][b] = 1;
						Graph[b][a] = 1;
				}
				int j;
				/*for(i=1;i<=n;++i)
				  {
				  for(j=1;j<=n;++j)
				  printf("%d ",Graph[i][j]);
				  printf("\n");
				  }*/
				if(bp(n) == 1) printf("Scenario #%d:\nNo suspicious bugs found!\n",cp++);
				else printf("Scenario #%d:\nSuspicious bugs found!\n",cp++);
		}
}
