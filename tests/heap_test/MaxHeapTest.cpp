#include "gtest/gtest.h"

#include <string>
#include <stdlib.h>
#include <stdexcept>

#include "Heap.hpp"

using datastruct::heap::Heap;

TEST(HeapTest, InitTest)
{
  Heap<int, std::greater<int>> aHeap(5, std::greater<int>());
	ASSERT_TRUE(aHeap.empty());
	ASSERT_EQ(0, aHeap.size());
}

