#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  if(head==NULL)
  {
    smaller= NULL;
    larger= NULL;
  }
  if(head==NULL)
  return;
  if(head->val<=pivot)
  {
    smaller = head;
    llpivot(head->next, smaller->next,larger, pivot);
  }
  else
  {
    larger = head;
    llpivot(head->next, smaller,larger->next, pivot);
  }
}

