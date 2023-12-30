#include <stdio.h>
int main()
{
  int arr[100],n,key,i;
  printf("Enter size of array\t");
  scanf("%d",&n);
  printf("Enter a array\n");
  for(i = 0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("Enter a key you want find\t");
  scanf("%d",&key);
  for(i=0;i<n;i++)
  {
    if(arr[i] == key)
    {
      printf("find a key %d",key);
      break;
    }
  }
  if(i == n)
  printf("not found\n");
}
