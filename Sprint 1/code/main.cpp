#include <iostream>

#include "FileStructure.h"
#include "Key.h"

//Finding the middle element of the list for splitting
Key* getMiddle(Key* head)
{
  if (head == NULL)
  {
    return head;
  }

  Key* fast = head;
  Key* slow = fast;

  while (fast->getPrev() != NULL && fast->getPrev()->getPrev() != NULL)
  {
    slow = slow->getPrev();
    fast = fast->getPrev()->getPrev();
  }
  return slow;
}

//Merge subroutine to merge two sorted lists
Key* merge(Key* a, Key* b)
{
  Key* dummyHead = NULL;
  Key* curr = dummyHead;
  while (a != NULL && b != NULL)
  {
    if (a->getText() <= b->getText())
    {
      curr->setPrev(a);
      a = a->getPrev();
    }
    else
    {
      curr->setPrev(b);
      b = b->getPrev();
    }
    curr = curr->getPrev();
  }
  curr->setPrev((a == NULL) ? b : a);
  return dummyHead->getPrev();
}

Key* merge_sort(Key* head)
{
  if (head == NULL || head->getPrev() == NULL)
  {
    return head;
  }
  Key* middle = getMiddle(head);      //get the middle of the list
  Key* sHalf = middle->getPrev();
  middle->setPrev(NULL);   //split the list into two halfs

  return merge(merge_sort(head), merge_sort(sHalf)); //recurse on that
}




int main()
{
  FileStructure f;
  Key head;
  // f.loadFile("data/gibberish.bin", head);

  Key k;
  k.addValue("eik");
  k.addValue("einsteinium");
  k.addValue("eik");
  k.addValue("ei");
  k.addValue("eieren");
  k.addValue("eigendom");
  k.addValue("taxibaan");
  k.addValue("tafel");
  k.addValue("calculator");

  // next line is only to show what kind of data we're working with
  // remove this line to increase performance!
  //head.print();
  k.print();
  std::cout << std::endl;

  // sort all data
  // todo: call your sort method(s) here!
  //std::cout << k.getValuePtr()->getPrev()->getPrev()->getPrev()->getText();
  merge_sort(&k);
  k.print();

  // save sorted data into a new file called sorted.bin
  f.saveFile(head, "sorted.bin");

  return 0;
}
