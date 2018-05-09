#include <iostream>

#include "FileStructure.h"
#include "Key.h"

Key* SortedMerge(Key* a, Key* b)
{
  if (a == NULL)
  {
    return b;
  }
  else if (b == NULL)
  {
    return a;
  }

  Key* result = NULL;

  //vergelijken
  if (a->getText() <= b->getText())
  {
    result = a;
    result->setPrev(SortedMerge(a->getPrev(), b));
  }
  else
  {
    result = b;
    result->setPrev(SortedMerge(a, b->getPrev()));
  }

  return result;
}

void Split(Key* source, Key** frontRef, Key** backRef)
{
  if (source == NULL || source->getPrev() == NULL)
  {
    *frontRef = source;
    *backRef = NULL;
    return;
  }

  Key* slow = source;
  Key* fast = source->getPrev();

  while (fast != NULL)
  {
    fast = fast->getPrev();
    if (fast != NULL)
    {
      slow = slow->getPrev();
      fast = fast->getPrev();
    }
  }

  *frontRef = source;
  *backRef = slow->getPrev();
  slow->setPrev(NULL);
}

void MergeSort(Key* headRef)
{
  if (headRef == NULL || (headRef)->getPrev() == NULL)
  {
    return;
  }

  Key *a, *b;

  Split(headRef, &a, &b);

  MergeSort(a);
  MergeSort(b);

  headRef = SortedMerge(a, b);

}


int main()
{
  FileStructure f;
  Key head;
  //f.loadFile("data/gibberish.bin", head);

  Key k;

k.addValue("GG");
k.addValue("CC");
k.addValue("AA");
k.addValue("EE");
k.addValue("BB");
k.addValue("HH");
k.addValue("DD");
k.addValue("FF");
k.addValue("CC");




  // next line is only to show what kind of data we're working with
  // remove this line to increase performance!
  //head.print();
  //k.print();
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
