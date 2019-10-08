#include "gtest/gtest.h"

#include <string>
#include <stdlib.h>
#include <stdexcept>

#include "Stack.hpp"

using datastruct::stack::Stack;

TEST(StackTest, InitTest)
{
	Stack<std::string> aStack;
	ASSERT_TRUE(true);
}
