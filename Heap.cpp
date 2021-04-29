#include "Heap.h"


using namespace std;

bool Heap::isEmpty(){
  if (numItems == 0){
    return true;
  }
  return false;
}

int Heap::getParentIndex(int childIndex){
  return ((childIndex - 1) / 2);
}

bool Heap::swap(int child, int parent){
  if (child > numItems || parent > numItems || parent < 0) return false;
  if (arr[child]->getPriority() > arr[parent]->getPriority()){
    PrintJob* temp = arr[parent];
    arr[parent] = arr[child];
    arr[child] = temp;
    return true;
  } else return false;
}

void Heap::enqueue(PrintJob* newone){
  if (numItems == MAX_HEAP_SIZE){return;}
  arr[numItems] = newone;
  int currIndex = numItems;
  while (currIndex != 0 and swap(currIndex, getParentIndex(currIndex))){
    currIndex = getParentIndex(currIndex);
  }
  numItems++;
}

void Heap::dequeue ( )
{
  if (isEmpty()){return;}
  PrintJob* temp = arr[0];
  arr[0] = arr[numItems - 1];
  arr[numItems - 1] = temp;
  numItems--;

  trickleDown(0);
  
}

void Heap::trickleDown(int parentIndex)
{
  int childIndex = getGreatestChildIndex(parentIndex);
  if(childIndex == -1){
    return;
  }

 
 while (childIndex < numItems && arr[parentIndex]->getPriority() < arr[childIndex]->getPriority())
  {
    swap(childIndex, parentIndex);
    parentIndex = childIndex;
    childIndex = getGreatestChildIndex(parentIndex);
    if(childIndex == -1){
      return;
    }

  }

}

PrintJob* Heap::highest ( )
{
  if(numItems > 0){
    return arr[0];
  }
  else{
    return nullptr;
  }
}

void Heap::print ()
{
  if (isEmpty())
  {
    return;
  }
  cout << "Priority: " << highest()->getPriority() << ", ";
  cout << "Job Number: " << highest()->getJobNumber() << ", ";
  cout << "Number of Pages: " << highest()->getPages();
  cout << endl;
}

int Heap::getRightChildIndex(int parentIndex)
{
  return (2 * parentIndex) + 2;
}

int Heap::getLeftChildIndex(int parentIndex)
{
  return (2 * parentIndex) + 1;
}

int Heap::getGreatestChildIndex(int parentIndex)
{
    int childIndex;
    
    int rightChild = getRightChildIndex(parentIndex);
    int leftChild = getLeftChildIndex(parentIndex);
    //if both are out of range, at a leaf node
    if (rightChild > numItems && leftChild > numItems){
      return -1;
    }
    else if(leftChild < numItems && rightChild < numItems){
      if(arr[rightChild]->getPriority() > arr[leftChild]->getPriority())
      {
        childIndex = rightChild;
      }
      else
      {
        childIndex = leftChild;
      }
    }
    //if just the left child is higher
    else if (arr[leftChild]->getPriority() > arr[parentIndex]->getPriority()){
      childIndex = leftChild;
    }
    //if just the right child is higher
    else if (arr[rightChild]->getPriority() > arr[parentIndex]->getPriority()){
      childIndex = rightChild;
    }
    //only has left child
    else if(leftChild < numItems){
      childIndex = leftChild;
    }
    //only has right child
    else if (rightChild < numItems){
      childIndex = rightChild;
    }
    return childIndex;
}