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

TEST(BSTTest, InsertAndFindMin)
{
  BST<int, int> aBST;
  aBST.insert(5, 5);
  aBST.insert(4, 4);
  aBST.insert(9, 9);
  aBST.insert(1, 1);

  ASSERT_EQ(1, aBST.find_min());
}

TEST(BSTTest, LinearLeftInsertAndFindMin)
{
  BST<int, int> aBST;
  aBST.insert(5, 5);
  aBST.insert(4, 4);
  aBST.insert(3, 3);
  aBST.insert(2, 2);
  aBST.insert(1, 1);

  ASSERT_EQ(1, aBST.find_min());
}

TEST(BSTTest, LinearRightInsertAndFindMin)
{
  BST<int, int> aBST;
  aBST.insert(1, 1);
  aBST.insert(2, 2);
  aBST.insert(3, 3);
  aBST.insert(4, 4);
  aBST.insert(5, 5);

  ASSERT_EQ(1, aBST.find_min());
}

TEST(BSTTest, InsertAndFindMax)
{
  BST<int, int> aBST;
  aBST.insert(5, 5);
  aBST.insert(4, 4);
  aBST.insert(9, 9);
  aBST.insert(1, 1);

  ASSERT_EQ(9, aBST.find_max());
}

TEST(BSTTest, LinearLeftInsertAndFindMax)
{
  BST<int, int> aBST;
  aBST.insert(5, 5);
  aBST.insert(4, 4);
  aBST.insert(3, 3);
  aBST.insert(2, 2);
  aBST.insert(1, 1);

  ASSERT_EQ(5, aBST.find_max());
}

TEST(BSTTest, LinearRightInsertAndFindMax)
{
  BST<int, int> aBST;
  aBST.insert(1, 1);
  aBST.insert(2, 2);
  aBST.insert(3, 3);
  aBST.insert(4, 4);
  aBST.insert(5, 5);

  ASSERT_EQ(5, aBST.find_max());
}

TEST(BSTTest, DoubleInsertAndFind)
{
  BST<int, int> aBST;
  aBST.insert(1, 1);
  aBST.insert(2, 5);

  ASSERT_EQ(5, aBST.find(2));
}

TEST(BSTTest, LinearRightInsertAndFind)
{
  BST<int, int> aBST;
  aBST.insert(1, 1);
  aBST.insert(2, 2);
  aBST.insert(3, 3);
  aBST.insert(4, 4);
  aBST.insert(5, 5);

  ASSERT_EQ(4, aBST.find(4));
}



