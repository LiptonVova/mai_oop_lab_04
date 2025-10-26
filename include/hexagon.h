#ifndef MAI_OOP_LAB_04_HEXAGON_H
#define MAI_OOP_LAB_04_HEXAGON_H

#include "figure.h"

template <conceptPoint T>
class Hexagon : public Figure<T> {
public:
    Hexagon() = default;

    Hexagon(const Hexagon& other) {
        for (const auto& point_ptr : other.points) {
            this->points.push_back(std::make_unique<Point<T>>(*point_ptr));
        }
        this->n = other.n;
    }

    Hexagon(Hexagon &&other) noexcept {
        this->points = std::move(other.points);
        this->n = std::move(other.n);
    }

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

    Hexagon& operator=(const Hexagon& right_operand) {
        if (this != &right_operand) {
            this->points.clear();
            for (const auto &point_ptr : right_operand.points) {
                this->points.push_back(std::make_unique<Point<T> >(*point_ptr));
            }
            this->n = right_operand.n;
        }
        return *this;
    }

    Hexagon& operator=(Hexagon&& right_operand) noexcept {
        if (this != &right_operand) {
            this->points = std::move(right_operand.points);
            this->n = std::move(right_operand.n);
        }
        return *this;
    }
};



#endif //MAI_OOP_LAB_04_HEXAGON_H