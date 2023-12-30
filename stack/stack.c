#include <stdio.h>
#define size 5
int stack[size],top,i,ch,ele;
int is_empty();
int is_full();
void push();
void pop();
void display();
void peek();
int main()
{
  top = -1;
  printf("\t Stack operation on array\n");
  printf("\t 1.push\n \t 2.pop\n \t 3.display\n \t 4.peek\n \t 5.exit\n"); 
  do
  {
    printf("Enter operation number\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        display();
        break;
      case 4: 
        peek();
        break;
      default:
        printf("Enter a vailed number (1,2,3,4)\n");
    }
  }while(ch!=5);
  return 0;
}
int is_full()
{
  if(top == size-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void push()
{
 int a;
  if(is_full() == 1)
  {
    printf("Stack is overflow\n");
  }
  else
  {
    printf("Enter a number in stack\t");
    scanf("%d",&a);
    top++;
    stack[top] = a;
  }
}
int is_empty()
{
  if(top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void pop()
{
  if(is_full() == 1)
  {
    printf("stack is underflow\n");
  }
  else
  {
    printf("%d element is poped\n",stack[top]);
    top--;
  }
}
void display()
{
  printf("stack in element = ");
  for(i=top;i>=0;i--)
  {
    printf("%d  ",stack[i]);
  }
  printf("\n");
}
void peek()
{
  printf("last element in stack %d\n",stack[top]);
}
   
