#include <iostream>
#include "include/figure.h"
#include "include/rhombus.h"
#include "include/pentagon.h"
#include "include/hexagon.h"
#include "include/array.h"

int main() {

    std::vector <Point<int>> points;
    constexpr const Point<int> point_1(0, 0);
    constexpr const Point<int> point_2(1, 0);
    constexpr const Point<int> point_3(1, 1);
    constexpr const Point<int> point_4(0, 1);

    points.push_back(point_1);
    points.push_back(point_2);
    points.push_back(point_3);
    points.push_back(point_4);

    // Rhombus<int> rhombus(points);
    Rhombus<int> rhombus;
    std::cin >> rhombus;
    std::cout << rhombus;


    constexpr const Point<int> point_6(0, 2);

    points.push_back(point_6);

    Pentagon<int> pentagon(points);
    std::cout << pentagon;

    constexpr const Point<int> point_7(5, 2);
    points.push_back(point_7);

    Hexagon<int> hexagon(points);
    std::cout << hexagon;

    Array<Figure<int>*> figures;
    figures.add(&rhombus);
    figures.add(&pentagon);
    figures.add(&hexagon);

    figures.print_array();


    return 0;
}