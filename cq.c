#include<stdio.h>
#define SIZE 50
struct que
{
		int q[SIZE],head,tail;
};
int isempty(struct que *Myq)
{
		return Myq->head == -1;
}
int isfull(struct que *Myq)
{
		if((Myq->head == Myq->tail + 1) || (Myq->head == 0 && Myq->tail == SIZE-1)) return 1;
		return 0;
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
int main()
{
		struct que Myq;
		Myq.head = Myq.tail = -1;
		printf("enq 10 \n");
		enq(&Myq,10);
		printf("enq 20 \n");
		enq(&Myq,20);
		printf("enq 30 \n");
		enq(&Myq,30);
		printf("enq 40 \n");
		enq(&Myq,40);
		printf("enq 50 \n");
		enq(&Myq,50);
		printf("enq 60 \n");
		enq(&Myq,60);
		printf("enq 70 \n");
		enq(&Myq,70);
		printf("enq 80 \n");
		enq(&Myq,80);
		printf("enq 90 \n");
		enq(&Myq,90);
		printf("%d\n",deq(&Myq));
		printf("%d\n",deq(&Myq));
		printf("%d\n",deq(&Myq));
		printf("%d\n",deq(&Myq));
		printf("%d\n",deq(&Myq));
		printf("%d\n",deq(&Myq));
		printf("%d\n",deq(&Myq));
		printf("%d\n",deq(&Myq));
		printf("%d\n",deq(&Myq));
		printf("%d\n",deq(&Myq));

}
