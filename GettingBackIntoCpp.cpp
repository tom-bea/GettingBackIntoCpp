// GettingBackIntoCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Collection.h"
#include "Vector.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

void testVector();
void testIterator();
void testLinkedList();

template <class Type>
void printCollection(Type&, const char delim = ' ', const char start = '[', const char end = ']');

int main()
{
   testVector();
   //testIterator();
   testLinkedList();
}

void testVector()
{
   cout << "TESTING THE VECTOR CLASS" << endl << endl;

   cout << "Creating an empty vector with capacity 2." << endl;
   Vector<int> v(2);
   cout << "V has a size of " << v.size() << " and capacity of " << v.capacity() << endl;

   cout << "Testing the appendToEnd method" << endl;
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

   cout << "Changing the 54th element (0 index) to 10000" << endl;
   v[54] = 10000;
   cout << v[54] << endl;

   cout << "Testing the insert method" << endl;
   v.insert(-5, 0);
   v.insert(-50, 10);
   v.insert(-500, 10000);
   printCollection(v);

   cout << "Testing the remove method" << endl;
   cout << v[10] << endl;
   v.remove(10);
   cout << v[10] << endl;
   printCollection(v);

   for (size_t i = 0; i < 100; i++)
      v.remove(10);
   printCollection(v);
   cout << "V has a size of " << v.size() << " and capacity of " << v.capacity() << endl;

   cout << "Testing the clear method" << endl;
   v.clear();
   printCollection(v);
   cout << "V has a size of " << v.size() << " and capacity of " << v.capacity() << endl;

   cout << "Creating a vector and then cloning it" << endl;
   Vector<char> vOrig;
   for (char c = 'a'; c <= 'z'; c++)
      vOrig.appendToEnd(c);
   Vector<char> vClone(vOrig);
   printCollection(vOrig);
   printCollection(vClone);

   cout << "Changing the clone" << endl;
   vClone[4] = 'E';
   vClone[9] = 'J';
   printCollection(vOrig);
   printCollection(vClone);

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
   cout << "TESTING THE LINKEDLIST CLASS" << endl << endl;

   cout << "Creating an empty LinkedList" << endl;
   LinkedList<char> l;
   printCollection(l);
   
   cout << "Testing the insertAtTail method" << endl;
   for (char c = 'a'; c <= 'z'; c++)
      l.insertAtTail(c);
   printCollection(l);

   cout << "Testing the remove method" << endl;
   l.remove(25);
   l.remove(24);
   l.remove(0);
   l.remove(1);
   l.remove(5);
   printCollection(l);

   cout << "Testing the insertAtHead method" << endl;
   l.insertAtHead('a');
   l.insertAtHead('a');
   printCollection(l);

   cout << "Testing the insert method" << endl;
   l.insert('c', 3);
   l.insert('h', 8);
   printCollection(l);

   cout << "Testing the [] method" << endl;
   l[0] = 'A';
   l[8] = 'H';
   l[3] = 'C';
   printCollection(l);

   cout << "Testing the clear method" << endl;
   l.clear();
   printCollection(l);

   cout << "Creating a LinkedList and then cloning it" << endl;
   LinkedList<string> lOrig;
   string str = "";
   for (char c = 'a'; c <= 'j'; c++)
   {
      str += c;
      lOrig.insertAtTail(str);
   }
   LinkedList<string> lClone(lOrig);
   printCollection(lOrig, ',');
   printCollection(lClone,  ',');

   cout << "Changing the clone" << endl;
   lClone[4] = "hello";
   lClone[9] = "world";
   printCollection(lOrig);
   printCollection(lClone);

   cout << "DONE TESTING THE LINKEDLIST CLASS" << endl << endl;
}

template <class Type>
void printCollection(Type& c, const char delim, const char start, const char end)
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
