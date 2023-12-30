#include <stdio.h>
#define size 20
char str[size];
int top,i;
void push(char ch);
void pop();
int main()
{
  top = -1;
  printf("Enter a string\t");
  scanf("%s",str);
  while(str[i] != '\0')
  {
    push(str[i]);
    i++;
  }
  printf("reverse string\n");
  while(top >= 0)
  {
    pop();
  }
  printf("\n");
  return 0;
}
void push(char ch)
{
  if(top == size-1)
  {
    printf("stack is overflow\n");
  }
  else
  {
     top++;
     str[top]= ch;
  }
}
void pop()
{
   if(top == -1)
   {
     printf("stack is underflow\n");
   }
   else
   {
     printf("%c",str[top]);
     top--;
    }
  } 
