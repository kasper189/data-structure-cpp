#include "gtest/gtest.h"

#include <string>
#include <stdlib.h>
#include <stdexcept>

#include "MaxHeap.hpp"

using datastruct::heap::MaxHeap;

TEST(MaxHeapTest, InitTest)
{
  MaxHeap<int> aHeap(5);
	ASSERT_TRUE(aHeap.empty());
	ASSERT_EQ(0, aHeap.size());
}

TEST(MaxHeapTest, TooManyInsertShouldThrowTest)
{
  MaxHeap<int> aHeap(5);
  ASSERT_TRUE(aHeap.empty());
  ASSERT_NO_THROW(aHeap.insert(9));
  ASSERT_NO_THROW(aHeap.insert(10));
  ASSERT_NO_THROW(aHeap.insert(1));
  ASSERT_NO_THROW(aHeap.insert(2));
  ASSERT_NO_THROW(aHeap.insert(3));
  ASSERT_THROW(aHeap.insert(11), std::runtime_error);
}

TEST(MaxHeapTest, FirstInsertGetMaxTest)
{
  MaxHeap<int> aHeap(5);
  aHeap.insert(9);
  aHeap.insert(4);
  ASSERT_EQ(9, aHeap.get_max());
}

TEST(MaxHeapTest, SecondInsertGetMaxTest)
{
  MaxHeap<int> aHeap(5);
  aHeap.insert(4);
  aHeap.insert(9);
  ASSERT_EQ(9, aHeap.get_max());
}

TEST(MaxHeapTest, FullFlowTest)
{
  MaxHeap<int> aHeap(5);
  aHeap.insert(4);
  aHeap.insert(9);
  ASSERT_EQ(9, aHeap.get_max());

  aHeap.insert(100);
  ASSERT_EQ(100, aHeap.get_max());

  aHeap.delete_max();
  aHeap.delete_max();
  ASSERT_EQ(4, aHeap.get_max());
  ASSERT_EQ(1, aHeap.size());
}

