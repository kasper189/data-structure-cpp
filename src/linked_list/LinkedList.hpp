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
    const T& front() const;

    /**
     * Gets the last element, if exists
     * Not optimized method, using a linear traversal
     */
    const T& tail() const;

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
  {}

  template<typename T>
  LinkedList<T>::~LinkedList() {
    Node *toBeDeletedNode;
    while (_head != NULL)
    {
      toBeDeletedNode = _head;
      _head = _head->_next;
      delete toBeDeletedNode;
    }
  }

  template<typename T>
  size_t LinkedList<T>::size() const {
    return _size;
  }

  template<typename T>
  const bool LinkedList<T>::empty() const {
    return _size == 0;
  }

  template<typename T>
  void LinkedList<T>::push_back(const T& iData) {
    Node *aNode = new Node(iData, NULL);
    if(_head == NULL){
      _head = aNode;
    }
    else {
      Node *tmp;
      tmp = _head;
      while(tmp->_next != NULL) {
        tmp = tmp->_next;
      }
      tmp->_next = aNode;
    }
    ++_size;
  }

  template<typename T>
  const T& LinkedList<T>::front() const {
   if(empty()) {
     throw std::runtime_error("Empty list");
   }
   return _head->_data;
  }

  template<typename T>
  const T& LinkedList<T>::tail() const {
    if(empty()) {
      throw std::runtime_error("Empty list");
    }
    Node* tmp = _head;
    while(tmp->_next != NULL) {
     tmp = tmp->_next;
    }
    return tmp->_data;
  }

}}
