#include "FileStructure.h"
#include "Value.h"
#include "Key.h"

template<typename T>
T* Merge(T* firstNode, T* secondNode)
{
  if (firstNode == NULL) return secondNode;
  else if (secondNode == NULL) return firstNode;

  else if (firstNode->getText() >= secondNode->getText())
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
  if (my_node == NULL)return NULL;
  else if (my_node->getPrev() == NULL)return NULL;
  T* secondNode = my_node->getPrev();
  my_node->setPrev(secondNode->getPrev());
  secondNode->setPrev(Split(secondNode->getPrev()));
  return secondNode;
}

template<typename T>
T* MergeSort(T* my_node)
{
  if (my_node == NULL) return NULL;
  else if (my_node->getPrev() == NULL) return my_node;
  return Merge(MergeSort(my_node), MergeSort(Split(my_node)));
}


int main()
{
  FileStructure f;
  Key* head = new Key();
  f.loadFile("data/gibberish.bin", *head);

  Key* newHead = MergeSort(head);
  Key* tempHead = newHead;

  while (tempHead != NULL)
  {
    Value* value = MergeSort(tempHead->getValuePtr());
    tempHead->setValuePtr(value);
    tempHead = tempHead->getPrev();
  }
  // save sorted data into a new file called sorted.bin
  f.saveFile(*newHead, "sorted.bin");

  delete newHead;
  newHead = NULL;

  return 0;
}
