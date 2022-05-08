#ifndef VECTOR_H
#define VECTOR_H

#include <cstring>

template <typename T>
class Vector {
private:
    T* arr;
    size_t capacity;
    size_t currentSize;

    static const short DEFAULT_STARTING_CAPACITY = 1;

    void copy(const T* arr, const size_t capacity, const size_t currentSize);
    void deleteMem();
    void resize();

public:
    Vector();
    Vector(const Vector& other);
    Vector<T>& operator=(const Vector<T>& other);
    ~Vector();

    void push(const T& element);
    void pop();

    size_t getSize() const;

    const T& operator[](size_t index) const;
    T& operator[](size_t index);
};

template <typename T>
void Vector<T>::copy(const T* arr, size_t capacity, size_t currentSize)
{
    this->capacity = capacity;
    this->currentSize = currentSize;

    this->arr = new T[capacity];
    for (size_t i = 0; i < currentSize; ++i) {
        this->arr[i] = arr[i];
    }
}

template <typename T>
void Vector<T>::deleteMem()
{
    delete[] arr;
    arr = nullptr;
    currentSize = 0;
}

template <typename T>
void Vector<T>::resize()
{
    capacity *= 2;
    T* tmp = new T[capacity];
    for (size_t i = 0; i < currentSize; ++i) {
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
    tmp = nullptr;
}

template <typename T>
Vector<T>::Vector()
{
    capacity = DEFAULT_STARTING_CAPACITY;
    currentSize = 0;
    arr = new T[DEFAULT_STARTING_CAPACITY];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    copy(other.arr, other.capacity, other.currentSize);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other) {
        deleteMem();
        copy(other.arr, other.capacity, other.currentSize);
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    deleteMem();
}

template <typename T>
void Vector<T>::push(const T& element)
{
    if (currentSize == capacity)
        resize();
    arr[currentSize++] = element;
}

template <typename T>
void Vector<T>::pop()
{
    currentSize--;
}

template <typename T>
size_t Vector<T>::getSize() const
{
    return currentSize;
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
    if (index > currentSize)
        throw "Index out of bounds!";
    return arr[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    if (index > currentSize)
        throw "Index out of bounds!";
    return arr[index];
}

#endif
