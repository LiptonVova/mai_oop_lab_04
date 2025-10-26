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

    Rhombus<int> rhombus_1(points);

    Rhombus<int> rhombus;
    std::cin >> rhombus;
    // std::cout << rhombus;


    std::cout << "Equal rhombus and rhombus_1? " << (rhombus_1 == rhombus ? "Equal" : "Not equal") << '\n';

    constexpr const Point<int> point_6(0, 2);

    points.push_back(point_6);

    Pentagon<int> pentagon(points);
    // std::cout << pentagon;

    constexpr const Point<int> point_7(5, 2);
    points.push_back(point_7);

    Hexagon<int> hexagon(points);
    // std::cout << hexagon;

    Array<std::shared_ptr<Figure<int>>> figures;

    std::shared_ptr<Figure<int>> shared_ptr_rhombus_1 = std::make_shared<Rhombus<int>>(rhombus);
    std::shared_ptr<Figure<int>> shared_ptr_pentagon_1 = std::make_shared<Pentagon<int>>(pentagon);
    std::shared_ptr<Figure<int>> shared_ptr_hexagon_1 = std::make_shared<Hexagon<int>>(hexagon);

    figures.add(shared_ptr_rhombus_1);
    figures.add(shared_ptr_pentagon_1);
    figures.add(shared_ptr_hexagon_1);

    figures.print_array();
    std::cout << "Total area in array figures = " << figures.total_area() << '\n';


    std::cout << "\n\n\n\n\n\n\n\n\n";

    figures.pop(0);
    figures.print_array();


    std::cout << "\n\n\n\n\n\n\n\n\n";

    Array<Rhombus<int>> array_rhombuss;
    array_rhombuss.add(rhombus);

    std::cout << "\n\n\n\n\n\n\n\n\n";
    std::cout << "Figures rhombus:\n";
    array_rhombuss.print_array();
    std::cout << "Total area in array rhombus = " << array_rhombuss.total_area() << '\n';


    return 0;
}