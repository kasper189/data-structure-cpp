#pragma once

#include <stdlib.h>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

namespace datastruct { namespace heap
{
  template<typename T, typename Compare>
  class Heap {

  public:
    /** Constructor **/
    Heap(size_t iSize, const Compare& iComparator);

    /** Destructor **/
    ~Heap() {}

    /**
     * Inserts an element in the heap
     */
    void insert(const T& iElement);

    /**
     * Checks if the heap is empty
     */
    const bool empty() const;

    /**
     * Gets the number of elements in the heap
     */
    const size_t size() const;

  protected:
    Compare _comparator;
    size_t _limit;
    size_t _size;
    std::vector<T> _data;

    /**
     * Gets the heap root element, if exists
     */
    const T& get_root() const;

    /**
     * Removes the heap root element, if exists
     */
    void delete_root();

    /**
     * Bottom-up reheapify
     */
    void swim(size_t iIndex);

    /**
     * Top-down reheapify
     */
    void sink(size_t iIndex);
  };

  template<typename T, typename Compare>
  Heap<T,Compare>::Heap(size_t iSize, const Compare& iComparator)
  : _comparator(iComparator), _limit(iSize + 1), _size(0)
  {
    if (iSize == 0)
    {
      throw std::runtime_error("Heap of size zero.");
    }
    _data.reserve(_limit);
  }

  template<typename T, typename Compare>
  const bool Heap<T,Compare>::empty() const {
    return _size == 0;
  }

  template<typename T, typename Compare>
  const size_t Heap<T,Compare>::size() const{
    return _size;
  }

  template<typename T, typename Compare>
  void Heap<T,Compare>::insert(const T& iElement){
    throw std::runtime_error("Not implemented");
  }

  template<typename T, typename Compare>
  const T& Heap<T,Compare>::get_root() const {
    throw std::runtime_error("Not implemented");
  }

  template<typename T, typename Compare>
  void Heap<T,Compare>::delete_root() {
    throw std::runtime_error("Not implemented");
  }

  template<typename T, typename Compare>
  void Heap<T,Compare>::swim(size_t iIndex){
    throw std::runtime_error("Not implemented");
  }

  template<typename T, typename Compare>
  void Heap<T,Compare>::sink(size_t iIndex) {
    throw std::runtime_error("Not implemented");
  }


}}
