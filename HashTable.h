#ifndef HASHTABLE_H
#define HASHTABLE_H

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insert(int key, int value);
    bool remove(int key);
    Node* find(int key);
    void clear();
};

class HashTable {
private:
    DoublyLinkedList** table;
    int capacity;
    int size;

    int hashFunction(int key) const;
    void rehash(int newCapacity);
    float loadFactor() const;

public:
    HashTable(int initCapacity = 8);
    ~HashTable();

    void insert(int key, int value);
    bool remove(int key);
    int* get(int key);
    void print();
};

#endif
