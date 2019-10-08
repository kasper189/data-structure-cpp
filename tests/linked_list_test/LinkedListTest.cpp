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

TEST(LinkedListTest, FrontInsertShouldIncreaseSize)
{
  LinkedList<std::string> aStringList;
  ASSERT_EQ(size_t(0), aStringList.size());

  std::string aString("Test string");
  aStringList.push_front(aString);
  ASSERT_FALSE(aStringList.empty());
  ASSERT_EQ(size_t(1), aStringList.size());
}

TEST(LinkedListTest, BaseFrontPushAndFront)
{
  LinkedList<std::string> aStringList;
  ASSERT_EQ(size_t(0), aStringList.size());

  std::string aExpectedString("Test string");
  aStringList.push_front(aExpectedString);

  const std::string aCurrentString = aStringList.front();
  ASSERT_EQ(aExpectedString, aCurrentString);
}

TEST(LinkedListTest, DoubleFrontPushAndSingleFront)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_front(1);

  const int aInt = aList.front();
  ASSERT_EQ(1, aInt);
}

TEST(LinkedListTest, BaseFrontPushAndTail)
{
  LinkedList<std::string> aStringList;
  ASSERT_EQ(size_t(0), aStringList.size());

  std::string aExpectedString("Test string");
  aStringList.push_front(aExpectedString);

  const std::string aCurrentString = aStringList.tail();
  ASSERT_EQ(aExpectedString, aCurrentString);
}

TEST(LinkedListTest, TripleFrontPushAndSingleTail)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_front(10);
  aList.push_front(1);

  const int aInt = aList.tail();
  ASSERT_EQ(0, aInt);
}

TEST(LinkedListTest, BaseFrontPushAndFrontTail)
{
  LinkedList<std::string> aStringList;
  ASSERT_EQ(size_t(0), aStringList.size());

  std::string aExpectedString("Test string");
  aStringList.push_front(aExpectedString);
  ASSERT_EQ(aStringList.front(), aStringList.tail());
}

TEST(LinkedListTest, GetNthElementBase)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_front(10);
  aList.push_front(1);

  // 1 -> 10 -> 0
  const int aInt = aList.get_element(size_t(2));
  ASSERT_EQ(10, aInt);
}

TEST(LinkedListTest, ShorterListShouldThrow)
{
  LinkedList<std::string> aStringList;
  ASSERT_THROW(aStringList.get_element(size_t(2)), std::runtime_error);
}

TEST(LinkedListTest, GetNthElement)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);
  aList.push_front(1);
  aList.push_back(100);

  // 1 -> 0 -> 10 -> 100
  const int aInt = aList.get_element(size_t(4));
  ASSERT_EQ(100, aInt);
}

bool isSmallerThan(int target)
{
  return target < 5;
}

TEST(LinkedListTest, TraverseAndSelect)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);
  aList.push_front(1);
  aList.push_back(100);
  // 1 -> 0 -> 10 -> 100

  LinkedList<int> resultList;
  aList.select((LinkedList<int>::vCmpMethod) isSmallerThan, resultList);
  ASSERT_EQ(2, resultList.size());
}

TEST(LinkedListTest, PopFront)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);

  ASSERT_EQ(2, aList.size());

  aList.pop_front();
  ASSERT_EQ(1, aList.size());
  ASSERT_EQ(10, aList.front());
}

TEST(LinkedListTest, PopTail)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);

  ASSERT_EQ(2, aList.size());

  aList.pop_tail();
  ASSERT_EQ(1, aList.size());
  ASSERT_EQ(0, aList.front());
}

TEST(LinkedListTest, FindPositionBasic)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);
  aList.push_back(3);

  ASSERT_EQ(2, aList.find_position(10));
}

TEST(LinkedListTest, FindPositionNested)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);
  aList.push_back(3);

  ASSERT_EQ(
      10,
      aList.get_element(
          aList.find_position(10)
      )
  );
}

TEST(LinkedListTest, FindPositionNotFound)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);
  aList.push_back(3);

  ASSERT_EQ(-1, aList.find_position(100));
}

TEST(LinkedListTest, FoundContains)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);
  aList.push_back(3);

  ASSERT_TRUE(aList.contains(10));
}

TEST(LinkedListTest, NotFoundContains)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);
  aList.push_back(3);

  ASSERT_FALSE(aList.contains(100));
}

TEST(LinkedListTest, PopFrontWithFind)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);

  ASSERT_EQ(2, aList.size());

  aList.pop_element(0);
  ASSERT_EQ(1, aList.size());
  ASSERT_EQ(10, aList.front());
}

TEST(LinkedListTest, PopTailWithFind)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(10);

  ASSERT_EQ(2, aList.size());

  aList.pop_element(10);
  ASSERT_EQ(1, aList.size());
  ASSERT_EQ(0, aList.front());
}

TEST(LinkedListTest, PopElement)
{
  LinkedList<int> aList;
  aList.push_front(0);
  aList.push_back(1);
  aList.push_back(2);

  ASSERT_EQ(3, aList.size());

  aList.pop_element(1);
  ASSERT_EQ(2, aList.size());
  ASSERT_EQ(0, aList.front());
  ASSERT_EQ(2, aList.tail());
}
