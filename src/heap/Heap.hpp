#pragma once

#include <stdlib.h>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <utility>

namespace datastruct { namespace heap
{
  template<typename T, typename Compare>
  class Heap {

  public:
    /** Destructor **/
    virtual ~Heap() {}

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

    /** Constructor **/
    Heap(size_t iSize, const Compare& iComparator);

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

    void exchange(const size_t iFirst, const size_t iSecond);
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
    if (_size == _limit - 1) {
      throw std::runtime_error("Full heap");
    }
    _data[++_size] = iElement;
    swim(_size);
  }

  template<typename T, typename Compare>
  const T& Heap<T,Compare>::get_root() const {
    if(empty()) {
      throw std::runtime_error("Empty heap");
    }
    return _data[1];
  }

  template<typename T, typename Compare>
  void Heap<T,Compare>::delete_root() {
    if (empty()) {
      throw std::runtime_error("Empty heap");
    }
    T root = std::move(_data[1]);
    exchange(1, _size--);
    sink(1);
  }

  template<typename T, typename Compare>
  void Heap<T,Compare>::swim(size_t iIndex){
    size_t elementIndex = iIndex;
    while (elementIndex > 1 && _comparator(_data[elementIndex / 2], _data[elementIndex])) {
      exchange(elementIndex / 2, elementIndex);
      elementIndex = elementIndex / 2;
    }
  }

  template<typename T, typename Compare>
  void Heap<T,Compare>::sink(size_t iIndex) {
    while(2 * iIndex <= _size) {
      size_t j(2 * iIndex);
      if(j < _size && _comparator(_data[j], _data[j+1])) j++;
      if (!_comparator(_data[iIndex], _data[j])) break;
      exchange(iIndex, j);
      iIndex = j;
    }
  }

  template<typename T, typename Compare>
  void Heap<T,Compare>::exchange(const size_t iFirst, const size_t iSecond) {
    T tmp = std::move(_data[iFirst]);
    _data[iFirst] = std::move(_data[iSecond]);
    _data[iSecond] = std::move(tmp);
  }


}}
