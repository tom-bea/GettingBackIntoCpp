// GettingBackIntoCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Collection.h"
#include "Vector.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

void testVector();
void testIterator();
void testLinkedList();

template <class Type>
void printCollection(Collection<Type>&, const char delim = ' ', const char start = '[', const char end = ']');

int main()
{
   testVector();
   testIterator();
   testLinkedList();
}

void testVector()
{
   cout << "TESTING THE VECTOR CLASS" << endl << endl;

   Vector<int> v(2);
   cout << "V has a size of " << v.size() << " and capacity of " << v.capacity() << endl;

   size_t i = 0, j = 0;
   size_t curLim = 1;
   while (i++ < 7)
   {
      curLim *= 2;
      for (; j < curLim; j++)
         v.appendToEnd(j);
      printCollection(v);
      cout << endl << "V has a size of " << v.size() << " and capacity of " << v.capacity() << endl;
   }

   v[54] = 10000;
   cout << v[54] << endl;

   v.insert(50);
   v.insert(-5, 0);
   v.insert(-50, 10);
   v.insert(-500, 10000);
   printCollection(v);
   cout << v[10] << endl;

   cout << v[10] << endl;
   v.remove(10);
   cout << v[10] << endl;
   printCollection(v);

   for (size_t i = 0; i < 100; i++)
      v.remove(10);
   printCollection(v);
   cout << "V has a size of " << v.size() << " and capacity of " << v.capacity() << endl;

   v.clear();
   printCollection(v);
   cout << "V has a size of " << v.size() << " and capacity of " << v.capacity() << endl;

   cout << "DONE TESTING THE VECTOR CLASS" << endl << endl;
}

void testIterator()
{
   cout << "TESTING THE ITERATOR CLASS" << endl << endl;

   size_t size = 30;
   Vector<int> v(size);
   for (size_t i = 0; i < size; i++)
      v.appendToEnd(i);

   for (size_t i = 0; i < size; i++)
      cout << i << " ";
   cout << endl;

   for (auto x : v)
      cout << x << " ";
   cout << endl;

   cout << "DONE TESTING THE ITERATOR CLASS" << endl << endl;
}

void testLinkedList()
{
   cout << "TESTING THE ITERATOR CLASS" << endl << endl;

   LinkedList<int> l;

   l.insert(5);
   cout << l[0] << endl;

   cout << "DONE TESTING THE ITERATOR CLASS" << endl << endl;
}

template <class Type>
void printCollection(Collection<Type>& c, const char delim, const char start, const char end)
{
   cout << start;
   for (auto x : c)
      cout << x << delim;
   cout << end << endl;
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
