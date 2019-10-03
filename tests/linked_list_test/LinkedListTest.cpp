#include "gtest/gtest.h"

#include <string>
#include <stdlib.h>
#include <stdexcept>

#include "LinkedList.hpp"

using datastruct::linkedlist::LinkedList;

TEST(LinkedListTest, InitTest)
{
	LinkedList<std::string> aStringList;
	ASSERT_TRUE(aStringList.empty());
	ASSERT_EQ(size_t(0), aStringList.size());
}
