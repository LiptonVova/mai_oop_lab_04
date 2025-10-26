#ifndef MAI_OOP_LAB_04_FIGURE_H
#define MAI_OOP_LAB_04_FIGURE_H

#include <iostream>
#include <memory>
#include <vector>

template <class T>
concept conceptPoint = std::is_arithmetic_v<T>;

template <conceptPoint T>
struct Point {
    T x, y;


    friend bool operator==(const Point& lhs, const Point& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};


template <conceptPoint T>
class Figure {
    friend std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
        os << "-----------------------------------------------------------------------------------------------\n";
        os << figure.define_figure_type() << ": \n";
        for (int i = 0; i < figure.n; ++i) {
            os << "    Point " << i + 1 << ": (x: " << figure.points[i]->x << ", y: " << figure.points[i]->y << ")\n";
        }
        os << "\n";
        os << "    Area: " << static_cast<double>(figure) << "\n";
        os << "    Point centre: " << "(x: " << figure.define_centre_figure()->x << ", y: " << figure.define_centre_figure()->y << ")\n";
        os << "-----------------------------------------------------------------------------------------------\n";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure<T>& figure) {
        size_t count_vertexes = figure.define_count_vertexes();
        for (int i = 0; i < count_vertexes; ++i) {
            Point<T> point;
            std::cout << "Enter a point in the format: x y: ";
            is >> point.x >> point.y;
            figure.points.push_back(std::make_unique<Point<T>>(point));
        }
        figure.n = count_vertexes;
        return is;
    }

    friend bool operator==(const Figure<T> &lhs, const Figure<T> &rhs) {
        if (lhs.define_figure_type() != rhs.define_figure_type()) {
            return false;
        }
        if (lhs.n != rhs.n) {
            return false;
        }

        for (size_t i = 0; i < lhs.n; i++) {
            if (*lhs.points[i] != *rhs.points[i]) {
                return false;
            }
        }

        return true;
    }

public:
    // Figure(const Figure& other) {
    //     for (const auto& point_ptr : other.points) {
    //         this->points.push_back(std::make_unique<Point<T>>(*point_ptr));
    //     }
    //     this->n = other.n;
    // }

    std::shared_ptr<Point<double>> define_centre_figure() const {
        std::shared_ptr<Point<double>> point_centre_figure = std::make_unique<Point<double>>();

        for (int i = 0; i < this->n; ++i) {
            point_centre_figure->x += this->points[i]->x;
            point_centre_figure->y += this->points[i]->y;
        }
        point_centre_figure->x /= static_cast<double>(this->n);
        point_centre_figure->y /= static_cast<double>(this->n);

        return point_centre_figure;
    }

    explicit operator double() const {
        double sum_1 = 0;
        double sum_2 = 0;
        int next_index = 0;
        for (int i = 0; i < this->n; ++i) {
            next_index = (i + 1) % this->n;
            sum_1 += this->points[i]->x * this->points[next_index]->y;
            sum_2 += this->points[next_index]->x * this->points[i]->y;
        }
        return std::abs(sum_1 - sum_2) / 2.0;
    }

    virtual std::string define_figure_type() const = 0;
    virtual size_t define_count_vertexes() const = 0;


    // Figure& operator=(const Figure& right_operand) {
    //     if (this != &right_operand) {
    //         this->points.clear();
    //         for (const auto &point_ptr : right_operand.points) {
    //             this->points.push_back(std::make_unique<Point<T> >(*point_ptr));
    //         }
    //         this->n = right_operand.n;
    //     }
    //     return *this;
    // }
    //
    // Figure& operator=(Figure&& right_operand) noexcept {
    //     if (this != &right_operand) {
    //         this->points = std::move(right_operand.points);
    //         this->n = std::move(right_operand.n);
    //     }
    //     return *this;
    // }

    virtual ~Figure() = default;

protected:
    std::vector<std::unique_ptr<Point<T>>> points;
    size_t n;
};




#endif //MAI_OOP_LAB_04_FIGURE_H