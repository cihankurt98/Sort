#include <iostream>

#include "FileStructure.h"
#include "Key.h"

void partition(Key* head, Key * *front, Key * *back)
 {
  Key* fast;
  Key* slow;

  if (head == NULL || head->getPrev() == NULL)
  {
    *front = head; // &a
    *back = NULL; // &b

  }
  else
  {
    slow = head;
    fast = head->getPrev();

    while (fast != NULL)
    {
      fast = fast->getPrev();

      if (fast != NULL)
      {
        slow = slow->getPrev();
        fast = fast->getPrev();
      }
    }

    *front = head; // a
    *back = slow->getPrev(); // b
    slow->setPrev(NULL);
  }

}

Key* mergeLists(Key* a, Key* b) {

  Key* mergedList = NULL;

  if (a == NULL)
  {
    return b;
  }
  else if (b == NULL)
  {
    return a;
  }

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

void mergeSort(Key* source)
{
  Key* head = source;
  Key* a = NULL;
  Key* b = NULL;

  if (head == NULL || head->getPrev() == NULL)
  {
    return;
  }

  partition(head, &a, &b);

  mergeSort(a);
  mergeSort(b);

  source = mergeLists(a, b);

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
  mergeSort(&k);
  k.print();

  // save sorted data into a new file called sorted.bin
  f.saveFile(head, "sorted.bin");

  return 0;
}
