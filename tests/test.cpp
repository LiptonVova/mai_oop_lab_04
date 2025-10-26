#include <gtest/gtest.h>
#include <memory>
#include <cmath>
#include "../include/array.h"
#include "../include/figure.h"
#include "../include/rhombus.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"




TEST(RhombusTest, AreaAndCenter) {
    std::vector<Point<double>> points = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
    Rhombus<double> rhombus(points);

    EXPECT_DOUBLE_EQ(static_cast<double>(rhombus), 8.0);

    auto center = rhombus.define_centre_figure();
    EXPECT_DOUBLE_EQ(center->x, 0.0);
    EXPECT_DOUBLE_EQ(center->y, 0.0);
}


TEST(PentagonTest, AreaAndCenter) {
    std::vector<Point<double>> points = {{0, 2}, {2, 1}, {1, -1}, {-1, -1}, {-2, 1}};
    Pentagon<double> pentagon(points);

    double area = static_cast<double>(pentagon);
    EXPECT_GT(area, 0);

    auto center = pentagon.define_centre_figure();
    EXPECT_NEAR(center->x, 0.0, 0.001);
    EXPECT_NEAR(center->y, 0.4, 0.001);
}


TEST(HexagonTest, AreaAndCenter) {
    std::vector<Point<double>> points = {{2, 0}, {1, 1}, {-1, 1}, {-2, 0}, {-1, -1}, {1, -1}};
    Hexagon<double> hexagon(points);

    double area = static_cast<double>(hexagon);
    EXPECT_GT(area, 0);

    auto center = hexagon.define_centre_figure();
    EXPECT_DOUBLE_EQ(center->x, 0.0);
    EXPECT_DOUBLE_EQ(center->y, 0.0);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}