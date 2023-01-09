#include "02526-data-stream.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Datastream, BasicTest) {
	Datastream datastream(4,3);

	EXPECT_FALSE(datastream.consec(4));
	EXPECT_FALSE(datastream.consec(4));
	EXPECT_TRUE(datastream.consec(4));
	EXPECT_FALSE(datastream.consec(3));
}
