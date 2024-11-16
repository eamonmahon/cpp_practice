#include <iostream>

template <typename T>
class DynamicArray {
    private:
    size_t capacity_;
    size_t length_;
    T* arr;

    public:

    DynamicArray(int capacity) : length_(0) {
        if (capacity <= 0) {
            throw std::invalid_argument("Capacity must be a positive integer");
        }
        capacity_ = static_cast<size_t>(capacity);
        arr = new T[capacity_];
    }

    DynamicArray() : capacity_(1), length_(0), arr(new T[1]) {}


    ~DynamicArray() {
        delete[] arr;
    }

    // TODO: Copy constructor
    // TODO: Copy assignment operator
    // TODO: Move constructor
    // TODO: Move assignment operator

    T get(int i) {

        if (i < 0 || static_cast<size_t>(i) >= length_) {
            throw std::out_of_range("Index out of bounds");
        }

        return arr[i];
    }

    // TODO: change to const T& n
    void set(int i, const T& n) {
        if (i < 0 || static_cast<size_t>(i) >= length_) {
            throw std::out_of_range("Index out of bounds");
        }
        if (length_ == 0) {
            throw std::underflow_error("Cannot set value; array is empty.");
        }

            arr[i] = n;
    }

    // TODO: change to const T& n
    void pushback(const T& n) {

        if (length_ == capacity_) {
            resize(); // what are the different ways to call this (this->resize(); ?)
        }
        arr[length_] = n;
        length_++;
    }

    T popback() {
        if (length_ == 0) {
            throw std::underflow_error("Array is empty");
        }
        T element = arr[length_-1];
        length_--;
        return element;
    }

    void resize() {

        T* new_arr = new T[capacity_*2];

        for (size_t i = 0; i < length_; i++) {
            new_arr[i] = arr[i];
        }
        capacity_ *= 2;
        delete[] arr;
        arr = new_arr;
    }

    int getSize() const {
        return length_;
    }

    int getCapacity() const {
        return capacity_;
    }

    void printArr() const {
        std::cout << "[ ";
        for (size_t i = 0; i < length_; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "]\n";
    }



};