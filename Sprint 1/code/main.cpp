#include <iostream>

#include "FileStructure.h"
#include "Key.h"

template<typename T>
T* Merge(T* firstNode, T* secondNode)
{
  if (firstNode == NULL)
  {
    return secondNode;
  }
  else if (secondNode == NULL)
  {
    return firstNode;
  }

  else if (firstNode->getText() >= secondNode->getText()) //if I reverse the sign to >=, the behavior reverses
  {
    firstNode->setPrev(Merge(firstNode->getPrev(), secondNode));
    return firstNode;
  }
  else
  {
    secondNode->setPrev(Merge(firstNode, secondNode->getPrev()));
    return secondNode;
  }
}

template<typename T>
T* Split(T* my_node)
{
  T* secondNode;

  if (my_node == NULL)
  {
    return NULL;
  }
  else if (my_node->getPrev() == NULL)
  {
    return NULL;
  }
  secondNode = my_node->getPrev();
  my_node->setPrev(secondNode->getPrev());
  secondNode->setPrev(Split(secondNode->getPrev()));
  return secondNode;
}

template<typename T>
T* MergeSort(T* my_node)
{
  T* secondNode;

  if (my_node == NULL)
  {
    return NULL;
  }
  else if (my_node->getPrev() == NULL)
  {
    return my_node;
  }
  secondNode = Split(my_node);
  return Merge(MergeSort(my_node), MergeSort(secondNode));
}




int main()
{
  FileStructure f;
  Key head;
  f.loadFile("data/gibberish.bin", head);



  Key* newHead = MergeSort(&head);
  Key* tempHead = newHead;
  while (tempHead != NULL)
  {
    Value* value = MergeSort(tempHead->getValuePtr());
    tempHead->setValuePtr(value);
    tempHead = tempHead->getPrev();
  }
  // save sorted data into a new file called sorted.bin
  f.saveFile(*newHead, "sorted.bin");


  return 0;
}
