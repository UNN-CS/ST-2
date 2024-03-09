#include "pch.h"
#include "tasks.h"

TEST(CircleGetters, GetRadius) {
    circle c;
	c.setRadius(30);
    EXPECT_DOUBLE_EQ(30.0, c.getRadius());
    EXPECT_TRUE(true);
}

TEST(CircleGetters, GetFerense) {
	circle c;
	c.setFerense(30);
	EXPECT_DOUBLE_EQ(30.0, c.getFerense());
	EXPECT_TRUE(true);
}

TEST(CircleGetters, GetArea) {
	circle c;
	c.setArea(30);
	EXPECT_DOUBLE_EQ(30.0, c.getArea());
	EXPECT_TRUE(true);
}


TEST(CircleSetRadius, CalcFerense) {
	circle c;
	c.setRadius(30);
	EXPECT_DOUBLE_EQ(188.49555921538759430775, c.getFerense());
	EXPECT_TRUE(true);
}

TEST(CircleSetRadius, CalcArea) {
	circle c;
	c.setRadius(3);
	EXPECT_DOUBLE_EQ(28.274333882308138, c.getArea());
	EXPECT_TRUE(true);
}

TEST(CircleSetRadius, NegativeThrow) {
	circle c;
	ASSERT_ANY_THROW(c.setRadius(-1));
}


TEST(CircleSetFerense, CalcRadius) {
	circle c;
	c.setFerense(30);
	EXPECT_DOUBLE_EQ(4.7746482927568605, c.getRadius());
	EXPECT_TRUE(true);
}

TEST(CircleSetFerense, CalcArea) {
	circle c;
	c.setFerense(30);
	EXPECT_DOUBLE_EQ(71.6197243913529, c.getArea());
	EXPECT_TRUE(true);
}

TEST(CircleSetFerense, NegativeThrow) {
	circle c;
	ASSERT_ANY_THROW(c.setFerense(-1), "Trying to set negative Ferense");
}

TEST(CircleSetArea, CalcRadius) {
	circle c;
	c.setArea(30);
	EXPECT_DOUBLE_EQ(3.0901936161855166, c.getRadius());
	EXPECT_TRUE(true);
}

TEST(CircleSetArea, CalcFerense) {
	circle c;
	c.setArea(30);
	EXPECT_DOUBLE_EQ(19.416259125556994, c.getFerense());
	EXPECT_TRUE(true);
}

TEST(CircleSetArea, NegativeThrow) {
	circle c;
	ASSERT_ANY_THROW(c.setArea(-1), "Trying to set negative Area");
}


TEST(Tasks, Earth) {
	tasks t;
	EXPECT_DOUBLE_EQ(0.15915494319051504, t.earth());
	EXPECT_TRUE(true);
}

TEST(Tasks, Pool) {
	tasks t;
	EXPECT_DOUBLE_EQ(72256.6310325652426, t.pool());
	EXPECT_TRUE(true);
}

//-----------------------------------------------main

int main(int argc, char** argv) {
	int result_code = 0;

	::testing::TestEventListeners& listeners =
		::testing::UnitTest::GetInstance()->listeners();

	testing::InitGoogleTest(&argc, argv);

	result_code = RUN_ALL_TESTS();

	return result_code;
}