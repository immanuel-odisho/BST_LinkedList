#include "assignment3.h"
#include <stdio.h>
#include <stdlib.h>


TreeNodePtr createBSTnode(int key)
{
	TreeNodePtr new_bts;

  /* declares a TreeNodePtr */

	new_bts = malloc(sizeof(struct TreeNode));
	
  /*sets the size */

	if (new_bts == NULL){
		
    return NULL;
	}

  /* checks if null and returns null */

  /* sets the key of the node */
	new_bts->key = key;

	new_bts->left = NULL;

/* makes the right and left equal to null */
	new_bts->right = NULL;
/*returns*/


	return new_bts;
}
  

TreeNodePtr insertNodeIntoBST(TreeNodePtr root, const TreeNodePtr z)
{

  TreeNodePtr temp = root;											

  for (; ; )				/* for loop to go until breaks */			
  {
    if (z->key < temp->key)				
    {
      /* checks if key is smaller than key and goes to left */
      if (temp->left == NULL)				
      
      {
        /* if condiiton met it will insert into the left of the node */
        temp->left = z;					
        
        /* break to exit out of for loop */
        break;               }


      temp = temp->left;		  }

 else							
    {
      if (temp->right == NULL)				
      
      {
        /* sets thr right to equal pointer given */
        
        temp->right = z;
        

        break;					
        					
      }
      /* sets the temp to equal the right node */
      temp = temp->right;				
    
    }
  
  }



    return root;  
}


TreeNodePtr insertArrayIntoBST(int n, int *A)
{
  TreeNodePtr root = createBSTnode(A[0]);
  
  int j;
  
  /* creates a for loop and int is declared outside for C89 */
  
  for (j = 1; j < n; j++)
  {

    /* goes through recurrsion and sets the node to next array element */
    TreeNodePtr node = createBSTnode(A[j]);
    
    /*inserts the node into the root and keeps track of the root */
    
    root = insertNodeIntoBST(root, node);
  
  }
  
  return root;
}


void deallocateBST(TreeNodePtr root)
{
  if (root != NULL)
  {
  
  deallocateBST(root->left);
  /* recursion and goes through the left most side and deallocates */

  /* recursion and goes through the right most side and deallocates */
  deallocateBST(root->right);
  
  /* frees the root and sets to Null to avoid errors */
  free(root);
  

  root = NULL;
  }
}



ListNodePtr convertBSTtoLinkedList(TreeNodePtr root)
{
    ListNodePtr list,top;

    list = malloc(sizeof(struct ListNode));
    /* decalare the structure of the listnode in order to return*/
    list->key = root->key;

    if (root->right != NULL)

    {
        /* recursion to go through the right side and make it next of root*/

        list->next = convertBSTtoLinkedList(root->right);

    }
    else

    {
        /* will make next null in order to free memory and remove errors*/
      list->next = NULL;

    }

    /* checks if root left exists */

    if (root->left != NULL)  

    {

    /* creates a listnode pointers */

    ListNodePtr past;
    /* recursion will keep track of the top of the list*/
    top = convertBSTtoLinkedList(root->left);

    past = top;

    while (past->next != NULL) {
      /* continually checks and makes the top of the head in track */
        past = past->next;

    }
    /*makes the top of the list next point to the root */
    past->next = list;

    return top;

    }

    return list;
}