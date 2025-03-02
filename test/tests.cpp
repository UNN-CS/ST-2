// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <iostream>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, RadiusTest) {
  Circle c(10);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10);
  std::cout << "Radius: " << c.getRadius() << std::endl;
}

TEST(CircleTest, FerenceTest) {
  Circle c(10);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 10);
  std::cout << "Ference: " << c.getFerence() << std::endl;
}

TEST(CircleTest, AreaTest) {
  Circle c(10);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 10 * 10);
  std::cout << "Area: " << c.getArea() << std::endl;
}

TEST(CircleTest, SetRadiusTest) {
  Circle c(10);
  c.setRadius(20);
  EXPECT_DOUBLE_EQ(c.getRadius(), 20);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 20);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 20 * 20);
  std::cout << "Set Radius: " << c.getRadius() << std::endl;
}

TEST(CircleTest, SetFerenceTest) {
  Circle c(10);
  c.setFerence(2 * M_PI * 20);
  EXPECT_DOUBLE_EQ(c.getRadius(), 20);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 20);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 20 * 20);
  std::cout << "Set Ference: " << c.getFerence() << std::endl;
}

TEST(CircleTest, SetAreaTest) {
  Circle c(10);
  c.setArea(M_PI * 20 * 20);
  EXPECT_DOUBLE_EQ(c.getRadius(), 20);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 20);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 20 * 20);
  std::cout << "Set Area: " << c.getArea() << std::endl;
}

TEST(CircleTest, DefaultConstructorTest) {
  Circle c(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
  std::cout << "Default Constructor - Radius: " << c.getRadius()
            << ", Ference: " << c.getFerence() << ", Area: " << c.getArea()
            << std::endl;
}

TEST(CircleTest, NegativeRadiusTest) {
  Circle c(-10);
  EXPECT_DOUBLE_EQ(c.getRadius(), -10);
  EXPECT_DOUBLE_EQ(c.getFerence(), -2 * M_PI * 10);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 10 * 10);
  std::cout << "Negative Radius - Radius: " << c.getRadius()
            << ", Ference: " << c.getFerence() << ", Area: " << c.getArea()
            << std::endl;
}

TEST(CircleTest, SetNegativeRadiusTest) {
  Circle c(10);
  EXPECT_THROW(c.setRadius(-20), std::invalid_argument);
  std::cout << "Set Negative Radius - Exception thrown" << std::endl;
}

TEST(CircleTest, SetNegativeFerenceTest) {
  Circle c(10);
  EXPECT_THROW(c.setFerence(-2 * M_PI * 20), std::invalid_argument);
  std::cout << "Set Negative Ference - Exception thrown" << std::endl;
}

TEST(CircleTest, SetNegativeAreaTest) {
  Circle c(10);
  EXPECT_THROW(c.setArea(-M_PI * 20 * 20), std::invalid_argument);
  std::cout << "Set Negative Area - Exception thrown" << std::endl;
}

TEST(CircleTest, ZeroRadiusTest) {
  Circle c(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
  std::cout << "Zero Radius - Radius: " << c.getRadius()
            << ", Ference: " << c.getFerence() << ", Area: " << c.getArea()
            << std::endl;
}

TEST(CircleTest, ZeroFerenceTest) {
  Circle c(10);
  c.setFerence(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
  std::cout << "Zero Ference - Radius: " << c.getRadius()
            << ", Ference: " << c.getFerence() << ", Area: " << c.getArea()
            << std::endl;
}

TEST(CircleTest, ZeroAreaTest) {
  Circle c(10);
  c.setArea(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
  std::cout << "Zero Area - Radius: " << c.getRadius()
            << ", Ference: " << c.getFerence() << ", Area: " << c.getArea()
            << std::endl;
}

TEST(TaskTest, CalculateGapTest) {
  double gap = calculateGap(6378.1, 1);
  EXPECT_NEAR(gap, 0.15915494309189535, 1e-6);
  std::cout << "Gap: " << gap << std::endl;
}

TEST(TaskTest, CalculateCostTest) {
  double cost = calculateCost(3, 1);
  EXPECT_DOUBLE_EQ(cost, 1000 * (M_PI * 16 - M_PI * 9) + 2000 * (2 * M_PI * 4));
  std::cout << "Cost: " << cost << std::endl;
}

TEST(TaskTest, CalculateGapZeroAddedLengthTest) {
  double gap = calculateGap(6378.1, 0);
  EXPECT_DOUBLE_EQ(gap, 0);
  std::cout << "Calculate Gap Zero Added Length - Gap: " << gap << std::endl;
}

TEST(TaskTest, CalculateGapNegativeAddedLengthTest) {
  EXPECT_THROW(calculateGap(6378.1, -1), std::invalid_argument);
  std::cout << "Calculate Gap Negative Added Length - Exception thrown"
            << std::endl;
}

TEST(TaskTest, CalculateCostZeroPathWidthTest) {
  double cost = calculateCost(3, 0);
  EXPECT_DOUBLE_EQ(cost, 0);
  std::cout << "Calculate Cost Zero Path Width - Cost: " << cost << std::endl;
}

TEST(TaskTest, CalculateCostNegativePathWidthTest) {
  double cost = calculateCost(3, -1);
  EXPECT_DOUBLE_EQ(cost, 0);
  std::cout << "Calculate Cost Negative Path Width - Cost: " << cost
            << std::endl;
}

TEST(TaskTest, CalculateCostZeroPoolRadiusTest) {
  double cost = calculateCost(0, 1);
  EXPECT_DOUBLE_EQ(cost, 0);
  std::cout << "Calculate Cost Zero Pool Radius - Cost: " << cost << std::endl;
}

TEST(TaskTest, CalculateCostNegativePoolRadiusTest) {
  double cost = calculateCost(-3, 1);
  EXPECT_DOUBLE_EQ(cost, 0);
  std::cout << "Calculate Cost Negative Pool Radius - Cost: " << cost
            << std::endl;
}
