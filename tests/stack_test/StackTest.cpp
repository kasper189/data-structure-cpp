#include "gtest/gtest.h"

#include <string>
#include <stdlib.h>
#include <stdexcept>

#include "Stack.hpp"

using datastruct::stack::Stack;

TEST(StackTest, InitTest)
{
	Stack<std::string> aStack(5);
	ASSERT_TRUE(aStack.empty());
}

TEST(StackTest, InitSizeTest)
{
	Stack<std::string> aStack(5);
	ASSERT_TRUE(aStack.empty());
	ASSERT_EQ(0, aStack.size());
}

TEST(StackTest, SinglePushTest)
{
  Stack<int> aStack(5);
  ASSERT_TRUE(aStack.empty());

  aStack.push(50);
  ASSERT_EQ(1, aStack.size());
}

TEST(StackTest, MultiplePushTest)
{
  Stack<int> aStack(5);
  ASSERT_TRUE(aStack.empty());

  aStack.push(50);
  aStack.push(22);
  aStack.push(11);
  ASSERT_EQ(3, aStack.size());
}

TEST(StackTest, MultiplePushShouldThrowTest)
{
  Stack<int> aStack(2);
  ASSERT_TRUE(aStack.empty());

  aStack.push(50);
  aStack.push(22);
  ASSERT_THROW(aStack.push(11);, std::runtime_error);
}

TEST(StackTest, SinglePushAndTopTest)
{
  Stack<int> aStack(5);
  aStack.push(50);
  ASSERT_EQ(50, aStack.top());
}

TEST(StackTest, MutiplePushAndSingleTopTest)
{
  Stack<int> aStack(5);
  aStack.push(50);
  aStack.push(40);
  aStack.push(30);
  ASSERT_EQ(30, aStack.top());
}

TEST(StackTest, SinglePushAndPopTest)
{
  Stack<int> aStack(5);
  aStack.push(50);
  aStack.pop();
  ASSERT_EQ(0, aStack.size());
}

TEST(StackTest, MultipleOpsTest)
{
  Stack<int> aStack(5);
  aStack.push(50);
  aStack.push(40);
  ASSERT_EQ(40, aStack.top());
  aStack.push(30);
  aStack.pop();
  aStack.pop();
  ASSERT_EQ(50, aStack.top());
  aStack.pop();
  ASSERT_TRUE(aStack.empty());
}

