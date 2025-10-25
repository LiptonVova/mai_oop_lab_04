#ifndef MAI_OOP_LAB_04_HEXAGON_H
#define MAI_OOP_LAB_04_HEXAGON_H

#include "figure.h"

template <conceptPoint T>
class Hexagon : public Figure<T> {
public:
    Hexagon() = default;
    Hexagon(std::vector<Point<T>> &vector) {
        for (int i = 0; i < vector.size(); ++i) {
            this->points.push_back(std::make_unique<Point<T>>(vector[i]));
        }
        this->n = 6;
    }

    std::string define_figure_type() const override {
        return "Hexagon";
    }

    size_t define_count_vertexes() const override {
        return 6;
    };
};



#endif //MAI_OOP_LAB_04_HEXAGON_H