#include<stdio.h>
#include<malloc.h>
struct node 
{
  int data;
  struct node *next;
};
void push(struct node **q);
void pop(struct node **q);
void display(struct node *q);
int main()
{
  int ch;
  struct node *head;
  head = NULL;
  do
  {
    printf("1->Push\n");
    printf("2->Pop\n");
    printf("3->Display\n");
    printf("4->EXIT\n");
    printf("Enter a choice\t:-  ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        push(&head);
        break;
      case 2:
        pop(&head);
        break;
      case 3:
        display(head);
        break;
      case 4:
        printf("EXIT\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  }while(ch != 4);
}
void push(struct node **q)
{
  struct node *newnode,*temp;
  newnode = malloc(sizeof(struct node));
  printf("Enter an element\t:-  ");
  scanf("%d",&newnode->data);
  newnode->next = NULL;
  if(*q == NULL)
  {
    *q = newnode;
  }
  else
  {
    temp = *q;
    while(temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newnode;
  }
}
void pop(struct node **q)
{
  struct node *old,*temp;
  temp = *q;
  while(temp->next != NULL)
  {
    old = temp;
    temp = temp->next;
  }
  old->next = temp->next;
  free(temp);
}
void display(struct node *q)
{
  if(q == NULL)
  {
    printf("list is empty\n");
  }
  else
  {
    while(q != NULL)
    {
      printf("%d   ",q->data);
      q = q->next;
    }
    printf("\n");
  }
}
