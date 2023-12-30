#include <stdio.h>
#include <malloc.h>

struct node
{
  int data;
  struct node *next;
};

void insert_at_beg(struct node **q,int num);
void insert_at_last(struct node **q,int num);
void insert_at_middle(struct node **q,int num,int loc);
void delete_at_beg(struct node **q);
void delete_at_last(struct node **q);
void delete_at_middle(struct node **q,int num);
void count(struct node *q);
void display(struct node *q);
void search(struct node *q,int num);

int main()
{
 int ch,ele,loc;
 struct node *head;
 do
 {
    printf("1->insert at begging\n");
    printf("2->insert at last\n");
    printf("3->insert at middle\n");
    printf("4->delete at begging\n");
    printf("5->delete at last\n");
    printf("6->delete at middle\n");
    printf("7->count a node\n");
    printf("8->display a node\n");
    printf("9->search a node\n");
    printf("10->exit\n");
    printf("Enter a valid choice\t:-");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("Enter a number\t:-");
        scanf("%d",&ele);
        insert_at_beg(&head,ele);
        break;
      case 2:
        printf("Enter a number\t:-");
        scanf("%d",&ele);      
        insert_at_last(&head,ele);
        break;
      case 3:
        printf("Enter a number\t:-");
        scanf("%d",&ele);
        printf("Enter a location\t:-");
        scanf("%d",&loc);
        insert_at_middle(&head,ele,loc);
        break;
      case 4:
        delete_at_beg(&head);
        break;
      case 5:
        delete_at_last(&head);
        break;
      case 6:
        printf("Enter a number\t:-");
        scanf("%d",&ele);
        delete_at_middle(&head,ele);
        break;
      case 7:
        count(head);
        break;
      case 8:
        display(head);
        break;
      case 9:
        printf("Enter a number\t:-");
        scanf("%d",&ele);
        search(head,ele);
        break;
      case 10:
        printf("exit a linked list\n");
        break;
      default:
        printf("invalid choice\n");
    }
  }while(ch != 10);
  return 0;
}
void insert_at_beg(struct node **q,int num)
{
  printf("%p\n",q);
  struct node *temp,*newnode;
  printf("befor malloc %p\n",newnode);
  newnode = malloc(sizeof(struct node));
  printf("after malloc %p\n",newnode);
  newnode->data = num;
  printf("befor  %x\n",temp->next);
  newnode->next = *q;
  printf("after %x\n",temp->next);
  *q = newnode;
}
void insert_at_last(struct node **q,int num)
{
  struct node *temp,*newnode;
  newnode = malloc(sizeof(struct node));
  newnode->data = num;
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
void insert_at_middle(struct node **q,int num,int loc)
{
  struct node *temp,*newnode;
  temp = *q;
  for(int i = 0;i<loc-1;i++)
  {
    temp = temp->next;
    if(temp == NULL)
    {
      printf("wrong location\n");
      return;
    }
  }
  newnode = malloc(sizeof(struct node));
  newnode->data = num;
  newnode->next = temp->next;
  temp->next = newnode;
}
void delete_at_beg(struct node **q)
{
  struct node *temp;
  temp = *q;
  *q = temp->next;
  free(temp);
}
void delete_at_last(struct node **q)
{
  struct node *temp,*old;
  temp = *q;
  while(temp->next != NULL)
  {
    temp = old;
    temp = temp->next;
  }
  temp->next = old->next;
  free(temp);
}
void delete_at_middle(struct node **q,int num)
{
  struct node *temp,*old;
  temp = *q;
  while(temp->next != NULL)
  {
    if(num == temp->data)
    {
      temp->next = old->next;
      free(temp);
      return;
    }
    temp = old;
    temp = temp->next;
  }
}
void count(struct node *q)
{
  int count = 0;
  while(q != NULL)
  {
    count++;
    q = q->next;
  }
  printf("total node is = %d\n",count);
}
void display(struct node *q)
{
  while(q != NULL)
  {
     printf("%d\t ",q->data);
     q = q->next;
  }
  printf("\n");
}
void search(struct node *q,int num)
{
  while(q != NULL)
  {
    if(num == q->data)
    {
      printf("find a number %d\n",q->data);
      return;
    }
    q = q->next;
  }
  printf("not found\n");
}
