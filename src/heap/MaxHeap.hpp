#pragma once

#include "Heap.hpp"

namespace datastruct { namespace heap
{
  template<typename T>
  class MaxHeap : public Heap<T, std::less<T>> {

  public:
    /** Constructor **/
    MaxHeap(size_t iSize);

    /** Destructor **/
    virtual ~MaxHeap() {}

    /**
     *
     */
    const T& get_max() const;

    /**
     *
     */
    void delete_max(const T& iElement);

  };

  template<typename T>
  MaxHeap<T>::MaxHeap(size_t iSize)
  : Heap<T, std::less<T>>(iSize, std::less<T>())
  {}

  template<typename T>
  const T& MaxHeap<T>::get_max() const {
    return Heap<T, std::less<T>>::get_root();
  }

  template<typename T>
  void MaxHeap<T>::delete_max(const T& iElement) {
    Heap<T, std::less<T>>::delete_root();
  }

}}
