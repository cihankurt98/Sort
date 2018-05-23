#include "FileStructure.h"
#include "Value.h"

template<typename T>
T* Merge(T* firstNode, T* secondNode)
{
  if (!firstNode) return secondNode;
  else if (!secondNode) return firstNode;

  else if (firstNode->getText() >= secondNode->getText())
  {
    firstNode->setPrev(Merge(firstNode->getPrev(), secondNode));
    return firstNode;
  }
  secondNode->setPrev(Merge(firstNode, secondNode->getPrev()));
  return secondNode;
}

template<typename T>
T* Split(T* my_node)
{
  if (!my_node || !my_node->getPrev()) return NULL;
  T* secondNode = my_node->getPrev();
  my_node->setPrev(secondNode->getPrev());
  secondNode->setPrev(Split(secondNode->getPrev()));
  return secondNode;
}

template<typename T>
T* MergeSort(T* my_node)
{
  if (!my_node) return NULL;
  else if (!my_node->getPrev()) return my_node;
  return Merge(MergeSort(my_node), MergeSort(Split(my_node)));
}


int main(void)
{
  FileStructure f;
  Key* head = new Key();
  f.loadFile("data/gibberish.bin", *head);

  head = MergeSort(head);
  Key* tempHead = head; //values

  while (tempHead)
  {
    tempHead->setValuePtr(MergeSort(tempHead->getValuePtr()));
    tempHead = tempHead->getPrev();
  }

  // save sorted data into a new file called sorted.bin
  f.saveFile(*head, "sorted.bin");

  delete head;
  //newHead = NULL;

  return 0;
}
