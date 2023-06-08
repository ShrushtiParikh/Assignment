#include "file.h"
#include "fun.h"

struct link *start = NULL;
struct link *ptr  = NULL;

void main()
{
//	struct link *start;
	struct link *new = malloc(sizeof(struct link));
	printf("Please Enter number for node\n");
	scanf("%d",&new->node);
	new->next = NULL;
	start = new;
	ptr = new;
	
	for(int i = 1 ; i < 5 ; i++)
	{
		struct link *now = malloc(sizeof(struct link));
		printf("Please Enter number for node\n");
		scanf("%d",&now->node);
		now->next = NULL;
		ptr->next = now;
		ptr = now;
	}
//	printf("start : %d\n",start->node);
//	printf("data : %d\n",ptr->node);
//	printf("operations\n");
	display();
	reverse();
	insert_at_start(10);
	insert_at_end(40);
	insert_at_middle(20,5);
	delete_first();
	delete_end();
	delete(2);
	display();
//	reverse();
}


