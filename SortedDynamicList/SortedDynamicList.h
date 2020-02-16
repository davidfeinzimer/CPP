#ifndef SORTEDDYNAMICLIST_H
#define SORTEDDYNAMICLIST_H

#include <iostream>
using namespace std;

class SortedDynamicList
{
private:
  int currentSize;
  int maxSize;
  int *items;
  void growByOne();
  friend ostream& operator<<(ostream&, const SortedDynamicList&);

public:
  SortedDynamicList(const int);
  int getCurrentSize();
  int getMaxSize();
  void addItem(const int);
  void moveRight(int);
  ~SortedDynamicList();
};

#endif
