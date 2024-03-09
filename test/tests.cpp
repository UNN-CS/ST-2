// Copyright 2024 Kashin Stepan
#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include <random>

double getRandomDouble(double a, double b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(a, b);

    return dis(gen); //new number [a, b)
}

// NegativeValues
TEST(Circle, radiusNegativeValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        EXPECT_FALSE(circle.setRadius(getRandomDouble(-RADIUS_MAX,0)));
    }
}

TEST(Circle, ferenceNegativeValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        EXPECT_FALSE(circle.setFerence(getRandomDouble(-FERENCE_MAX,0)));
    }
}

TEST(Circle, areaNegativeValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        EXPECT_FALSE(circle.setArea(getRandomDouble(-AREA_MAX,0)));
    }
}

//NormalValues
TEST(Circle, radiusNormalValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        EXPECT_TRUE(circle.setRadius(getRandomDouble(0,RADIUS_MAX)));
    }
}

TEST(Circle, ferenceNormalValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        EXPECT_TRUE(circle.setFerence(getRandomDouble(0,FERENCE_MAX)));
    }
}

TEST(Circle, areaNormalValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        EXPECT_TRUE(circle.setArea(getRandomDouble(0,AREA_MAX)));
    }
}

//OverloadedValues
TEST(Circle, radiusOverloadedValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        EXPECT_FALSE(circle.setRadius(getRandomDouble(RADIUS_MAX + 1,DBL_MAX)));
    }
}

TEST(Circle, ferenceOverloadedValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        EXPECT_FALSE(circle.setFerence(getRandomDouble(FERENCE_MAX + 1,DBL_MAX)));
    }
}

TEST(Circle, areaOverloadedValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        EXPECT_FALSE(circle.setArea(getRandomDouble(AREA_MAX + 1,DBL_MAX)));
    }
}

//calculating
TEST(Circle, calculatingRadiusByFerence) {
    Circle circle;
    double randomFerence;
    for (int i = 0; i < 100; i++) {
        randomFerence = getRandomDouble(0,FERENCE_MAX);
        circle.setFerence(randomFerence);
        EXPECT_EQ(circle.getRadius(), randomFerence / (PI * 2));
    }
}

TEST(Circle, calculatingRadiusByArea) {
    Circle circle;
    double randomArea;
    for (int i = 0; i < 100; i++) {
        randomArea = getRandomDouble(0,AREA_MAX);
        circle.setArea(randomArea);
        EXPECT_EQ(circle.getRadius(), std::sqrt(randomArea / PI));
    }
}

TEST(Circle, calculatingFerenceByRadius) {
    Circle circle;
    double randomRadius;
    for (int i = 0; i < 100; i++) {
        randomRadius = getRandomDouble(0,RADIUS_MAX);
        circle.setRadius(randomRadius);
        EXPECT_EQ(circle.getFerence(), 2 * PI * randomRadius);
    }
}

TEST(Circle, calculatingFerenceByArea) {
    Circle circle;
    double randomArea;
    for (int i = 0; i < 100; i++) {
        randomArea = getRandomDouble(0,AREA_MAX);
        circle.setArea(randomArea);
        EXPECT_EQ(circle.getFerence(), 2 * PI * std::sqrt(randomArea / PI));
    }
}

TEST(Circle, calculatingAreaByRadius) {
    Circle circle;
    double randomRadius;
    for (int i = 0; i < 100; i++) {
        randomRadius = getRandomDouble(0,RADIUS_MAX);
        circle.setRadius(randomRadius);
        EXPECT_EQ(circle.getArea(), PI * pow(randomRadius, 2));
    }
}

TEST(Circle, calculatingAreaByFerence) {
    Circle circle;
    double randomFerence;
    for (int i = 0; i < 100; i++) {
        randomFerence = getRandomDouble(0,FERENCE_MAX);
        circle.setFerence(randomFerence);
        EXPECT_EQ(circle.getArea(), PI * pow(randomFerence / (PI * 2), 2));
    }
}

//defaltValues
TEST(Circle, defaltValues) {
    Circle circle;
    EXPECT_EQ(circle.getRadius(), -1);
    EXPECT_EQ(circle.getFerence(), -1);
    EXPECT_EQ(circle.getArea(), -1);
}

//ProtectionAgainstOverloadedValues
TEST(Circle, radiusProtectionAgainstOverloadedValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        circle.setRadius(getRandomDouble(RADIUS_MAX + 1, DBL_MAX));
        EXPECT_EQ(circle.getRadius(), -1);
        EXPECT_EQ(circle.getFerence(), -1);
        EXPECT_EQ(circle.getArea(), -1);
    }
}

TEST(Circle, ferenceProtectionAgainstOverloadedValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        circle.setFerence(getRandomDouble(FERENCE_MAX + 1, DBL_MAX));
        EXPECT_EQ(circle.getRadius(), -1);
        EXPECT_EQ(circle.getFerence(), -1);
        EXPECT_EQ(circle.getArea(), -1);
    }
}

TEST(Circle, areaProtectionAgainstOverloadedValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        circle.setArea(getRandomDouble(AREA_MAX + 1, DBL_MAX));
        EXPECT_EQ(circle.getRadius(), -1);
        EXPECT_EQ(circle.getFerence(), -1);
        EXPECT_EQ(circle.getArea(), -1);
    }
}

//ProtectionAgainstNegativeValues
TEST(Circle, radiusProtectionAgainstNegativeValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        circle.setRadius(getRandomDouble(-RADIUS_MAX, 0));
        EXPECT_EQ(circle.getRadius(), -1);
        EXPECT_EQ(circle.getFerence(), -1);
        EXPECT_EQ(circle.getArea(), -1);
    }
}

TEST(Circle, ferenceProtectionAgainstNegativeValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        circle.setFerence(getRandomDouble(-FERENCE_MAX, 0));
        EXPECT_EQ(circle.getRadius(), -1);
        EXPECT_EQ(circle.getFerence(), -1);
        EXPECT_EQ(circle.getArea(), -1);
    }
}

TEST(Circle, areaProtectionAgainstNegativeValues) {
    Circle circle;
    for (int i = 0; i < 100; i++) {
        circle.setArea(getRandomDouble(-AREA_MAX, 0));
        EXPECT_EQ(circle.getRadius(), -1);
        EXPECT_EQ(circle.getFerence(), -1);
        EXPECT_EQ(circle.getArea(), -1);
    }
}
