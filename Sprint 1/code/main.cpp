#include <iostream>

#include "FileStructure.h"
#include "Key.h"

void quickSort(Key* head)
{
  if  (head == NULL || head->getPrev() == NULL)
  {
    return;
  }

  Key *lhs = NULL;
  Key  **pplhs = &lhs;
  Key *rhs = NULL;
  Key **pprhs = &rhs;
  Key *pvt = head;
  head = head->getPrev();
  std::cout << head->getText() << std::endl;
  pvt->setPrev(NULL);

  while (head != NULL)
  {
    std::cout << head->getText() << pvt->getText() << std::endl;
    if (head->getText() < pvt->getText())
    {
      *pplhs = head->getPrev(); // tack on lhs list end
    }
    else
    {
      *pprhs = head->getPrev(); // tack on rhs list end
      std::cout << pprhs->getText() << std::endl;
    }
    head = head->getPrev();
  }

  // terminate both list. note that the pivot is still
  //  unlinked, and will remain so until we merge
  *pplhs = NULL;
  *pprhs = NULL;

  // invoke on sublists.
  quickSort(lhs);
  quickSort(rhs);

  // find end of lhs list, slip the pivot into  position, then
  //  tack on the rhs list.
  while (*pplhs != NULL)
  {
    *pplhs = (*pplhs)->getPrev();
    *pplhs = pvt;
    pvt->setPrev(rhs);
  }

  // set final output
  head = lhs;
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
  quickSort(&k);
  k.print();

  // save sorted data into a new file called sorted.bin
  f.saveFile(head, "sorted.bin");

  return 0;
}
