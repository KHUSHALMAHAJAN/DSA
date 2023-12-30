#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

int top = -1;
char infix[max],postfix[max];
char stack[max];

void push(char);
char pop();
int is_empty();
void intopost();
int space(char);
void print();
int precedence(char);

int main()
{
  printf("Enter the infix expression: ");
  scanf("%s",infix);
  intopost();
  print();
  return 0;
}
void intopost()
{
  int i,j=0;
  char next;
  char symbol;
  for(i=0;i<strlen(infix);i++)
  {
    symbol = infix[i];
    if(!space(symbol))
    {
      switch(symbol)
      {
        case '(':
          push(symbol);
          break;
        case ')':
          while((next = pop()) != '(')
          {
            postfix[j++] = next;
          }
          break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': 
          while(!is_empty() && precedence(stack[top]) >= precedence(symbol))
          {
            postfix[j++] = pop();
          }
          push(symbol);
          break;
          default:
            postfix[j++] = symbol;
         }
      }
  }
  while(!is_empty())
  {
     postfix[j++] = pop();
  }
  postfix[j] = '\0';
}
int space(char c)
{
  if(c == ' '||c == '\t')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int precedence(char symbol)
{
  switch(symbol)
  {
    case '^':
      return 3;
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return 0;
    }
  }
void print()
{
  int i=0;
  printf("The equivalent postfix expression is: ");
  while(postfix[i])
  {
    printf("%c",postfix[i++]);
  }
  printf("\n");
}
void push(char c)
{
   if(top == max - 1)
   {
     printf("stack overflow\n");
   }
   top++;
   stack[top] = c;
}
char pop()
{
  char c;
  if(top == -1)
  {
    printf("stack undreflow\n");
    exit(1);
  }
  c = stack[top];
  top = top - 1;
  return c;
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
