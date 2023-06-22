#include<stdio.h>
#include "struct_pool_test.h"

Rectangle *rpool;
Rectangle rpool_nodes[MAX_POOL_SIZE];

void free_node(Rectangle **rpool_pptr,Rectangle *node)
{
    node->next = *rpool_pptr;
    *rpool_pptr = node;
}

Rectangle *alloc_node(Rectangle **rpool_pptr)
{
    Rectangle *node_ptr;
    
    node_ptr = *rpool_pptr;
    
    *rpool_pptr = node_ptr->next;
    node_ptr->next = NULL; 
    //add_node_inuse(node_ptr); 
    
    return node_ptr;
}

void display(Rectangle *npointer)
{
    int count=0;
    Rectangle *node_ptr;
    for(node_ptr = npointer; node_ptr != NULL; node_ptr = node_ptr->next)
    {
        count++;
    }
    printf("Number of nodes in the node pool: %d\n",count);
}


void clear(Rectangle *ptr)
{
    ptr->id = 0;
    ptr->next = NULL;
    for(int i = 0; i <= VTX_CNT; i++)
    {
        ptr->v[i].x = 0;
        ptr->v[i].y = 0;
    }
}

void init_pool()
{
    int i;
    
    for(i = 0; i < (MAX_POOL_SIZE-1); i++)
    {
        rpool_nodes[i].next = &rpool_nodes[i+1];
        rpool_nodes[i].pool_index = i;
    }
    
    rpool_nodes[i].next = NULL;
    
    rpool = &rpool_nodes[0];
}

int main()
{
    Rectangle *use_node;
    Rectangle *nodes_in_use[10];
    
    init_pool();
    display(rpool_nodes);
    use_node = alloc_node(&rpool);
    /*use_node2 = alloc_node(&rpool);
    use_node3 = alloc_node(&rpool);
    use_node4 = alloc_node(&rpool);*/
    //display(use_node);
    free_node(&rpool,use_node);
    //free_node(&rpool,use_node);
    display(rpool);
    
    /*for(int i=0;i<10;i++)
    {
        nodes_in_use[i] = alloc_node(&rpool);
        
        printf("Node allocated %x - %x\n",nodes_in_use[i],&rpool_nodes[nodes_in_use[i]->pool_index]);
        if(nodes_in_use[i] != &rpool_nodes[nodes_in_use[i]->pool_index])
        {
            printf("Adress mismatch found at %d:\n",i);
        }
    }*/
    
    /*for(int i = 0; i < 5;i++)
    {
        nodes_in_use[i] = alloc_node(&rpool);
    }
    
    for(int i = 0;i < 9; i++)
    {
        free_node(&rpool,nodes_in_use[i]);
    }
    display(rpool);*/
    
    return 0;
}
