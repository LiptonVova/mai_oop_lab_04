#ifndef MAI_OOP_LAB_04_PENTAGON_H
#define MAI_OOP_LAB_04_PENTAGON_H

#include "figure.h"


template <conceptPoint T>
class Pentagon : public Figure<T> {
public:
    Pentagon() = default;

    Pentagon(const Pentagon& other) {
        for (const auto& point_ptr : other.points) {
            this->points.push_back(std::make_unique<Point<T>>(*point_ptr));
        }
        this->n = other.n;
    }

    Pentagon(Pentagon&& other) noexcept {
        this->points = std::move(other.points);
        this->n = std::move(other.n);
    }

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

    Pentagon& operator=(const Pentagon& right_operand) {
        if (this != &right_operand) {
            this->points.clear();
            for (const auto &point_ptr : right_operand.points) {
                this->points.push_back(std::make_unique<Point<T> >(*point_ptr));
            }
            this->n = right_operand.n;
        }
        return *this;
    }

    Pentagon& operator=(Pentagon&& right_operand) noexcept {
        if (this != &right_operand) {
            this->points = std::move(right_operand.points);
            this->n = std::move(right_operand.n);
        }
        return *this;
    }
};




#endif //MAI_OOP_LAB_04_PENTAGON_H