#pragma once

#include <stdlib.h>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

namespace datastruct { namespace stack
{
  template<typename T>
  class Stack {

  public:
    /** Constructor **/
	Stack(const size_t& iSize);

    /** Destructor **/
    ~Stack();

    /**
     * Checks if the stack is empty
     */
    const bool empty() const;

    /**
     * Gets the number of elements in the stack
     */
    size_t size() const;

    /**
     * Gets the top of the stack, if exists
     */
    const T& top() const;

    /**
     * Adds an element on top of the stack
     */
    void push(const T& iData);


    /**
     * Removes the element on top of the stack, if exists
     */
    void pop();

    /**
     * Swaps the contents of the two stacks
     */
    void swap(Stack<T>& ioOther);

  private:
    std::vector<T> _data;
    size_t _size;
    size_t _limit;

  };

  template<typename T>
  Stack<T>::Stack(const size_t& iSize)
  : _size(0), _limit(iSize)
  {
	if(iSize <= 0) {
	  //Should not happen seen that size_t is a unsigned int
	  throw std::runtime_error("The stack has to have size greater than zero.");
	}
    _data.reserve(iSize);
  }

  template<typename T>
  Stack<T>::~Stack() {}

  template<typename T>
  const bool Stack<T>::empty() const {
    return _size == 0;
  }

  template<typename T>
  size_t Stack<T>::size() const {
	return _size;
  }

  template<typename T>
  const T& Stack<T>::top() const {
	throw std::runtime_error("Not implemented");
  }

  template<typename T>
  void Stack<T>::push(const T& iData) {
    throw std::runtime_error("Not implemented");
  }

  template<typename T>
  void Stack<T>::pop() {
	throw std::runtime_error("Not implemented");
  }

  template<typename T>
  void Stack<T>::swap(Stack<T>& ioOther) {
    throw std::runtime_error("Not implemented");
  }

}}
