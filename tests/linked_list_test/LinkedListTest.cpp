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

TEST(LinkedListTest, EmptyListShouldThrow)
{
  LinkedList<std::string> aStringList;
  ASSERT_THROW(aStringList.front(), std::runtime_error);
}

TEST(LinkedListTest, BasePushAndTail)
{
  LinkedList<std::string> aStringList;
  ASSERT_EQ(size_t(0), aStringList.size());

  std::string aExpectedString("Test string");
  aStringList.push_back(aExpectedString);

  const std::string aCurrentString = aStringList.tail();
  ASSERT_EQ(aExpectedString, aCurrentString);
}

TEST(LinkedListTest, DoublePushAndSingleTail)
{
  LinkedList<int> aList;
  aList.push_back(0);
  aList.push_back(10);
  aList.push_back(1);

  const int aInt = aList.tail();
  ASSERT_EQ(1, aInt);
}

TEST(LinkedListTest, BasePushAndFrontTail)
{
  LinkedList<std::string> aStringList;
  ASSERT_EQ(size_t(0), aStringList.size());

  std::string aExpectedString("Test string");
  aStringList.push_back(aExpectedString);
  ASSERT_EQ(aStringList.front(), aStringList.tail());
}
