#include <stdio.h>
int main()
{
  int arr[100],n,key,temp,i,j;
  printf("Enter size of array\t");
  scanf("%d",&n);
  printf("Enter a array\n");
  for(i = 0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  for(i=0;i<(n-1);i++)
  {
    for(j=0;j<(n-i);j++)
    {
      if(arr[j]>arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  printf("sorted element are : \n");
  for(i = 0;i<n;i++)
  {
    printf("%d\n",arr[i]);
  }
  printf("\n");
  return 0;
}
