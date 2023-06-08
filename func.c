#include "file.h"
//#include "fun.h"

//extern struct link;
extern struct link *start,*ptr;
void display()
{
	printf("Display\n");
	struct link *dis;
	dis = start;
//	printf("%d\n",dis->node);
	int node = 1;
	while(dis != NULL)
	{
		printf("node = %d\tdata = %d\n",node++,dis->node);
		dis = dis->next;
	}
}

void reverse()
{
	printf("reversed data\n");
	struct link *rev;
	rev = start;
	struct link *newhead = NULL;
	while(rev->next != NULL)
	{
		struct link *newnode = malloc(sizeof(struct link));
		newnode->node = rev->node;
		newnode->next = NULL;
		newnode->next = newhead;
		newhead = newnode;
		rev = rev->next;
/*		printf("newhead data : %d\n",newhead->node);
		printf("newnode data : %d\n",newnode->node);
		printf("rev data : %d\n",rev->node);*/
	}
	start = rev;
	start->next = newhead;
	display();
}

void insert_at_start(int data)
{
	struct link *newnode = malloc(sizeof(struct link));
	newnode->node = data;
	newnode->next = start;
	start = newnode;
}

void insert_at_end(int data)
{
	struct link *newnode = malloc(sizeof(struct link));
	newnode->node = data;
	newnode->next = NULL;
	struct link *end = start;
	while(end->next != NULL)
	{
		end = end->next;
	}
	end->node= newnode->node;
	end->next = NULL;
}

void insert_at_middle(int data,int after)
{
	struct link *newnode = malloc(sizeof(struct link));
	newnode->node = data;
	newnode->next = NULL;
	struct link *pos = start;
	struct link *temp;
	while(pos->node!=after)
	{
		pos =  pos->next;
		temp = pos->next;
	}
	pos->next = newnode;
	newnode->next = temp;
}

void delete_first()
{
	struct link *del;
	struct link *ptr;
	del = start;
	ptr = del->next;
	free(del);
	start = ptr;
}

void delete_end()
{
	struct link *del  = start;
	struct link *ptr;
	while(del->next != NULL)
	{
		ptr = del;
		del = del->next;
	}
	ptr->next = NULL;
	free(del);
}

void delete(int data)
{
	struct link *del = start,*ptr;
	while(del->node != data)
	{
		ptr = del;
		del = del->next;
	}
	ptr->next = del->next;
	free(del);
}
