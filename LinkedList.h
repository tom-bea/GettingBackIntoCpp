#pragma once

#include "Collection.h"

template <class Type>
class LinkedList : Collection<Type>
{
private:
   typedef Collection<Type>::iterator iterator;

   class Node : public Collection<Type>::Node
   {
   private:
      Node* m_next;

   public:
      Node(const Type& data, Node* next = nullptr) : Collection<Type>::Node(data), m_next(next) {}
      Node(Node* other) : Node(**other, other->m_next) {}

      Node& operator++(int)
      {
         Node* ret = this;
         ++*this;
         return *ret;
      }
      Node& operator++()
      {
         ;
         return *this;
      }

      Node* next() const { return m_next; }
   };

   size_t m_size;
   Node* m_head;

public:
   LinkedList();
   ~LinkedList();

   void insert(const Type& data);
   void insert(const Type& data, const size_t ind);
   void insertAtHead(const Type& data);
   void insertAtTail(const Type& data);
   void clear();
   Type & operator[](const size_t i);

   iterator begin() { return iterator(nullptr); }
   iterator end() { return iterator(nullptr); }
};

template <class Type>
LinkedList<Type>::LinkedList()
{
   m_size = 0;
   m_head = nullptr;
}

template <class Type>
LinkedList<Type>::~LinkedList()
{
   clear();
}

template <class Type>
void LinkedList<Type>::insert(const Type& data)
{
   insertAtHead(data);
}

template <class Type>
void LinkedList<Type>::insert(const Type& data, const size_t ind)
{
   m_size++;

   if (ind == 0)
   {
      m_head = new Node(data, m_head);
      return;
   }

   Node* walker = new Node(m_head);
   for (size_t i = 0; i < ind - 1 && i < m_size - 1; i++)
      walker = walker->next();

   walker->next() = new Node(data, walker->next());

   delete walker;
}

template <class Type>
void LinkedList<Type>::insertAtHead(const Type& data)
{
   insert(data, 0);
}

template <class Type>
void LinkedList<Type>::insertAtTail(const Type& data)
{
   insert(data, m_size);
}

template <class Type>
void LinkedList<Type>::clear()
{
   if (m_size == 0)
      return;

   Node* curNode = m_head;
   Node* nextNode = m_head->next();

   while (nextNode != nullptr)
   {
      delete curNode;
      curNode = nextNode;
      nextNode = nextNode->next();
   }

   delete curNode;
}

template <class Type>
Type & LinkedList<Type>::operator[](const size_t i)
{
   if (i >= m_size)
   {
      std::cout << "i must be LESS than " << m_size << std::endl;
      return **m_head;
   }

   Node* walker = new Node(m_head);
   for (size_t j = 0; j < i; j++)
      walker = walker->next();

   Type ret = **walker;
   delete walker;
   return ret;
}