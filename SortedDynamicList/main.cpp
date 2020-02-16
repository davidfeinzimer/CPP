#include <iostream>
#include "SortedDynamicList.h"
using namespace std;

int main() 
{
  SortedDynamicList sdl(5);
  int choice;
  while(choice != -1)
  {
    cout << "Enter a number: ";
    cin >> choice;
    sdl.addItem(choice);
    cout << sdl;
  }
  return 0;
}
