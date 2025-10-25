#ifndef MAI_OOP_LAB_04_ARRAY_H
#define MAI_OOP_LAB_04_ARRAY_H

#include <iostream>
#include <memory>

template <class T>
class Array {
public:
    Array() : size(0), capacity(1) {
        data = std::make_unique<std::shared_ptr<T>[]>(capacity);
    }

    void add(T value) {
        if (this->size >= this->capacity) {
            this->resize();
        }
        this->data[size++] = std::make_shared<T>(std::move(value));
    }

    void resize() {
        this->capacity *= 2;
        std::unique_ptr<std::shared_ptr<T>[]> temp = std::make_unique<std::shared_ptr<T>[]>(this->capacity);
        for (size_t i = 0; i < this->size; ++i) {
            temp[i] = std::move(this->data[i]);
        }

        this->data = std::move(temp);
    }

    void print_array() {
        for (size_t i = 0; i < this->size; ++i) {
            std::cout << **(this->data[i]);
        }
    }



private:
    std::unique_ptr<std::shared_ptr<T>[]> data;
    size_t size;
    size_t capacity;
};



#endif //MAI_OOP_LAB_04_ARRAY_H