#pragma once

#include "Collection.h"
#include <iostream>

template <class Type>
class Vector : public Collection<Type>
{
private:
   typedef Collection<Type>::Node Node;
   typedef Collection<Type>::iterator iterator;

   size_t m_size;
   size_t m_capacity;
   Node** m_arr;

public:
   Vector(const size_t capacity = 10);
   // TODO: clone constructor
   ~Vector();

   void resize(const size_t capacity);

   size_t size() const { return m_size; }
   size_t capacity() const { return m_capacity; }

   void insert(const Type& data);
   void insert(const Type & data, const size_t ind);
   void remove(const size_t ind);
   void clear();
   void appendToEnd(const Type & data);
   Type & operator[](const size_t i);

   iterator begin() { return iterator(m_arr); }
   iterator end() { return iterator(m_arr + m_size); }
};

template <class Type>
Vector<Type>::Vector(const size_t capacity)
{
   m_arr = new Node*[capacity];
   m_capacity = capacity;
   m_size = 0;
}

template <class Type>
Vector<Type>::~Vector()
{
   clear();
   delete[] m_arr;
}

template <class Type>
void Vector<Type>::resize(const size_t capacity)
{
   Node** tempArr = new Node*[capacity];
   size_t end = (capacity > m_size) ? m_size : capacity;
   m_capacity = capacity;

   for (size_t i = 0; i < end; i++)
      tempArr[i] = m_arr[i];

   for (size_t i = end; i < m_size; i++)
   {
      delete m_arr[i];
      m_arr[i] = NULL;
   }

   delete[] m_arr;
   m_arr = NULL;
   m_arr = tempArr;
}

template <class Type>
void Vector<Type>::insert(const Type & data, const size_t ind)
{
   if (m_size == m_capacity)
      resize(m_capacity * 2);
   if (ind >= m_size)
   {
      appendToEnd(data);
      return;
   }

   for (size_t i = m_size; i > ind; i--)
      m_arr[i] = m_arr[i - 1];

   m_arr[ind] = new Node(data);

   ++m_size;
}

template <class Type>
void Vector<Type>::insert(const Type & data)
{
   if (m_size == m_capacity)
      resize(m_capacity * 2);
   appendToEnd(data);
}

template <class Type>
void Vector<Type>::remove(const size_t ind)
{
   if (m_size == 0)
      return;
   if (m_size == m_capacity / 2 - 1)
      resize(m_capacity / 2);

   if (ind < m_size)
      delete m_arr[ind];
   else
      delete m_arr[m_size];

   --m_size;

   for (size_t i = ind; i < m_size; i++)
      m_arr[i] = m_arr[i + 1];
}

template <class Type>
void Vector<Type>::clear()
{
   m_size = 0;
   for (size_t i = 0; i < m_size; i++)
      delete m_arr[i];
}

template <class Type>
void Vector<Type>::appendToEnd(const Type & data)
{
   if (m_size == m_capacity)
      resize(m_capacity * 2);
   m_arr[m_size++] = new Node(data);
}

template <class Type>
Type & Vector<Type>::operator[](const size_t i)
{
   if (i > m_size) //TODO: figure out if there is supposed to be >= or if > is fine
   {
      std::cout << "i must be LESS than " << m_size << std::endl;
      return **(m_arr[m_size - 1]);
   }
   return **(m_arr[i]);
}