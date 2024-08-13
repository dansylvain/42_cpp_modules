// Array.tpp
#include <stdexcept>
#include <algorithm>

template <typename T>
Array<T>::Array(size_t size) : size(size) {
    data = new T[size];
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size) {
    data = new T[size];
    copyFrom(other);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        free();
        size = other.size;
        data = new T[size];
        copyFrom(other);
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    free();
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
size_t Array<T>::getSize() const {
    return size;
}

template <typename T>
void Array<T>::copyFrom(const Array& other) {
    std::copy(other.data, other.data + size, data);
}

template <typename T>
void Array<T>::free() {
    delete[] data;
}
