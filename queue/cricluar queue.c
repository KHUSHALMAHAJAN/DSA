#include <stdio.h>
# define num 5
int front = -1,rear = -1,ch,ele,queue[num];
void equeue(void);
void dequeue(void);
void display(void);
int main()
{
  do
  {
    printf("1->equeue\n");
    printf("2->dequeue\n");
    printf("3->display\n");
    printf("4->exit\n");
    printf("Enter a valied chioce\t:-");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        equeue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Your exit\n");
        break;
      default:
        printf("plz Enter a vaild chice\n");
    }
    printf("front = %d\trear = %d\n",front,rear);
  }while(ch != 4);
}
void equeue(void)
{
  if((front == num-1 && rear == 0)||(front == rear - 1))
  {
    printf("queue is overflow\n");
    return;
  }
  else
  {
    printf("Enter a  element\t:-");
    scanf("%d",&ele);
    if(rear == -1 || front == num - 1)
    {
      if(front == -1) 
      {
        rear = 0;
      }
      front = 0;
      queue[front] = ele;
    }
    else
    {
      front++;
      queue[front] = ele;
    }
  }
}
void dequeue(void)
{
  if(rear == -1)
  {
    printf("queue is underflow\n");
    return;
  }
  else
  {
    printf("remove element is %d\n",queue[rear]);
    if(rear == front - 1)
    {
      rear = front = -1;
      printf("1 part run\n");
    }
    else if(rear == num - 1)
    {
      rear = 0;
      printf("2 part run\n");
    }
    else if(front == rear)
    {
      rear = front = -1;
      printf("3 part run\n");
    } 
    else
    {
      rear++;
      printf("4 part run\n");
    }  
  }
}
void display(void)
{
  if(front >= rear)
  {
    for(int i = rear;i<=front;i++)
    {
      printf("%d\t ",queue[i]);
    }
    printf("\n");
  }
  else
  {
    for(int i = rear;i<=num-1;i++)
    {
      printf("%d\t  ",queue[i]);
    }
    for(int i = 0;i<=front;i++)
    {
      printf("%d\t  ",queue[i]);
    }
    printf("\n");
  }
}
