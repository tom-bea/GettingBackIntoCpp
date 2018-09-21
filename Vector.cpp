#include "Vector.h"

#include <iostream>

using namespace std;

template <class T>
Vector<T>::Vector(const size_t capacity)
{
   m_arr = new T*[capacity];
   m_capacity = capacity;
   m_size = 0;
}

template <class T>
Vector<T>::~Vector()
{
   if (m_arr)
      delete[] m_arr;
}

template <class T>
void Vector<T>::resize(size_t capacity)
{
   int* tempArr = new int[capacity];
   size_t end = (capacity > m_size) ? m_size : capacity;
   m_capacity = capacity;

   for (size_t i = 0; i < end; i++)
      tempArr[i] = m_arr[i];

   delete[] m_arr;
   m_arr = tempArr;
}

template <class T>
void Vector<T>::appendToEnd(const T el)
{
   if (m_size == m_capacity)
      resize(m_capacity * 2);
   m_arr[m_size++] = el;
}

template <class T>
T & Vector<T>::operator[](const size_t i)
{
   if (i > m_size)
   {
      cout << "i must be LESS than " << m_size << endl;
      return m_arr[0];
   }
   return m_arr[i];
}

template <class T>
string Vector<T>::to_string() const
{
   string str = "[";
   /*for (size_t i = 0; i < m_size; i++)
      str += " " + m_arr[i];*/
   return str + " ]";
}