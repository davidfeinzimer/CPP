#include "SortedDynamicList.h"
using namespace std;
#include <iostream>

SortedDynamicList::SortedDynamicList(const int _maxSize) 
{
  maxSize = _maxSize;
  currentSize = 0;
  items = new int [maxSize];
}

int SortedDynamicList::getMaxSize()
{
  return maxSize;
}

int SortedDynamicList::getCurrentSize()
{
  return currentSize;
}

void SortedDynamicList::growByOne()
{
  cout << "Max size achieved, growing" << endl;
  maxSize*=2;
  int *temp;
  temp = new int [maxSize];
  for(int i = 0; i < maxSize; i++)
  {
    temp[i] = items[i];
  }
  delete [] items;
  items = temp;
}

SortedDynamicList::~SortedDynamicList()
{
  cout << "Freeing memory" << endl;
  delete [] items;
}

void SortedDynamicList::addItem(const int newItem)
{
  if (currentSize == maxSize)
  {
    growByOne();
  }
  int position = 0;
  for(int i = 0; i < currentSize; i++)
  {
    if (newItem == items[i])
    {
      position = i;
      moveRight(i);
      break;
    }
    else if (currentSize == 0)
    {
      break;
    }
    else if (currentSize > 0 && newItem < items[0])
    {
      position = 0;
      moveRight(0);
      break;
    }
    else if (i == currentSize - 1)
    {
      position = currentSize;
      break;
    }
    else if (newItem > items[i] && newItem < items[i+1])
    {
      moveRight(i+1);
      position = i+1;
      break;
    }
  }
  items[position] = newItem;
  currentSize++;
}

void SortedDynamicList::moveRight(int index)
{
  for(int i=currentSize; i > index; i--)
  {
    items[i] = items[i-1];
  }
}

ostream& operator<<(ostream& os, const SortedDynamicList& sl)
{
  for(int i = 0; i < sl.currentSize; i++)
  {
    os << sl.items[i] << " ";
  }
  cout << endl;
  return os;
}
