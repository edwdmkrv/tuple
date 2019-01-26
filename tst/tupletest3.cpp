#include <version.hpp>

#include <gtest/gtest.h>

#include <tuple.hpp>

using namespace version3;

#include "tupletest.hpp"


TEST(TupleVersion3, TestCopy) {
	checkcopy();
}

TEST(TupleVersion3, TestMove) {
	checkmove();
}

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
