// GettingBackIntoCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Vector.h"
#include <iostream>

using namespace std;

void testVector();

int main()
{
   testVector();
   
}

void testVector()
{
   Vector<int> v(2);
   cout << "V has a size of " << v.size() << " and capacity of " << v.capacity() << endl;

   size_t i = 0, j = 0;
   size_t curLim = 1;
   while (i++ < 7)
   {
      curLim *= 2;
      for (; j < curLim; j++)
         v.appendToEnd(j);
      for (size_t k = 0; k < v.size(); k++)
         cout << v[k] << ' ';
      cout << endl << "V has a size of " << v.size() << " and capacity of " << v.capacity() << endl;
   }

   v[54] = 10000;
   cout << v[54] << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
