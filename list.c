#include "assignment3.h"
#include <stdlib.h>
#include <stdlib.h>



ListNodePtr reverseList(ListNodePtr head)
{
  ListNodePtr next = NULL;
  /*declares the two pointers */
  ListNodePtr past = NULL;
  
  while (head->next != NULL)
  {
   
    next = head->next;
    /* sets the value of next to the next of had */
    head->next = past;
   /*makes the next of head past */
    past = head;
   /*past now is head and head is next */
    head = next;
  }
   
   /*head next becomes past and head is returned */
    head->next = past;
   
    return head;
}

void deallocateList(ListNodePtr head)
{
	if (head->next != NULL)
		/*goes into recursion and checks if next is null otherwirse frees the parameter */
    deallocateList(head->next);
		/* frees head  and sets to null */
    free(head);
		head = NULL;
	
}

