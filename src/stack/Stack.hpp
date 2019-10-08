#pragma once

#include <stdlib.h>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

namespace datastruct { namespace stack
{
  template<typename T>
  class Stack {

  public:
    /** Constructor **/
	  Stack();

    /** Destructor **/
    ~Stack();
  };

  template<typename T>
  Stack<T>::Stack() {}

  template<typename T>
  Stack<T>::~Stack() {}

}}
