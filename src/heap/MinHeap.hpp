#pragma once

#include "Heap.hpp"

namespace datastruct { namespace heap
{
  template<typename T>
  class MinHeap : public Heap<T, std::greater<T>> {

  public:
    /** Constructor **/
    MinHeap(size_t iSize);

    /** Destructor **/
    virtual ~MinHeap() {}

    /**
     * Gets the minimum element, if exists
     */
    const T& get_min() const;

    /**
     * Deletes the minimum element, if exists
     */
    void delete_min();

  };

  template<typename T>
  MinHeap<T>::MinHeap(size_t iSize)
  : Heap<T, std::greater<T>>(iSize, std::greater<T>())
  {}

  template<typename T>
  const T& MinHeap<T>::get_min() const {
    return Heap<T, std::greater<T>>::get_root();
  }

  template<typename T>
  void MinHeap<T>::delete_min() {
    Heap<T, std::greater<T>>::delete_root();
  }

}}
