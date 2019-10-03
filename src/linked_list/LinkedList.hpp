#pragma once

#include <stdlib.h>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

namespace datastruct { namespace linkedlist
{
  template<typename T>
  class LinkedList {

  public:
    /** Constructor **/
    LinkedList();

    /** Destructor **/
    ~LinkedList();

    /**
     * Gets the number of elements in the list
     */
    size_t size() const;

    /**
     * Checks if the list is empty
     */
    const bool empty() const;

    /**
     * Adds an element as last element in the list
     */
    void push_back(const T& iData);

    /**
     * Adds an element as first element in the list
     */
    void push_front(const T& iData);

    /**
     * Gets the first element, if exists
     */
    T& front() const;

    /**
     * Gets the iPosition-th element, if exists
     */
    T& get_element(const uint32_t& iPosition) const;

  private:

    struct Node
    {
      T _data;
      Node *_next;
      Node(T iValue, Node* iNext) : _data(iValue), _next(iNext)
      {}
    };

    Node *_head;
    size_t _size;
  };

  template<typename T>
  LinkedList<T>::LinkedList()
  : _head(NULL), _size(0)
  {

  }

  template<typename T>
  LinkedList<T>::~LinkedList()
  {
    Node *toBeDeletedNode;
    while (_head != NULL)
    {
      toBeDeletedNode = _head;
      _head = _head->_next;
      delete toBeDeletedNode;
    }
  }

  template<typename T>
  size_t LinkedList<T>::size() const
  {
    return _size;
  }

  template<typename T>
  const bool LinkedList<T>::empty() const
  {
    return _size == 0;
  }

}}
