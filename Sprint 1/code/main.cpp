#include <iostream>

#include "FileStructure.h"
#include "Key.h"


Key* mergeLists(Key* a, Key* b)
{
  Key* mergedList = NULL;

  if (a == NULL)
   {
    return b;
  }
  else if (b == NULL)
  {
    return a;
  }
  std::cout << a->getText() << b->getText() << std::endl;
if (a->getText() <= b->getText())
{
  mergedList = a;
  mergedList->setPrev(mergeLists(a->getPrev(), b));
}
else
{
  mergedList = b;
  mergedList->setPrev(mergeLists(a, b->getPrev()));
}
return mergedList;

}

Key* findMiddle(Key* head)
{
  if (head == NULL)
  {
    return NULL;
  }
  Key* slow = head;
  Key* fast = head;

  while (fast != NULL && fast->getPrev() != NULL)
  {
    fast = fast->getPrev()->getPrev();
    slow = slow->getPrev();
  }
  return slow;
}
//Finding the middle element of the list for splitting
void split(Key* head, Key* first, Key* second)
{
  if (head == NULL || head->getPrev() == NULL)
  {
    first = head;
    second = NULL;
  }

  Key* middle = findMiddle(head);

  if (middle == NULL)
  {
    middle = second;
  }
  if (first == NULL)
  {
    std::cout<< "error prevention" << std::endl;
  }
  first = head;
  std::cout << first->getText() << std::endl;
  second = middle->getPrev();
  middle->setPrev(NULL);
    first->print();
    second->print();
}

void mergeSort(Key* head)
{
  Key* tempHead = head;
  Key* a = NULL;
  Key* b = NULL;

  if (tempHead == NULL || tempHead->getPrev() == NULL)
  {
    return;
  }

  split(tempHead, a, b);
  mergeSort(a);
  mergeSort(b);
  head = mergeLists(a, b);

}



int main()
{
  FileStructure f;
  Key head;
  // f.loadFile("data/gibberish.bin", head);

  Key k;
  k.addValue("calculator");
  k.addValue("eik");
  k.addValue("einsteinium");
  k.addValue("eik");
  k.addValue("ei");
  k.addValue("eieren");
  k.addValue("eigendom");
  k.addValue("taxibaan");
  k.addValue("tafel");
 

  // next line is only to show what kind of data we're working with
  // remove this line to increase performance!
  //head.print();
  k.print();
  std::cout << std::endl;

  // sort all data
  // todo: call your sort method(s) here!
  //std::cout << k.getValuePtr()->getPrev()->getPrev()->getPrev()->getText();
  mergeSort(&k);


  // save sorted data into a new file called sorted.bin
  f.saveFile(head, "sorted.bin");

  return 0;
}
