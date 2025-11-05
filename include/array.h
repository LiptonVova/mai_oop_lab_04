#ifndef MAI_OOP_LAB_04_ARRAY_H
#define MAI_OOP_LAB_04_ARRAY_H

#include <iostream>
#include <memory>

template <class T>
class Array {
public:
    Array() : size(0), capacity(1) {
        data = std::make_shared<T[]>(capacity);
    }

    void add(T value) {
        if (this->size >= this->capacity) {
            this->resize();
        }
        this->data[this->size++] = std::move(value);
    }

    void resize() {
        this->capacity *= 2;
        std::shared_ptr<T[]> temp = std::make_shared<T[]>(this->capacity);
        for (size_t i = 0; i < this->size; ++i) {
            temp[i] = std::move(this->data[i]);
        }

        this->data = std::move(temp);
    }

    template<class U>
    struct ArrayPrinter {
        static void print(const U& ptr) {
            std::cout << ptr;
        }
    };

    template<class U>
    struct ArrayPrinter<std::shared_ptr<U>> {
        static void print(const std::shared_ptr<U>& ptr) {
            std::cout << *ptr;
        }
    };
    void print_array() {
        for (size_t i = 0; i < this->size; ++i) {
            ArrayPrinter<T>::print(this->data[i]);
        }
    }


    template<class U>
    struct ArrayAreaCount {
        static double area(const U& ptr) {
            return static_cast<double>(ptr);
        }
    };

    template<class U>
    struct ArrayAreaCount<std::shared_ptr<U>> {
        static double area(const std::shared_ptr<U>&ptr) {
            return static_cast<double>(*ptr);
        }
    };

    double total_area() {
        double result = 0;
        for (size_t i = 0; i < this->size; ++i) {
            result += ArrayAreaCount<T>::area(this->data[i]);
        }
        return result;
    }

    void pop(int index) {
        if (index < 0 || index >= this->size) {
            return;
        }

        for (size_t i = index; i < this->size - 1; ++i) {
            this->data[i] = std::move(this->data[i + 1]);
        }

        --this->size;
    }

private:
    std::shared_ptr<T[]> data;
    size_t size;
    size_t capacity;
};



#endif //MAI_OOP_LAB_04_ARRAY_H