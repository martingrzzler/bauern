#include <gtest/gtest.h>

struct ExampleTests : public ::testing::Test {
  virtual void SetUp() override {

  }

  virtual void TearDown() override {

  }
};

TEST(ExampleTests, DemonstrateGTestMacros) {
   EXPECT_EQ(true, true);
}

TEST_F(ExampleTests, TestWithExtra) {

}