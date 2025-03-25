#include "HashTable.h"
#include <iostream>

int main() {
    HashTable ht;

    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    ht.insert(17, 170); // Collision example if capacity is 8

    std::cout << "Initial table:" << std::endl;
    ht.print();

    int* value = ht.get(2);
    if (value)
        std::cout << "Value for key 2: " << *value << std::endl;
    else
        std::cout << "Key 2 not found." << std::endl;

    ht.remove(2);

    std::cout << "After removing key 2:" << std::endl;
    ht.print();

    return 0;
}
