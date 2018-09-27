#pragma once

#include "Iterator.h"

template <class Type>
class Collection
{
protected:
   class Node
   {
   private:
      Type m_data;

   public:
      Node(const Type & data) : m_data(data) {}

      Type & operator*() { return m_data; }
   };

public:
   typedef Iterator<Node*, Type> iterator;

   virtual void insert(const Type& data) = 0;
   virtual void clear() = 0;

   virtual iterator begin() = 0;
   virtual iterator end() = 0;
};