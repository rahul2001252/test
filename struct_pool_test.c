#include <stdio.h>

#include "struct_pool_test.h"


Rectangle *rpool;
Rectangle rpool_nodes[MAX_POOL_SIZE];


//Rectangle **rpool_pptr = &rpool;

void clear_node(Rectangle *ptr)
{
  ptr->id=0;
  for(int i=0; i<VTX_CNT; i++)
  {
    ptr->v[i].x=0;
    ptr->v[i].y=0;
  }
  for(int i=0;i<DESC_LEN;i++)
  {
    ptr->desc[i] = 0;
  }
}

void init_rpool(Rectangle **rpool_pptr)
{
  Rectangle *temp_ptr;
  *rpool_pptr = &rpool_nodes[0];
  temp_ptr= *rpool_pptr;
  for(int i=0; i<MAX_POOL_SIZE-1; i++)  
  {
    clear_node(temp_ptr);
    temp_ptr->pool_index=i;
    temp_ptr->next = &rpool[i+1];
    temp_ptr=temp_ptr->next;
  }
  temp_ptr->next = NULL;
}

void display_rpool(Rectangle *rpool)
{
  if(!rpool)
   printf("Error: NULL Pointer Encountered\n");
  else
  {
    int count_node=0;
    Rectangle *node_ptr;
    for(node_ptr = rpool; node_ptr!=NULL; node_ptr=node_ptr->next)
    {
      //printf("Node Index : %d\n",node_ptr->index);
      count_node++;
    }
    printf("Number of element in rpool is %d\n", count_node);
  }
}
  
Rectangle *alloc_rpool_node(Rectangle **rpool_pptr)
{
  Rectangle *temp_ptr;
  temp_ptr = *rpool_pptr;
  *rpool_pptr = temp_ptr->next;
  temp_ptr->next = NULL;
  return temp_ptr;
}

void free_pool_node(Rectangle  **rpool_pptr, Rectangle *rpool)
{
  if(!*rpool_pptr || !rpool)
   printf("Error: NULL Pointer Encountered\n");
  else
  {
    rpool->next=*rpool_pptr;
    *rpool_pptr = rpool;
  }
}  

int main()
{
  Rectangle *alloc_node;
  Rectangle *node_array[10];
  
  init_rpool(&rpool);
  display_rpool(rpool);
  
  for(int i=0;i<10;i++)
  {
    alloc_node = alloc_rpool_node(&rpool);
  }
  display_rpool(rpool);
  
  display_rpool(alloc_node); 
  
  free_pool_node(&rpool, alloc_node);
  display_rpool(rpool);
  
  for(int i=0;i<10;i++)
  {
   node_array[i]=alloc_rpool_node(&rpool);
   printf("\nNode allocated %x - %x",node_array[i], &rpool[node_array[i]->pool_index]);
   printf("\n");
   if(node_array[i]!=&rpool[node_array[i]->pool_index])
    printf("Address Mismatch\n");
  }
  for(int i=9;i>5;i--)
  {
    free_pool_node(&rpool, node_array[i]);
    node_array[i]= NULL;
  }
  display_rpool(rpool);
  
  
}

