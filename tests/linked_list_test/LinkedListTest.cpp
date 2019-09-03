#include "gtest/gtest.h"

#include <string>
#include <stdlib.h>
#include <stdexcept>

#include "LinkedList.hpp"

//using datastruct::linkedlist::LinkedList;

TEST(LinkedListTest, Dummy)
{
	ASSERT_TRUE(true);
}

//TEST(LinkedListTest, InitTest)
//{
//	LinkedList<std::string> aStringList;
//	ASSERT_TRUE(aStringList.empty());
//}
//
//TEST(LinkedListTest, BackInsertShouldIncreaseSize)
//{
//	LinkedList<std::string> aStringList;
//	ASSERT_EQ(size_t(0), aStringList.size());
//
//	std::string aString("Test string");
//	aStringList.push_back(aString);
//	ASSERT_FALSE(aStringList.empty());
//	ASSERT_EQ(size_t(1), aStringList.size());
//}
//
//TEST(LinkedListTest, FrontInsertShouldIncreaseSize)
//{
//	LinkedList<std::string> aStringList;
//	ASSERT_EQ(size_t(0), aStringList.size());
//
//	std::string aString("Test string");
//	aStringList.push_front(aString);
//	ASSERT_FALSE(aStringList.empty());
//	ASSERT_EQ(size_t(1), aStringList.size());
//}
//
//TEST(LinkedListTest, EmptyListShouldThrow)
//{
//	LinkedList<std::string> aStringList;
//	ASSERT_THROW(aStringList.front(), std::runtime_error);
//}
//
//TEST(LinkedListTest, ListShouldReturnFront)
//{
//	LinkedList<std::string> aStringList;
//	std::string aBackString("back");
//	std::string aFrontString("front");
//
//	aStringList.push_back(aBackString);
//	ASSERT_EQ(aBackString, aStringList.front());
//
//	aStringList.push_front(aFrontString);
//	ASSERT_EQ(aFrontString, aStringList.front());
//
//	std::string aFinalString("final");
//	aStringList.push_back(aFinalString);
//	ASSERT_EQ(aFrontString, aStringList.front());
//}