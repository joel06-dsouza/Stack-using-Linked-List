#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
   int data;
   struct node *next;
}node;

struct node * top=NULL;
void display();
void push(int val);
int pop();
void peep();

int main()
{
   int val,ch;
   
   while(1)
   {
   
     printf("\n\nMenu:\n1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit");
	 printf("\nEnter your choice: ");
	 scanf("%d",&ch);
	 switch(ch)
    {
	   case 1:
	          printf("Enter data: ");
			  scanf("%d",&val);
			  push(val);
			  break;
	   case 2:
	          val=pop();
			  if(val!=-1)
			      printf("Element popped=%d",val);
			  break;
	   case 3: peep();break;
	   case 4: display();break;
	   case 5: exit(0);
	    	  
	}
   }
}

void display()
{
  node * ptr;
  ptr= top;
  if(ptr==NULL)
  {
     printf("Empty Stack");
	 return;
  }
  printf("\nElements in the stack are: ");
  while(ptr!=NULL)
  {
    printf("\t%d",ptr->data);
	ptr=ptr->next;
  }
}


void push(int val)
{
  node *newnode=malloc(sizeof(node));
  newnode->data=val;
  newnode->next=top;
  top=newnode;
  
}

int pop()
{
   int val=-1;
   node * ptr;
   if(top==NULL)
      printf("Stack Empty!!");
   else
   {
      ptr=top;
	  val=top->data;
	  top=top->next;
	  free(ptr);
   }
   return val;
}

void peep()
{
  if(top==NULL)
     printf("Stack  Empty!!!");
  else
  {
    printf("Element at top=%d",top->data);
  }
}

