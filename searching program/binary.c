#include <stdio.h>
int main()
{
  int arr[100],n,key,l,u,m,i;
  printf("Enter size of array\t");
  scanf("%d",&n);
  printf("Enter a array\n");
  for(i = 0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("Enter a key you want find\t");
  scanf("%d",&key);
  l = 0;
  u = n-1;
  m = (l+u)/2;
  while(l <= u)
  {
    if(arr[m]<key)
      l = m+1;
    else if(arr[m] == key)
    {
      printf("found a element %d\n",arr[m]);
      break;
    }
    else
      u = m-1;
    m = (l+u)/2;
  }
  if(l > u)
    printf("not found\n");
  return 0;
}

