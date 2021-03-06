#include <version.hpp>

#include <gtest/gtest.h>

#include <tuple.hpp>

using namespace version2;

#include "tupletest.hpp"


TEST(TupleVersion2, TestCopy) {
	checkcopy();
}

TEST(TupleVersion2, TestMove) {
	checkmove();
}

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
