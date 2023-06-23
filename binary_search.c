#include <stdio.h>
#include "binary_search.h"

int arr[SIZE];
int get_int_array(int *arr)
{
 int count=0,temp;
 do
 {
     printf("Enter array elements\n");
       scanf("%d",&temp);
     
     if(temp ==-1)
       break;
     else
     {
       arr[count]= temp;
       count++;
     }
     
 }while(count<SIZE);
 return count;
}

void sort_array(int arr[], int size) 
{
    int i, j;
    for (i = 0; i < size-1; i++) 
    {
        for (j = 0; j < size-i-1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[],int count, int target) 
{
  int left=0;
  int mid;
  int right = count-1;
    while (left <= right) 
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;

       else
            right = mid - 1;
    }

}

int binary_search_main()
{
  int target,result=0;
  int arr_count = get_int_array(arr);
  printf("%d\n",arr_count);
  sort_array(arr,arr_count);
  printf("Array after sorting\n");
  for(int i=0;i<arr_count;i++)
   printf("%d\t",arr[i]);
  printf("\nEnter Target\n");
   scanf("%d",&target);
  result=binarySearch(arr,arr_count,target);
  if(target==0)
   printf("Target not found");
  else
   printf("Target found at %d location\n",result);
}

#ifndef RELOCATABLE_OBJ
int main()
{
 binary_search_main();
}
#endif 
   
  
   
   

