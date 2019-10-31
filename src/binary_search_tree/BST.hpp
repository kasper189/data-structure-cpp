#pragma once

#include <stdlib.h>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

namespace datastruct { namespace bst
{
  template<typename K, typename T>
  class BST {

  public:
    /** Constructor **/
    BST();

    /** Destructor **/
    ~BST();

  private:

    struct Node
    {
      K _key;
      T _value;
      size_t _size;
      Node *_left, *_right;
      Node(K iKey, T iValue, size_t iSize) : _key(iKey), _value(iValue), _size(iSize)
      {}
    };

    Node *_root;
  };

}}
