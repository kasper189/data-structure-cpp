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

