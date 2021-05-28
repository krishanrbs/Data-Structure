/* Implementation of Linear Queue */
/*Program Created by Dr. K. K. Goyal (Associate Professor and Dean, Faculty of Computer Application, RBSMTC, Agra.)*/
/* Linear Queue.C */

#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#define max 11
struct queue
{  int front;
   int rear;
   int arr[max];
}q;

void create_q()
{  int i;
   q.front=q.rear=0;
   for(i=1;i<=max;i++)
   q.arr[i]=NULL;
}
void insert_q(int item)
{  if(q.rear==max)
   printf("Queue is overflow\n");
   else
   {
   q.rear++;
   q.arr[q.rear]=item;
   }

}

void delete_q()
{  if(q.rear==0)
   printf("Queue is underflow\n");
   else
   { if(q.rear==q.front)
     {
       q.rear=q.front=0;
     }
     else
     {
      q.front++;
      q.arr[q.front]=NULL;
     }

   }
}
void search()
{
 int ino;
 printf("Enter the item no:\n");
 scanf("%d",&ino);
 printf("\n%d",q.arr[ino]);

}
void display()
{  int i;
   printf("Queue is as follow:--\n");
   for(i=1;i<max;i++)
   printf("%d\t",q.arr[i]);
}

main()
{int x,i;
 //clrscr();
 while(x!=6)
 {
 printf("\n1 ) Create queue\n");
 printf("2 ) Insert queue\n");
 printf("3 ) Delete queue\n");
 printf("4 ) Display queue\n");
 printf("5 ) Search\n");
 printf("6 ) Exit\n");
 printf("Enter your choice\n");
 scanf("%d",&x);
 switch(x)
 {
  case 1:
	    create_q();
	    break;
  case 2:   printf("Enter the item");
	    scanf("%d",&i);
	    insert_q(i);
	    break;
  case 3:
	    delete_q();
	    break;
  case 4:
	    display();
	    break;
  case 5:
	    search();
	    break;
  case 6:
	    exit(0);
	    break;
  default:
	    printf("This is not a choice");
	    break;

 }
 }
 printf("\n");
 getch();
}
