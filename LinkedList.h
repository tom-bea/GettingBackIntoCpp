#pragma once

#include <iostream>

template <class Type>
class LinkedList
{
private:
   class Node;
   class Iterator;

   typedef Node* NodePtr;

   size_t m_size;
   NodePtr m_head, m_tail;

public:
   LinkedList();
   LinkedList(LinkedList& other);
   ~LinkedList();

   size_t size() const { return m_size; }

   void insert(const Type& data, const size_t ind);
   void insertAtHead(const Type& data);
   void insertAtTail(const Type& data);
   void remove(const size_t ind);
   void clear();
   Type & operator[](const size_t i);

   Iterator begin() { return Iterator(m_head); }
   Iterator end() { return Iterator(nullptr); }
};

template <class Type>
class LinkedList<Type>::Node
{
private:
   Type m_data;
   NodePtr m_prev, m_next;

public:
   Node(const Type& data, const NodePtr prev = nullptr, const NodePtr next = nullptr) : m_data(data), m_prev(prev), m_next(next) {}

   //bool operator=(const Type& newData) { m_data = newData; return true; }
   Type& getData() { return m_data; }
   NodePtr getPrev() { return m_prev; }
   bool setPrev(const NodePtr newPrev) { m_prev = newPrev; return true; }
   NodePtr getNext() { return m_next; }
   bool setNext(const NodePtr newNext) { m_next = newNext; return true; }
};

template <class Type>
class LinkedList<Type>::Iterator
{
private:
   NodePtr m_walker;

public:
   Iterator(NodePtr start) : m_walker(start) {}
   Type operator*() const { return m_walker->getData(); }
   bool operator==(const Iterator& other) const { return m_walker == other.m_walker; }
   bool operator!=(const Iterator& other) const { return !(*this == other); }
   Type operator++(int)
   {
      Type ret = m_walker->getData();
      ++*this;
      return ret;
   }
   Iterator& operator++()
   {
      m_walker = m_walker->getNext();
      return *this;
   }
};

template <class Type>
LinkedList<Type>::LinkedList()
{
   m_size = 0;
   m_head = nullptr;
   m_tail = nullptr;
}

template <class Type>
LinkedList<Type>::LinkedList(LinkedList<Type>& other)
{
   m_size = 0;
   m_head = nullptr;
   m_tail = nullptr;

   for (auto x : other)
      (*this).insertAtTail(x);
}

template <class Type>
LinkedList<Type>::~LinkedList()
{
   clear();
}

template <class Type>
void LinkedList<Type>::insert(const Type& data, const size_t ind)
{
   m_size++;

   if (m_size == 1)
   {
      m_head = m_tail = new Node(data);
      return;
   }

   if (ind == 0)
   {
      m_head = new Node(data, nullptr, m_head);
      if (m_head->getNext() != nullptr)
         m_head->getNext()->setPrev(m_head);
      return;
   }
   if (ind >= m_size - 1)
   {
      m_tail = new Node(data, m_tail);
      if (m_tail->getPrev() != nullptr)
         m_tail->getPrev()->setNext(m_tail);
      return;
   }

   NodePtr walker = m_head;
   for (size_t i = 0; i < ind - 1 && i < m_size - 1; i++)
      walker = walker->getNext();

   walker->setNext(new Node(data, walker, walker->getNext()));
   walker->getNext()->getNext()->setPrev(walker->getNext());
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
void LinkedList<Type>::remove(const size_t ind)
{
   if (m_size == 0)
      return;

   if (ind == 0)
   {
      NodePtr newHead = m_head->getNext();
      delete m_head;
      m_head = newHead;
      m_head->setPrev(nullptr);
      --m_size;
      return;
   }

   if (ind >= m_size - 1)
   {
      NodePtr newTail = m_tail->getPrev();
      delete m_tail;
      m_tail = newTail;
      m_tail->setNext(nullptr);
      --m_size;
      return;
   }

   NodePtr prev = m_head;
   NodePtr curr = m_head->getNext();
   for (size_t i = 1; i < ind && i < m_size; i++)
   {
      prev = curr;
      curr = curr->getNext();
   }
   prev->setNext(curr->getNext());
   curr->getNext()->setPrev(prev);
   delete curr;
   --m_size;
}

template <class Type>
void LinkedList<Type>::clear()
{
   if (m_size == 0)
      return;

   m_size = 0;

   NodePtr curNode = m_head;
   NodePtr nextNode = m_head->getNext();

   while (nextNode != nullptr)
   {
      delete curNode;
      curNode = nextNode;
      nextNode = nextNode->getNext();
   }

   delete curNode;

   m_head = nullptr;
   m_tail = nullptr;
}

template <class Type>
Type & LinkedList<Type>::operator[](const size_t i)
{
   if (i >= m_size)
   {
      std::cout << "i must be LESS than " << m_size << std::endl;
      return m_tail->getData();
   }

   NodePtr walker = m_head;
   for (size_t j = 0; j < i; j++)
      walker = walker->getNext();

   return walker->getData();
}