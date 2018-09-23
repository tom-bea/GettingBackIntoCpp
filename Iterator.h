#pragma once

template <class NodePtrType, class StoredType>
class Iterator
{
private:
   NodePtrType* m_value;

public:
   Iterator(NodePtrType* start) : m_value(start) {}
   StoredType operator*() const { return ***m_value; }
   bool operator==(const Iterator& other) const { return m_value == other.m_value; }
   bool operator!=(const Iterator& other) const { return !(*this == other); }
   NodePtrType* operator++(int)
   {
      NodePtrType* ret = m_value;
      ++*this;
      return ret;
   }
   Iterator& operator++()
   {
      ++m_value;
      return *this;
   }
};