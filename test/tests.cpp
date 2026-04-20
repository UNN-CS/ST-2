#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;
const double EPS = 1e-9;

TEST(CircleTest, ConstructorSetsRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(CircleTest, ConstructorCalculatesFerence) {
    Circle c(5.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, EPS);
}

TEST(CircleTest, ConstructorCalculatesArea) {
    Circle c(5.0);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPS);
}

TEST(CircleTest, SetRadiusUpdatesFerenceAndArea) {
    Circle c(2.0);
    c.setRadius(4.0);
    EXPECT_NEAR(c.getRadius(), 4.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 4.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 16.0, EPS);
}

TEST(CircleTest, SetFerenceUpdatesRadiusAndArea) {
    Circle c(1.0);
    c.setFerence(2 * PI * 3.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 3.0, EPS);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
}

TEST(CircleTest, SetAreaUpdatesRadiusAndFerence) {
    Circle c(1.0);
    c.setArea(PI * 25.0);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPS);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, EPS);
}

TEST(CircleTest, GetRadiusReturnsCorrectValue) {
    Circle c(7.5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.5);
}

TEST(CircleTest, GetFerenceReturnsCorrectValue) {
    Circle c(2.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 2.0, EPS);
}

TEST(CircleTest, GetAreaReturnsCorrectValue) {
    Circle c(3.0);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, NegativeRadiusIgnored) {
    Circle c(5.0);
    c.setRadius(-10.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(CircleTest, NegativeFerenceIgnored) {
    Circle c(5.0);
    double oldFerence = c.getFerence();
    c.setFerence(-10.0);
    EXPECT_NEAR(c.getFerence(), oldFerence, EPS);
}

TEST(CircleTest, NegativeAreaIgnored) {
    Circle c(5.0);
    double oldArea = c.getArea();
    c.setArea(-10.0);
    EXPECT_NEAR(c.getArea(), oldArea, EPS);
}

TEST(CircleTest, MultipleSetOperations) {
    Circle c(2.0);
    c.setRadius(3.0);
    c.setFerence(4 * PI);
    EXPECT_NEAR(c.getRadius(), 2.0, EPS);
    c.setArea(PI * 9.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e10);
    EXPECT_NEAR(c.getRadius(), 1e10, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e10, EPS);
    EXPECT_NEAR(c.getArea(), PI * 1e20, EPS);
}

TEST(CircleTest, SmallRadius) {
    Circle c(1e-10);
    EXPECT_NEAR(c.getRadius(), 1e-10, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e-10, EPS);
    EXPECT_NEAR(c.getArea(), PI * 1e-20, EPS);
}

TEST(EarthRopeTest, GapPositive) {
    double gap = solveEarthRopeProblem();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthRopeTest, GapCorrectValue) {
    double gap = solveEarthRopeProblem();
    EXPECT_NEAR(gap, 0.15915494309189535, 1e-8);
}

TEST(EarthRopeTest, GapDoesNotDependOnRadius) {
    double gap1 = solveEarthRopeProblem();
    Circle testPlanet(1000.0);
    double ropeLength = testPlanet.getFerence();
    Circle newPlanet(0);
    newPlanet.setFerence(ropeLength + 1.0);
    double gap2 = newPlanet.getRadius() - testPlanet.getRadius();
    EXPECT_NEAR(gap1, gap2, 1e-9);
}

TEST(PoolTest, PathCostPositive) {
    PoolResult result = solvePoolProblem();
    EXPECT_GT(result.pathCost, 0.0);
}

TEST(PoolTest, FenceCostPositive) {
    PoolResult result = solvePoolProblem();
    EXPECT_GT(result.fenceCost, 0.0);
}

TEST(PoolTest, TotalCostPositive) {
    PoolResult result = solvePoolProblem();
    EXPECT_GT(result.totalCost, 0.0);
}

TEST(PoolTest, PathAreaCorrect) {
    double expectedArea = PI * ((4.0 * 4.0) - (3.0 * 3.0));
    PoolResult result = solvePoolProblem();
    EXPECT_NEAR(result.pathCost / 1000.0, expectedArea, EPS);
}

TEST(PoolTest, FenceLengthCorrect) {
    double expectedFerence = 2 * PI * 4.0;
    PoolResult result = solvePoolProblem();
    EXPECT_NEAR(result.fenceCost / 2000.0, expectedFerence, EPS);
}

TEST(PoolTest, ExactValuesMatch) {
    PoolResult result = solvePoolProblem();
    EXPECT_NEAR(result.pathCost, 21991.14857512855, 1e-5);
    EXPECT_NEAR(result.fenceCost, 50265.48245743669, 1e-5);
    EXPECT_NEAR(result.totalCost, 72256.63103256524, 1e-5);
}

TEST(PoolTest, PathAreaLessThanOuterArea) {
    Circle outer(4.0);
    PoolResult result = solvePoolProblem();
    double pathArea = result.pathCost / 1000.0;
    EXPECT_LT(pathArea, outer.getArea());
    EXPECT_GT(pathArea, 0.0);
}