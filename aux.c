 #include "assignment3.h"
#include <stdio.h>
#include <stdlib.h>



void generateRandomIntArray(int N, int *A, int NMAX)
{
	int i;

	for (i = 0; i < N; i++)
	{
		/* use modulos to keep the NMAX -1 as maximum number */
		A[i] = (rand() % NMAX);
	}

}

void printArray(int n, int *A)
{

	int i;
	for(i = 0; i < n; i++)
	{

		printf("%d ",A[i]);
	}


}


void printBSTinorder(TreeNodePtr root)
{
  if (root != NULL)
 
  {

  	/*this will print the left side while going through recursion*/
     printBSTinorder(root->left) ;
     
     /*this will print the selected root*/
     printf("%d ", (root->key)) ;  
     /*this will print the right side while going through recursion*/

     printBSTinorder(root->right) ;  
  
  }

}



void printList(ListNodePtr head)
{
	ListNodePtr temp = head;

	while (temp->next != NULL)
	{
		printf("%d ", temp->key);
		temp = temp->next;
	}

	printf("%d ", temp->key);


}



