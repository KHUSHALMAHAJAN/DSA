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
    //printf("0\n");
  }
  else
  {
    if(num < (*r)->data)
      {
        //printf("2\n");
        insert((&(*r)->left),num);
        //printf("2\n");
      }
    else
      {
        //printf("3\n");
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
void inorder(struct node *r)
{
 if(r != NULL)
 {
   inorder(r->left);
   printf("%d -> ",r->data);
   inorder(r->right);
 }
}
void postorder(struct node *r)
{
  if(r != NULL)
  {
    postorder(r->left);
    postorder(r->right);
    printf("%d -> ",r->data);
  }
}
void serach(struct node *r,int num)
{
  if(r == NULL)
  {
    printf("not found\n");
  }
  else if(num == r->data)
  {
    printf("%d is found\n",num);
  }
  else if(num < r->data)
  {
    serach((r)->left,num);
  }
  else
  {
    serach((r)->right,num);
  }
}
int inorderpredecessor(struct node *r)
{
  while((r)->right != NULL)
  {
    r = (r)->right;
  }
  return r->data;
}
void delete(struct node **r,int num)
{
  struct node *temp;
  if(*r == NULL)
  {
     printf("Element not found\n");
  }
  if(num < (*r)->data)
  {
    delete((&(*r)->left),num);
  }
  else if(num > (*r)->data)
  {
    delete((&(*r)->right),num);
  }
  else
  {
    if((*r)->right == NULL)
    {
      temp = *r;
      *r = (*r)->left;
      free(temp);
    }
    else if((*r)->left == NULL)
    {
      temp = *r;
      *r = (*r)->right;
      free(temp);
    }
    else
    {
      int ipre = inorderpredecessor((*r)->left);
      (*r)->data = ipre;
      delete((&(*r)->left),ipre);
    }
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
    printf("3->inoder\n");
    printf("4->postoder\n");
    printf("5->serach\n");
    printf("6->delete\n");
    printf("7->exit\n");
    printf("choice\t");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        //printf("Enter a number\t");
        //scanf("%d",&ele);
        insert(&root,10);
        insert(&root,12);
        insert(&root,11);
        insert(&root,19);
        insert(&root,17);
        insert(&root,20);
        insert(&root,5);
        insert(&root,3);
        insert(&root,1);

      //  printf("value of %d\n",root->data);
        break;
      case 2:
        preorder(root);
        printf("\n");
        break;
      case 3:
        inorder(root);
        printf("\n");
        break;
      case 4:
        postorder(root);
        printf("\n");
        break;
      case 5:
        printf("Enter a number you wand to find\t");
        scanf("%d",&ele);
        serach(root,ele);
      case 6:
        printf("Enter a number you wand to delete\t");
        scanf("%d",&ele);
        delete(&root,ele);
        break;
      case 7:
        printf("exit\n");
        break;
      default:
        printf("invalid choice\n");
    }
  }while(ch != 7);
  return 0;
}
//in this code only understand insert a node and preorder display 
