#include <stdio.h>
#include <stdlib.h>
#define num 5

int front = -1;
int rear = -1;
int queue[num];

void enqueue(int x);
void dequeue();
void display();

int main()
{
  int ch,x;
  while(1)
  {
    printf("**** menu ****\n");
    printf(" 1.insert\n 2.delete\n 3.display\n 4.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("Enter a number :  ");
        scanf("%d",&x);
        enqueue(x);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
    }
  }
  return 0;
}
void enqueue(int x)
{
  if(rear >= num-1)
  {
    printf("queue is overflow\n");
  }
  else
  {
    rear++;
    //printf("%d\n",rear);
    queue[rear] = x;
    if(front = -1)
    {
      front++;
    }
  }
}
void dequeue()
{
  if(front == -1)
  {
    printf("queue is underflow\n");
  }
  else
  {
    printf("delete element is %d\n",queue[front]);
    if(rear == front)
      {
        front = -1;
        rear = -1;
      }
    else
      {
        front++;
      }
  }
}
void display()
{
  if(rear == -1)
  {
    printf("queue is underflow\n");
  }
  int i;
  printf("print a element is :\t");
  for(i = front;i<=rear;i++)
  {
    printf("%d\t",queue[i]);
  }
  printf("\n");
}
