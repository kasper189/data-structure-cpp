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

TEST(LinkedListTest, BackInsertShouldIncreaseSize)
{
  LinkedList<std::string> aStringList;
  ASSERT_EQ(size_t(0), aStringList.size());

  std::string aString("Test string");
  aStringList.push_back(aString);
  ASSERT_FALSE(aStringList.empty());
  ASSERT_EQ(size_t(1), aStringList.size());
}

TEST(LinkedListTest, BasePushAndFront)
{
  LinkedList<std::string> aStringList;
  ASSERT_EQ(size_t(0), aStringList.size());

  std::string aExpectedString("Test string");
  aStringList.push_back(aExpectedString);

  const std::string aCurrentString = aStringList.front();
  ASSERT_EQ(aExpectedString, aCurrentString);
}


TEST(LinkedListTest, DoublePushAndSingleFront)
{
  LinkedList<int> aList;
  aList.push_back(0);
  aList.push_back(1);

  const int aInt = aList.front();
  ASSERT_EQ(0, aInt);
}
