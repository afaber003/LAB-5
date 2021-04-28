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

void Heap::swap(int child, int parent){
    if (arr[child]->getPriority() > arr[parent]->getPriority()){
        PrintJob* temp = arr[parent];
        arr[parent] = arr[child];
        arr[child] = temp;
    } else return;
}

void Heap::enqueue(PrintJob* newone){
    arr[numItems] = newone;
    if (isEmpty() || getParentIndex(numItems) == 0){
        return;
    }
    int currIndex = numItems;
    while (arr[currIndex]->getPriority() > arr[getParentIndex(currIndex)]->getPriority()){
        swap(currIndex, getParentIndex(currIndex));
        currIndex = getParentIndex(currIndex);
        if (currIndex == 0){break;}
    }
}