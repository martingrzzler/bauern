#include <gtest/gtest.h>

#include "../Constants.hpp"
#include "../Tree.hpp"
#include "../Utils.hpp"

struct BauernTest : public ::testing::Test 
{

  Tree* tree;
  Node* root;

  virtual void SetUp() override 
  {
    root = new Node(Constants::initial);
    tree = new Tree(*root);
  }

  virtual void TearDown() override 
  {
    delete root;
    delete tree;
  }
};

TEST_F(BauernTest, TestInitialFieldShouldNotEnd) 
{

  const bool hasEnded = tree->hasEnded(Utils::WHITE, tree->getRoot().getData());
  ASSERT_FALSE(hasEnded);
}

TEST_F(BauernTest, TestForEachReverseShouldLoopInReverseOrder)
{
  auto callback = [](int row, int colum) 
  {
  };

  Utils::forEachBlackReverse(Constants::initial, callback);
}