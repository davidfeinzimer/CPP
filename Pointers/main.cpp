//
//  main.cpp
//  Pointers
//
//  Created by David Feinzimer on 2/20/20.
//  Copyright © 2020 Fein. All rights reserved.
//

#include <iostream>
using namespace std;

int g_int1 = 10;
int g_int2 = 20;

void printOut(int *iPtr) {
    cout << "g_int1\t\t" << g_int1 << endl;
    cout << "&g_int1\t\t" << &g_int1 << endl;
    cout << "g_int2\t\t" << g_int2 << endl;
    cout << "&g_int2\t\t" << &g_int2 << endl;
    cout << "iPtr\t\t" << iPtr << endl;
    cout << "*iPtr\t\t" << *iPtr << endl;
    cout << "&iPtr\t\t" << &iPtr << endl;
    cout << endl;
}

void foo1(int *iPtr) {
    *iPtr = 11;
    iPtr = &g_int2;
}

void foo2(int **iPtr) {
    **iPtr = 22;
    *iPtr = &g_int2;
}

int main(int argc, const char * argv[]) {
    int *iPtr = &g_int1;
    foo1(iPtr);
    foo2(&iPtr);
    return 0;
}
