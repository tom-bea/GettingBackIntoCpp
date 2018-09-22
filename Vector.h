#pragma once

#include <string>
#include <iostream>

template <class Type>
class Vector
{
private:
   class Node
   {
   private:
      Type m_data;

   public:
      Node(const Type & data) : m_data(data) {}

      Type & getData() { return m_data; }
      bool setData(const Type & data);
   };

   size_t m_size;
   size_t m_capacity;
   Node** m_arr;

public:
   Vector(const size_t capacity = 10);
   ~Vector();

   void resize(const size_t capacity);

   size_t size() const { return m_size; }
   size_t capacity() const { return m_capacity; }

   void appendToEnd(const Type & data);
   Type & operator[](const size_t i);
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
   for (size_t i = 0; i < m_size; i++)
      delete m_arr[i];
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

   delete[] m_arr;
   m_arr = NULL;
   m_arr = tempArr;
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
   if (i > m_size)
   {
      std::cout << "i must be LESS than " << m_size << std::endl;
      return m_arr[0]->getData();
   }
   return m_arr[i]->getData();
}

template <class Type>
bool Vector<Type>::Node::setData(const Type & data)
{
   m_data = data;
   return true;
}