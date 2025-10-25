#ifndef MAI_OOP_LAB_04_PENTAGON_H
#define MAI_OOP_LAB_04_PENTAGON_H

#include "figure.h"


template <conceptPoint T>
class Pentagon : public Figure<T> {
public:
    Pentagon() = default;
    explicit Pentagon(std::vector<Point<T>> &vector) {
        for (int i = 0; i < vector.size(); ++i) {
            this->points.push_back(std::make_unique<Point<T>>(vector[i]));
        }
        this->n = 5;
    }

    std::string define_figure_type() const override {
        return "Pentagon";
    }

    size_t define_count_vertexes() const override {
        return 5;
    };
};




#endif //MAI_OOP_LAB_04_PENTAGON_H