#include <iostream>
#include "include/figure.h"
#include "include/rhombus.h"
#include "include/pentagon.h"
#include "include/hexagon.h"
#include "include/array.h"

int main() {
    // {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
    Rhombus<double> rhombus;
    std::cout << "Enter a rhombus:\n";
    std::cin >> rhombus;

    // {{0, 2}, {2, 1}, {1, -1}, {-1, -1}, {-2, 1}};
    Pentagon<double> pentagon;
    std::cout << "Enter a pentagon:\n";
    std::cin >> pentagon;

    // {{2, 0}, {1, 1}, {-1, 1}, {-2, 0}, {-1, -1}, {1, -1}};
    Hexagon<double> hexagon;
    std::cout << "Enter a hexagon:\n";
    std::cin >> hexagon;

    Array<std::shared_ptr<Figure<double>>> figures;

    std::shared_ptr<Figure<double>> shared_ptr_rhombus_1 = std::make_shared<Rhombus<double>>(rhombus);
    std::shared_ptr<Figure<double>> shared_ptr_pentagon_1 = std::make_shared<Pentagon<double>>(pentagon);
    std::shared_ptr<Figure<double>> shared_ptr_hexagon_1 = std::make_shared<Hexagon<double>>(hexagon);

    figures.add(shared_ptr_rhombus_1);
    figures.add(shared_ptr_pentagon_1);
    figures.add(shared_ptr_hexagon_1);

    figures.print_array();
    std::cout << "Total area in array figures = " << figures.total_area() << '\n';


    std::cout << "\n\nAfter pop element index 0:\n";
    figures.pop(0);
    figures.print_array();



    std::cout << "\n\nTesting, array<Rhombus<int>>:\n";

    std::vector<Point<double>> rhombus_points_1 = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    std::vector<Point<double>> rhombus_points_2 = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};

    Rhombus<double> rhombus_1(rhombus_points_1);
    Rhombus<double> rhombus_2(rhombus_points_2);

    Array<Rhombus<double>> array_rhombuss;
    array_rhombuss.add(rhombus);
    array_rhombuss.add(rhombus_1);
    array_rhombuss.add(rhombus_2);


    array_rhombuss.print_array();
    std::cout << "Total area in array rhombus = " << array_rhombuss.total_area() << '\n';



    std::cout << "\n\nTesting equals: \n";
    std::cout << "Check rhombus_1 == rhombus ?\n";
    std::cout << "rhombus_1: " << rhombus_1 << '\n';
    std::cout << "rhombus: " << rhombus << '\n';

    std::cout << (rhombus_1 == rhombus ? "Equal" : "Not equal") << '\n';

    std::cout << '\n';
    std::cout << "Check rhombus == rhombus_2 ?\n";
    std::cout << "rhombus: " << rhombus << '\n';
    std::cout << "rhombus_2: " << rhombus_2 << '\n';

    std::cout << (rhombus == rhombus_2 ? "Equal" : "Not equal") << '\n';


    return 0;
}