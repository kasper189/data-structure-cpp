#include "gtest/gtest.h"

#include <string>
#include <stdlib.h>
#include <stdexcept>

#include "BST.hpp"

using datastruct::bst::BST;

TEST(BSTTest, SingleInsertAndTraverse)
{
  BST<int, int> aBST;
  aBST.insert(5, 5);
  std::string expectedOrder(":5:");
  ASSERT_EQ(expectedOrder, aBST.get_as_string());
}

TEST(BSTTest, DoubleIncInsertAndTraverse)
{
  BST<int, int> aBST;
  aBST.insert(5, 5);
  aBST.insert(6, 6);
  std::string expectedOrder(":5::6:");
  ASSERT_EQ(expectedOrder, aBST.get_as_string());
}

TEST(BSTTest, DoubleDecInsertAndTraverse)
{
  BST<int, int> aBST;
  aBST.insert(5, 5);
  aBST.insert(4, 4);
  std::string expectedOrder(":4::5:");
  ASSERT_EQ(expectedOrder, aBST.get_as_string());
}


