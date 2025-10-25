#ifndef MAI_OOP_LAB_04_RHOMBUS_H
#define MAI_OOP_LAB_04_RHOMBUS_H

#include "figure.h"



template <conceptPoint T>
class Rhombus : public Figure<T> {
public:
    Rhombus() = default;
    explicit Rhombus(std::vector<Point <T> > &vector) {
        for (int i = 0; i < vector.size(); ++i) {
            this->points.push_back(std::make_unique<Point<T> >(vector[i]));
        }
        this->n = 4;
    }

    std::string define_figure_type() const override {
        return "Rhombus";
    }

    size_t define_count_vertexes() const override {
        return 4;
    };



};


#endif //MAI_OOP_LAB_04_RHOMBUS_H