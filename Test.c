#include <stdio.h>
// Create a node for LL 

struct Node { 
    int data; 
    struct Node* next; // Pointer to next node in DLL 
    struct Node* prev; // Pointer to previous node in DLL 
};

// Create a node in LL 
//

typedef struct struct_name *name

name* CreateNode()
{
  name temp;
  temp=(name)malloc (sizeof (struct struct_name));
  temp -> next=NULL;
  return temp;
}

// Add node in LL Question 3
// This will add node at the end 
name* addNode (name *pHead, unsigned int data_val)
{
  /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    struct Node* last = *head_ref; /* To be used in Step 5 */
  
    /* 2. put in the data  */
    new_node->data = new_data; 
  
    /* 3. This new node is going to be the last node, so 
          make next of it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new 
          node as head */
    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
  
    /* 6. Change the next of last node */
    last->next = new_node; 
  
    /* 7. Make last node as previous of new node */
    new_node->prev = last; 
  
    return; 
} 

// Delete a node in LL 

// Insert a node after a given position

void insertnodeAfter(struct Node* pHead, int new_data) 
{ 
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) 
    { 
      printf("the given previous node cannot be NULL"); 
      return; 
    } 
  
    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 
  
    /* 3. put in the data  */
    new_node->data  = new_data; 
  
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next; 
  
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node; 
} 
