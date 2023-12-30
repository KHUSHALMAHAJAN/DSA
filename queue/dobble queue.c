#include<stdio.h>
#define size 5
int front = -1,rear = -1,queue[size],ch,ele;
void equeue_at_front(void);
void equeue_at_back(void);
void dequeue_at_front(void);
void dequeue_at_back(void);
void display(void);
int main()
{
  do
  {
    printf("1->equeue at front\n");
    printf("2->equeue at back\n");
    printf("3->equeue at front\n");
    printf("4->equeue at back\n");
    printf("5->display\n");
    printf("6->exit\n");
    printf("Enter a vaild choice\t:-");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        equeue_at_front();
        break;
      case 2:
        equeue_at_back();
        break;
      case 3:
        dequeue_at_front();
        break;
      case 4:
        dequeue_at_back();
        break;
      case 5:
        display();
        break;
      case 6:
        printf("Exit a queue\n");
    }
  }while(ch != 6);
}
void equeue_at_front(void)
{
  if(front == size-1)
  {
    printf("queue is overflow\n");
    return;
  }
  else
  {
    printf("Enter a element\t:-");
    scanf("%d",&ele);
    if(rear == -1)
    {
      front = rear = 0;
      queue[front] = ele;
    }
    else if(rear == 0)
    {
      for(int i = front;i>=rear;i--)
      {
        queue[i+1] = queue[i];
        front++;
      }
      queue[rear] = ele; 
    }  
    else
    {
      rear--;
      queue[rear] = ele;
    }
  }
}
void equeue_at_back(void)
{
  if(front == size-1)
  {
    printf("queue is overflow\n");
    return;
  }
  else
  {
    printf("Enter a element\t:-");
    scanf("%d",&ele);
    if(rear == -1)
    {
      front = rear = 0;
      queue[front] = ele;
    }
    else
    {
      front++;
      queue[front] = ele;
    }
  }
}
void dequeue_at_front(void)
{
  if(rear == -1)
  {
    printf("queue is underflow\n");
    return;
  }
  else
  {
    printf("remove a elemnet od %d",queue[rear]);
    rear++;
    if(front == rear)
    {
      front = rear = -1;
    }
  }
}
void dequeue_at_back(void)
{
  if(rear == -1)
  {
    printf("queue is underflow\n");
    return;
  }
  else
  {
    printf("remove a elemnet od %d",queue[front]);
    front--;
    if(front == rear)
    {
      front = rear = -1;
    }    
  }
}
void display(void)
{
  for(int i = rear;i<=front;i++)
  {
    printf("%d\t  ",queue[i]);
  }
  printf("\n");
}
