#include <gtest/gtest.h>

#include "../Constants.hpp"
#include "../Tree.hpp"

struct BauernTest : public ::testing::Test {
  virtual void SetUp() override {

  }

  virtual void TearDown() override {

  }
};

TEST_F(BauernTest, TestInitialFieldShouldNotEnd) {
  const Node root = Node(Constants::initial);
  const Tree tree = Tree(root);
  const bool hasEnded = tree.hasEnded(Utils::WHITE, tree.getRoot().getData());
  ASSERT_FALSE(hasEnded);

}