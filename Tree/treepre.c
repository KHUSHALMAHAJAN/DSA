#include <stdio.h>
#include <malloc.h>
struct node 
{
  int data;
  struct node *left;
  struct node *right;
};
void insert(struct node **r,int num)
{
  if(*r == NULL)
  {
    //printf("0\n");
    *r = malloc(sizeof(struct node));
    (*r)->data = num;
    (*r)->right = NULL;
    (*r)->left = NULL;
    printf("0\n");
  }
  else
  {
    if(num < (*r)->data)
      {
        printf("2\n");
        insert((&(*r)->left),num);
        //printf("2\n");
      }
    else
      {
        printf("3\n");
        insert((&(*r)->right),num);
        //printf("3\n");
      }
  }
}
void preorder(struct node *r)
{
  if(r != NULL)
  {
    printf("%d  ",r->data);
    //printf(" **number4**");
    preorder(r->left);
    //printf("**number5**");
    preorder(r->right);
  }
}
int main()
{
  struct node *root = NULL;
  int ch,ele;
  do
  {
    printf("1->insert\n");
    printf("2->prioder\n");
    printf("3->exit\n");
    printf("choice\t");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("Enter a number\t");
        scanf("%d",&ele);
        insert(&root,ele);
        printf("value of %d\n",root->data);
        break;
      case 2:
        preorder(root);
        printf("\n");
        break;
      case 3:
        printf("exit\n");
        break;
      default:
        printf("invalid choice\n");
    }
  }while(ch != 3);
  return 0;
}
//in this code only understand insert a node and preorder display 
