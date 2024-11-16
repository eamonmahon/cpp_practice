#include <iostream>
#include <vector>
#include <cassert>
#include "../containers/LinkedList.cpp" // Include the LinkedList implementation file directly

// Function to print a vector (for debugging)
void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

void testLinkedList() {
    LinkedList<int> list;

    // Test inserting at the head
    list.insertHead(10);
    list.insertHead(20);
    list.insertHead(30);

    std::vector<int> expected = {30, 20, 10};
    assert(list.getValues() == expected);
    std::cout << "Test insertHead passed.\n";

    // Test inserting at the tail
    list.insertTail(40);
    list.insertTail(50);
    expected = {30, 20, 10, 40, 50};
    assert(list.getValues() == expected);
    std::cout << "Test insertTail passed.\n";

    // Test getting elements by index
    assert(list.get(0) == 30);
    assert(list.get(2) == 10);
    assert(list.get(4) == 50);
    assert(list.get(5) == -1); // Index out of bounds
    std::cout << "Test get passed.\n";

    // Test removing elements
    assert(list.remove(0)); // Remove first element
    expected = {20, 10, 40, 50};
    assert(list.getValues() == expected);

    assert(list.remove(2)); // Remove middle element
    expected = {20, 10, 50};
    assert(list.getValues() == expected);

    assert(!list.remove(5)); // Try to remove out of bounds
    std::cout << "Test remove passed.\n";

    // Final list check
    expected = {20, 10, 50};
    assert(list.getValues() == expected);

    std::cout << "All tests passed!\n";
}

int main() {
    testLinkedList();
    return 0;
}
