/*This is linked list full program covers traversing, Insertion and deletion from beginning, specified position and from the end.
This program is created by Dr. Krishan Kumar Goyual (Associate Professor and Dean, Faculty of Computer Application, RBSMTC, Agra.)
If you have any query/doubt and suggestions please email me on kkgoyal@gmail.com .*/
#include"stdio.h"
#include"malloc.h"
#include"conio.h"
#include"ctype.h"
struct link
{
  int data;
  struct link *next;

};

struct link start,*previous,*new1;

void create_link_list(struct link *);
void display(struct link*);
void insert(struct link *);
void delete_node(struct link *);

void delete_node(struct link *node)
{ char ch;
int node_number=1,delete_node;
node=start.next;
previous=&start;
  printf("\nEnter your choice from where do you want to delete a node\n");
  printf("\n1. From begining press B");
  printf("\n2. From End press E");
  printf("\n3. From a specified location I");
  fflush(stdin);
  ch=tolower(getchar());

  switch(ch)
  {
  case 'b':

	if(node==NULL)
	{
	printf("\nUnderflow\n");
	}
	else
	{
	previous->next=node->next;
	free(node);
	}
	break;
   case 'e':
	if(node==NULL)
	{
	printf("\nUnderflow\n");
	}
	else
	{
	 while(node->next!=NULL)
	 {
	  node=node->next;
	  previous=previous->next;
	  node_number++;
	 }
	 printf("Before deleting the node No. %d Data Value %d Total no of nodes are:%d",node_number,node->data,node_number);
	 previous->next=node->next;
	 free(node);
	}
	break;
   case 'i':
	printf("\nInput node number you want to delete\n");
	scanf("%d",&delete_node);
	while(node)
	{
	  if((node_number)==delete_node)
	  { previous->next=node->next;
	  free(node);
	  break;
	  }
	  else
	  {node=node->next;
	  previous=previous->next;
	  }
	  node_number++;
	}
	break;
	default:
	printf("\nThis is not a choice\n");
  }
  }

void insert(struct link *node)
{
  char ch;
  int node_number=1,insert_node_number;
  node=start.next;
  previous=&start;
  printf("\nEnter your choice where do you want to insert\n");
  printf("\n1. At begening press B");
  printf("\n2. At End press E");
  printf("\n3. In between two nodes press I");
  fflush(stdin);
  ch=tolower(getchar());

  switch(ch)
  {
  case 'b':
  new1=(struct link*)malloc(sizeof(struct link));
  new1->next=node;
  previous->next=new1;
  printf("\nInput the first node value\n");
  scanf("%d",&new1->data);
  break;
  case 'e':
  while(node)
  {
  node=node->next;
  previous=previous->next;
  }
  if(node==NULL)
  {
  new1=(struct link*)malloc(sizeof(struct link));
  new1->next=node;
  previous->next=new1;
  printf("\nInput the last node value\n");
  scanf("%d",&new1->data);
  }
  break;
  case 'i':
  printf("Enter the node no.\n");
  scanf("%d",&insert_node_number);
  while(node)
  {
  if(node_number==insert_node_number)
  {
  new1=(struct link*)malloc(sizeof(struct link));
  new1->next=node;
  previous->next=new1;
  printf("\nInput the node value\n");
  scanf("%d",&new1->data);
  break;
  }
  else
  {
  node=node->next;
  previous=previous->next;
  }
  node_number++;
  }
  break;
  default:
  printf("This is not a choice\n");
  }
}

void create_link_list(struct link *node)
{
  char ch;
  start.next=NULL;
  node=&start;
  while(ch!='n')
  {
  node->next=(struct link *)malloc(sizeof(struct link));
  node=node->next;
  printf("Enter data for link list\n");
  scanf("%d",&node->da/ta);
  node->next=NULL;
  printf("\n Input choice n for break:\n");
  fflush(stdin);
  ch=getchar();
  }

}
void display(struct link *node)
{
//   clrscr();
   node=start.next;
   printf("Link list elements are as follows:\n");
   printf("START ->");
   while(node)
   {
   // printf("%u[",node);
    printf("%d\t",node->data);
    node=node->next;
   }
   printf("NULL");
}
main()
{
char ch;
struct link *a=(struct link *)malloc(sizeof(struct link));
//clrscr();
create_link_list(a);
display(a);

printf("\nDo you want to insert a new node in link list(Y/N)\n");
fflush(stdin);
ch=tolower(getchar());
while(ch=='y')
{
insert(a);
printf("\nDo you want to insert a new node in link list(Y/N)\n");
fflush(stdin);
ch=tolower(getchar());
}
display(a);
getch();
printf("\nDo you want to delete a node from link list(Y/N)\n");
fflush(stdin);
ch=tolower(getchar());
while(ch=='y')
{
delete_node(a);
printf("\nDo you want to delete a new node from link list(Y/N)\n");
fflush(stdin);
ch=tolower(getchar());
}

printf("After deleting the first node the link list is as follows\n");
display(a);
getch();
}
