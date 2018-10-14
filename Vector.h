#pragma once

#include <iostream>

template <class Type>
class Vector
{
private:
   class Node;
   class Iterator;

   size_t m_size;
   size_t m_capacity;
   Node** m_arr;

public:
   Vector(const size_t capacity = 10);
   Vector(Vector& other);
   ~Vector();

   void resize(const size_t capacity);

   size_t size() const { return m_size; }
   size_t capacity() const { return m_capacity; }

   void insert(const Type & data, const size_t ind);
   void remove(const size_t ind);
   void clear();
   void appendToEnd(const Type & data);
   Type & operator[](const size_t i);

   Iterator begin() { return Iterator(m_arr); }
   Iterator end() { return Iterator(m_arr + m_size); }
};

template <class Type>
class Vector<Type>::Node
{
private:
   Type m_data;

public:
   Node(const Type& data) : m_data(data) {}

   bool operator=(const Type& newData) { m_data = newData; return true; }
   Type& getData() { return m_data; }
};

template <class Type>
class Vector<Type>::Iterator
{
private:
   Node** m_walker;

public:
   Iterator(Node** start) : m_walker(start) {}
   Type operator*() const { return (*m_walker)->getData(); }
   bool operator==(const Iterator& other) const { return m_walker == other.m_walker; }
   bool operator!=(const Iterator& other) const { return !(*this == other); }
   Type operator++(int)
   {
      Type ret = (*m_walker)->getData();
      ++*this;
      return ret;
   }
   Iterator& operator++()
   {
      ++m_walker;
      return *this;
   }
};

template <class Type>
Vector<Type>::Vector(const size_t capacity)
{
   m_arr = new Node*[capacity];
   m_capacity = capacity;
   m_size = 0;
}

template <class Type>
Vector<Type>::Vector(Vector<Type>& other)
{
   m_capacity = other.m_capacity;
   m_size = other.m_size;
   m_arr = new Node*[m_capacity];

   for (Type x : other)
      this->appendToEnd(x);
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
   m_size = 0;

   for (size_t i = 0; i < end; i++)
   {
      tempArr[i] = m_arr[i];
      m_size++;
   }

   for (size_t i = end; i < m_size; i++)
   {
      delete m_arr[i];
      m_arr[i] = nullptr;
   }

   delete[] m_arr;
   m_arr = nullptr;
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
   for (size_t i = 0; i < m_size; i++)
      delete m_arr[i];
   m_size = 0;
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
      return m_arr[m_size - 1]->getData();
   }
   return m_arr[i]->getData();
}