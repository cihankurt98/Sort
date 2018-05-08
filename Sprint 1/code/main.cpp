#include <iostream>

#include "FileStructure.h"
#include "Key.h"

int getLength(Key* head)
{
  int count = 0;
  Key* temp = head;
  while (temp != NULL)
  {
    count++;
    temp = temp->getPrev();
  }
  return count;
}

Key* MergeList(Key* a, Key* b) {
    Key* result = NULL;
    if (a == NULL)
    {
      return b;
    }
    if (b == NULL)
    {
      return a;
    }
    
    if (a->getText() > b->getText()) 
    {
      result = b;
      result->setPrev(MergeList(a, b->getPrev()));
    } 
    else 
    {
      result = a;
      result->setPrev( MergeList(a->getPrev(), b));
    }
    return result;
}

Key* MergeSort(Key* head)
{
    Key* oldHead = head;
    // find the length of the linkedlist
    int mid = getLength(head) / 2;
    if (head->getPrev() == NULL)
    {
      return head;
    }
    // set one pointer to the beginning of the list and another at the next
    // element after mid
    while (mid - 1 > 0)
    {
      oldHead = oldHead->getPrev();
      mid--;
    }

    Key* newHead = oldHead->getPrev();// make newHead points to the beginning of
                  // the second half of the list
    oldHead->setPrev(NULL);// break the list
    oldHead = head;// make one pointer points at the beginning of the first
          // half of the list
    Key* t1 = MergeSort(oldHead);//make recursive calls 
    Key* t2 = MergeSort(newHead);
return MergeList(t1, t2); // merge the sorted lists

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
  MergeSort(&k);
  k.print();

  // save sorted data into a new file called sorted.bin
  f.saveFile(head, "sorted.bin");

  return 0;
}
