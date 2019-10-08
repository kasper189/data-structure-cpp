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
