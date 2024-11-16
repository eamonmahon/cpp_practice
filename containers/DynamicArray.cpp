#include <iostream>

class DynamicArray {
    private:
    size_t capacity_;
    size_t length_;
    int* arr;

    public:

    DynamicArray(int capacity) : length_(0) {
        if (capacity <= 0) {
            throw std::invalid_argument("Capacity must be a positive integer");
        }
        capacity_ = static_cast<size_t>(capacity);
        arr = new int[capacity_];
    }

    DynamicArray() : capacity_(1), length_(0), arr(new int[1]) {}


    ~DynamicArray() {
        delete[] arr;
    }

    // TODO: Copy constructor
    // TODO: Copy assignment operator
    // TODO: Move constructor
    // TODO: Move assignment operator

    int get(int i) {

        if (i < 0 || static_cast<size_t>(i) >= length_) {
            throw std::out_of_range("Index out of bounds");
        }

        return arr[i];
    }

    void set(int i, int n) {
        if (i < 0 || static_cast<size_t>(i) >= length_) {
        throw std::out_of_range("Index out of bounds");
    }
    if (length_ == 0) {
        throw std::underflow_error("Cannot set value; array is empty.");
    }

        arr[i] = n;
    }

    void pushback(int n) {

        if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Value is out of range for int");
        }
        if (length_ == capacity_) {
            resize(); // what are the different ways to call this (this->resize(); ?)
        }
        arr[length_] = n;
        length_++;
    }

    int popback() {
        if (length_ == 0) {
            throw std::underflow_error("Array is empty");
        }
        int element = arr[length_-1];
        length_--;
        return element;
    }

    void resize() {

        int* new_arr = new int[capacity_*2];

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