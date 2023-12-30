#include <stdio.h>
#include <malloc.h>
struct node
{
  int data;
  struct node *R_next;
  struct node *L_next;
};
void insert_at_begin(struct node **q,struct node **lt);
void insert_at_end(struct node **lt,struct node **q);
void delete_at_begin(struct node **q,struct node **lt);
void delete_at_end(struct node **lt,struct node **q);
void display_at_begin(struct node *q);
void display_at_end(struct node *lt);

int main()
{
 int ch;
 struct node *head = NULL,*last = NULL;
 do
 {
   printf("1-> inserting from begin\n");
   printf("2-> inserting from end\n");
   printf("3-> deleting from begin\n");
   printf("4-> deleting from end\n");
   printf("5-> display from begin\n");
   printf("6-> display from end\n");
   printf("7->EXIT\n");
   printf("Enter a choice\t:-  ");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
       insert_at_begin(&head,&last);
       break;
     case 2:
       insert_at_end(&last,&head);
       break;
     case 3:
       delete_at_begin(&head,&last);
       break;
     case 4:
       delete_at_end(&last,&head);
       break;
     case 5:
       display_at_begin(head);
       break;
     case 6:
       display_at_end(last);
       break;
     case 7:
        printf("EXIT\n");
        break;
     default:
        printf("Invalid choice\n");
   }
 }while(ch != 7);
}
void insert_at_begin(struct node **q,struct node **lt)
{
   struct node *newnode;
   newnode = malloc(sizeof(struct node));
   printf("Enter a element\t:-  ");
   scanf("%d",&newnode->data);
   if(*q == NULL)
   {
     newnode->R_next = NULL;
     newnode->L_next = NULL;
     *q = newnode;
     *lt = newnode;
     printf("1\n");
   }
   else
   {
     newnode->R_next = NULL;
     newnode->L_next = *q;
     (*q)->R_next = newnode;
     *q = newnode;
   }
}
void insert_at_end(struct node **lt,struct node **q)
{
   struct node *newnode,*temp;
   newnode = malloc(sizeof(struct node));
   printf("Enter a element\t:-  ");
   scanf("%d",&newnode->data);
   if(*q == NULL)
   {
     newnode->R_next = NULL;
     newnode->L_next = NULL;
     *lt = newnode;
     *q = newnode;
   }
   else
   {
     newnode->R_next = *lt;
     newnode->L_next = NULL;
     (*lt)->L_next = newnode;
     *lt = newnode;
   }
}    
void delete_at_begin(struct node **q,struct node **lt)
{
  if(*q == NULL)
  {
    printf("list is empty\n");
  }
  else
  {
    if(*q == *lt)
    {
      *q = *lt = NULL;
    }
    else
    {
      struct node *temp;
      temp = *q;
      *q = temp->L_next;
      (*q)->R_next = NULL;
      free(temp);
    }
  }
}
void delete_at_end(struct node **lt,struct node **q)
{
  if(*q == NULL)
  {
    printf("list is empty\n");
  }
  else
  {
    if(*q == *lt)
    {
      *q = *lt = NULL;
    }
    else
    {
      struct node *temp;
      temp = *lt;
      *lt = temp->R_next;
      (*lt)->L_next = NULL;
      free(temp);
    }
  }
}
void display_at_begin(struct node *q)
{
  while(q != NULL)
  {
    printf("%d  ",q->data);
    q = q->L_next;
  }
  printf("\n");
}
void display_at_end(struct node *lt)
{
  while(lt != NULL)
  {
    printf("%d \t ",lt->data);
    lt = lt->R_next;
  }
  printf("\n");
}
