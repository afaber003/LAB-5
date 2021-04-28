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
    if (arr[child]->getPriority() > arr[parent]->getPriority()){
        PrintJob* temp = arr[parent];
        arr[parent] = arr[child];
        arr[child] = temp;
        return true;
    } else return false;
}

void Heap::enqueue(PrintJob* newone){
    arr[numItems] = newone;
    int currIndex = numItems;
    while (swap(currIndex, getParentIndex(currIndex))){
        currIndex = getParentIndex(currIndex);
        if (currIndex == 0){break;}
    }
    numItems++;
}

void Heap::dequeue ( )
{
  trickleDown(0);
}

void Heap::trickleDown(int currIndex)
{
  int childIndex = 2 * currIndex + 1;
  int currPriority = arr[currIndex]->getPriority();

  while (childIndex < numItems)
  {
    int maxPriority = currPriority;
    int maxIndex = -1;
    for (int i = 0; i < 2 && i + childIndex < numItems; i++) {
      if (arr[i + childIndex]->getPriority() > maxPriority)
      {
        maxPriority = arr[i + childIndex]->getPriority();
        maxIndex = i + childIndex;

      }
    }

    if (maxPriority == currPriority)
    {
      return;
    }
    else
    {
      swap(maxIndex, currIndex);
      currIndex = maxIndex;
      childIndex = 2 * currIndex + 1;
    }
  }
}

PrintJob* Heap::highest ( )
{
  return arr[0];
}

void Heap::print ( )
{
  cout << "Priority: " << highest()->getPriority() << ", ";
  cout << "Job Number: " << highest()->getJobNumber() << ", ";
  cout << "Number of Pages: " << highest()->getPages() << ", ";
  cout << endl;
}