#include <gtest/gtest.h>

TEST(ARKANOID3000_tests, ARKANOID3000_tests_example)
{
    EXPECT_EQ(1, 1);
    EXPECT_NE(0, 1);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}