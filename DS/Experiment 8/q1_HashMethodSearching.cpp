/*
1. Write a program to implement searching using hashing method?
*/
#include <iostream>
#include <vector>

using namespace std;

const int TABLE_SIZE = 128; // The size of the hash table

// A hash table element, which consists of a key and a value
struct Element {
    int key;
    int value;
};

// A hash table, which consists of an array of elements and a count of elements
struct HashTable {
    vector<Element> elements;
    int count;
};

// A hash function that returns a hash value for a given key
int hash_function(int key) {
    return key % TABLE_SIZE;
}

// A function to create a new hash table
HashTable* create_hash_table() {
    HashTable* table = new HashTable;
    table->count = 0;
    table->elements.resize(TABLE_SIZE);
    return table;
}

// A function to insert a new element into a hash table
void insert(HashTable* table, int key, int value) {
    Element e;
    e.key = key;
    e.value = value;

    // Find the index at which to insert the element
    int index = hash_function(key);
    while (table->elements[index].key != 0) {
        index = (index + 1) % TABLE_SIZE;
    }

    // Insert the element
    table->elements[index] = e;
    table->count++;
}

// A function to search for an element with a given key in a hash table
int search(HashTable* table, int key) {
    // Find the index at which the element with the given key should be located
    int index = hash_function(key);
    while (table->elements[index].key != key) {
        index = (index + 1) % TABLE_SIZE;
        if (table->elements[index].key == 0) {
            // The element was not found
            return -1;
        }
    }

    // The element was found
    return table->elements[index].value;
}

int main() {
    HashTable* table = create_hash_table();

    insert(table, 1, 10);
    insert(table, 2, 20);
    insert(table, 3, 30);
    insert(table, 4, 40);
    insert(table, 5, 50);

    cout << "Searching at (3) : " << search(table, 3) << endl; // 30
    cout << "Searching at (6) : "<< search(table, 6) << endl; // -1 (not found)

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
