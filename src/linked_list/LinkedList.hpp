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
    T& get_element(const size_t& iPosition) const;

    typedef bool (* vCmpMethod)(T args);
    typedef void (* vPushFunction)(T args);

    /**
     * Fills a list with the elements that satisfy the condition
     * in the compare method
     */
    void select(vCmpMethod compare, LinkedList<T>& ioLList) const;

    /**
     * Removes the element at the head of the list, if exists
     */
    void pop_front();

    /**
     * Removes the element at the tail of the list, if exists
     */
    void pop_tail();

    /**
     * Removes the first element matching iData
     */
    void pop_element(const T& iData);

    /**
     * Finds the position of the fist element matching iData, if exists
     */
    uint32_t find_position(const T& iData) const;

    /**
     * Returns true if an element matching iData exists
     */
    const bool contains(const T& iData) const;

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
  void LinkedList<T>::push_front(const T& iData) {
    Node *aNode = new Node(iData, _head);
    _head = aNode;
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

  template<typename T>
  T& LinkedList<T>::get_element(const size_t& iPosition) const {
    if(size() < iPosition) {
      throw std::runtime_error("The list size is smaller");
    }
    Node *tmp, *node;
    tmp = _head;
    int cnt(0);
    while(cnt != iPosition && tmp != NULL) {
      node = tmp;
      tmp = tmp->_next;
      ++cnt;
    }
    return node->_data;
  }

  template<typename T>
  void LinkedList<T>::select(vCmpMethod compare, LinkedList<T>& ioLList) const {
    Node* tmp;
    tmp = _head;
    while(tmp != NULL) {
      if(compare(tmp->_data)) {
        ioLList.push_back(tmp->_data);
      }
      tmp = tmp->_next;
    }
  }

  template<typename T>
  void LinkedList<T>::pop_front() {
    if(empty()) {
      throw std::runtime_error("Empty list");
    }

    Node* tmp;
    tmp = _head;
    _head = _head->_next;
    delete tmp;
    --_size;
  }

  template<typename T>
  void LinkedList<T>::pop_tail() {
    if(empty()) {
      throw std::runtime_error("Empty list");
    }

    Node* tmp = _head;
    while(tmp->_next != NULL && tmp->_next->_next != NULL) {
     tmp = tmp->_next;
    }
    Node* toBeRemoved = tmp->_next;
    tmp->_next = NULL;
    delete toBeRemoved;
    --_size;
  }

  template<typename T>
  void LinkedList<T>::pop_element(const T& iData) {
    throw std::runtime_error("Not implemented");
  }

  template<typename T>
  uint32_t LinkedList<T>::find_position(const T& iData) const {
    size_t cnt(1);
    Node *tmp = _head;

    while(tmp != NULL) {
      if(tmp->_data == iData) {
        return cnt;
      }
      ++cnt;
      tmp = tmp->_next;
    }
    return -1;
  }

  template<typename T>
  const bool LinkedList<T>::contains(const T& iData) const {
    return find_position(iData) != -1;
  }

}}
