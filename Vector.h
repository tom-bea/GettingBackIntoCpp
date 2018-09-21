#pragma once

#include <string>

template <class T>
class Vector
{
private:
   class Node
   {
      T data;
   };

   size_t m_size;
   size_t m_capacity;
   Node** m_arr;

   typedef T* iterator;
   typedef const T* const_iterator;

public:
   Vector(const size_t capacity = 10);
   ~Vector();

   void resize(size_t capacity);

   size_t size() const { return m_size; }
   size_t capacity() const { return m_capacity; }

   void appendToEnd(const T el);
   T & operator[](const size_t i);

   iterator begin() { return &m_arr[0]; }
   const_iterator begin() const { return &m_arr[0]; }
   iterator end() { return &m_arr[m_size - 1]; }
   const_iterator end() const { return &m_arr[m_size - 1]; }

   std::string to_string() const;
};