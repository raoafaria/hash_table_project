#include "HashTable.h"
#include <iostream>
#include <cmath>

// ------------------- DoublyLinkedList -----------------------

DoublyLinkedList::DoublyLinkedList() : head(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::insert(int key, int value) {
    Node* existing = find(key);
    if (existing) {
        existing->value = value;
        return;
    }
    Node* newNode = new Node(key, value);
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
}

bool DoublyLinkedList::remove(int key) {
    Node* curr = head;
    while (curr) {
        if (curr->key == key) {
            if (curr->prev) curr->prev->next = curr->next;
            if (curr->next) curr->next->prev = curr->prev;
            if (curr == head) head = curr->next;
            delete curr;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

Node* DoublyLinkedList::find(int key) {
    Node* curr = head;
    while (curr) {
        if (curr->key == key) return curr;
        curr = curr->next;
    }
    return nullptr;
}

void DoublyLinkedList::clear() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}

// --------------------- HashTable ----------------------------

HashTable::HashTable(int initCapacity) : capacity(initCapacity), size(0) {
    table = new DoublyLinkedList*[capacity];
    for (int i = 0; i < capacity; ++i)
        table[i] = new DoublyLinkedList();
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        delete table[i];
    }
    delete[] table;
}

int HashTable::hashFunction(int key) const {
    const float A = 0.6180339887f; // Knuth's constant
    float frac = fmod(key * A, 1.0f);
    return (int)(capacity * frac);
}

float HashTable::loadFactor() const {
    return (float)size / capacity;
}

void HashTable::rehash(int newCapacity) {
    DoublyLinkedList** oldTable = table;
    int oldCapacity = capacity;

    table = new DoublyLinkedList*[newCapacity];
    capacity = newCapacity;
    size = 0;

    for (int i = 0; i < capacity; ++i) {
        table[i] = new DoublyLinkedList();
    }

    for (int i = 0; i < oldCapacity; ++i) {
        Node* curr = oldTable[i]->head;
        while (curr) {
            insert(curr->key, curr->value);
            curr = curr->next;
        }
        delete oldTable[i];
    }
    delete[] oldTable;
}

void HashTable::insert(int key, int value) {
    int index = hashFunction(key);
    table[index]->insert(key, value);
    ++size;
    if (loadFactor() > 1.0f) {
        rehash(capacity * 2);
    }
}

bool HashTable::remove(int key) {
    int index = hashFunction(key);
    if (table[index]->remove(key)) {
        --size;
        if (capacity > 8 && loadFactor() < 0.25f) {
            rehash(capacity / 2);
        }
        return true;
    }
    return false;
}

int* HashTable::get(int key) {
    int index = hashFunction(key);
    Node* found = table[index]->find(key);
    if (found) return &found->value;
    return nullptr;
}

void HashTable::print() {
    for (int i = 0; i < capacity; ++i) {
        std::cout << i << ": ";
        Node* curr = table[i]->head;
        while (curr) {
            std::cout << "(" << curr->key << "," << curr->value << ") -> ";
            curr = curr->next;
        }
        std::cout << "nullptr\n";
    }
}
