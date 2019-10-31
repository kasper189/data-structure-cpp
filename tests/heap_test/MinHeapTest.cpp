#include "gtest/gtest.h"

#include <string>
#include <stdlib.h>
#include <stdexcept>

#include "MinHeap.hpp"

using datastruct::heap::MinHeap;

TEST(MinHeapTest, InitTest)
{
  MinHeap<int> aHeap(5);
	ASSERT_TRUE(aHeap.empty());
	ASSERT_EQ(0, aHeap.size());
}

TEST(MinHeapTest, TooManyInsertShouldThrowTest)
{
  MinHeap<int> aHeap(5);
  ASSERT_TRUE(aHeap.empty());
  ASSERT_NO_THROW(aHeap.insert(9));
  ASSERT_NO_THROW(aHeap.insert(10));
  ASSERT_NO_THROW(aHeap.insert(1));
  ASSERT_NO_THROW(aHeap.insert(2));
  ASSERT_NO_THROW(aHeap.insert(3));
  ASSERT_THROW(aHeap.insert(11), std::runtime_error);
}

TEST(MinHeapTest, FirstInsertGetMinTest)
{
  MinHeap<int> aHeap(5);
  aHeap.insert(9);
  aHeap.insert(4);
  ASSERT_EQ(4, aHeap.get_min());
}

TEST(MinHeapTest, SecondInsertGetMinTest)
{
  MinHeap<int> aHeap(5);
  aHeap.insert(4);
  aHeap.insert(9);
  ASSERT_EQ(4, aHeap.get_min());
}

TEST(MinHeapTest, FullFlowTest)
{
  MinHeap<int> aHeap(5);
  aHeap.insert(4);
  aHeap.insert(9);
  ASSERT_EQ(4, aHeap.get_min());

  aHeap.insert(1);
  ASSERT_EQ(1, aHeap.get_min());

  aHeap.delete_min();
  aHeap.delete_min();
  ASSERT_EQ(9, aHeap.get_min());
  ASSERT_EQ(1, aHeap.size());
}

