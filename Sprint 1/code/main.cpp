#include <iostream>

#include "FileStructure.h"
#include "Key.h"


int Compare(const std::string a, const std::string b) //Van groot naar klein.
{
  if (a < b)
  {
    return 1;
  }
  else if (a > b)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

void Swap(Value* current, Value* temp)
{
  temp = current->getPrev();
  current->setPrev(current->getPrev()->getPrev());
  temp->setPrev(current);
}

void Sort_Values(Value* head) //bubblesort
{
  int count = 0;
  int i;
  Value *start = head;
  Value *curr = NULL;
  Value *trail = NULL;
  Value *temp = NULL;


  while (start->getPrev() != NULL)
  { //grab count
    count++;
    start = start->getPrev();
  }

  for (i = 0; i < count; ++i)
  { //for every element in the list

    curr = start;
    trail = start; //set curr and trail at the start node
   // std::cout << curr->getText(); //TESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSST
    while (curr= NULL)
    { //for the rest of the elements in the list
      std::cout << "hua";
      if (Compare(curr->getText(), curr->getPrev()->getText()) == 1)
      { //compare curr and curr->next
        std::cout << "hoi";
        Swap(curr, temp);

        //now we need to setup pointers for trail and possibly head
        if (curr == head)
        {
          std::cout << "doei";
          head = temp;
          trail = temp;
        } //this is the case of the first element swapping to preserve the head pointer

        else //setup trail correctly
          trail->setPrev(temp);
        curr = temp; //update curr to be temp since the positions changed
      }
      //advance pointers
      trail = curr;
      curr = curr->getPrev();
    }
  }
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
  k.addValue("taxibaan");
  k.addValue("tafel");
  k.addValue("calculator");

  // next line is only to show what kind of data we're working with
  // remove this line to increase performance!
  //head.print();
  k.print();

  // sort all data
  // todo: call your sort method(s) here!
  Sort_Values(k.getValuePtr());
  k.print();

  // save sorted data into a new file called sorted.bin
  f.saveFile(head, "sorted.bin");

  return 0;
}
