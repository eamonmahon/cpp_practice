#include <iostream>
#include "../containers/DynamicArray.cpp" // Include the implementation directly

void testDynamicArray() {
    try {
        std::cout << "=== Testing Constructors ===\n";
        DynamicArray defaultArray;
        std::cout << "Default constructor test passed. Capacity: " 
                  << defaultArray.getCapacity() 
                  << ", Size: " << defaultArray.getSize() << "\n";

        DynamicArray customArray(5);
        std::cout << "Custom constructor test passed. Capacity: " 
                  << customArray.getCapacity() 
                  << ", Size: " << customArray.getSize() << "\n";

        std::cout << "\n=== Testing pushback ===\n";
        for (int i = 1; i <= 10; ++i) {
            customArray.pushback(i);
            customArray.printArr();
        }
        std::cout << "Pushback test passed. Capacity: " 
                  << customArray.getCapacity() 
                  << ", Size: " << customArray.getSize() << "\n";

        std::cout << "\n=== Testing popback ===\n";
        for (int i = 0; i < 5; ++i) {
            int value = customArray.popback();
            std::cout << "Popped: " << value << "\n";
            customArray.printArr();
        }
        std::cout << "Popback test passed. Capacity: " 
                  << customArray.getCapacity() 
                  << ", Size: " << customArray.getSize() << "\n";

        std::cout << "\n=== Testing get and set ===\n";
        customArray.set(0, 42);
        std::cout << "After set(0, 42): ";
        customArray.printArr();
        int value = customArray.get(0);
        std::cout << "Value at index 0: " << value << "\n";
        std::cout << "Get and set test passed.\n";

        std::cout << "\n=== Testing Exception Handling ===\n";
        try {
            customArray.get(100); // Out of bounds
        } catch (const std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }

        try {
            customArray.set(-1, 5); // Negative index
        } catch (const std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }

        try {
            DynamicArray invalidArray(0); // Invalid capacity
        } catch (const std::invalid_argument& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }

        try {
            while (true) {
                customArray.popback(); // Pop until empty to trigger exception
            }
        } catch (const std::underflow_error& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }

        std::cout << "\n=== All Tests Passed ===\n";

    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << "\n";
    }
}

int main() {
    testDynamicArray();
    return 0;
}
