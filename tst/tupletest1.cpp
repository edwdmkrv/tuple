#include <version.hpp>

#include <gtest/gtest.h>

#include <tuple.hpp>

using namespace version1;

#include "tupletest.hpp"


TEST(TupleVersion1, TestCopy) {
	checkcopy();
}

TEST(TupleVersion1, TestMove) {
	checkmove();
}

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
