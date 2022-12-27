/*
1. Write a program to implement searching using hashing method?
*/
#include <iostream>
#include <unordered_map>

int main()
{
    // Create a hash table to store key-value pairs
    std::unordered_map<int, std::string> hashTable;

    // Insert some values into the hash table
    hashTable[1] = "one";
    hashTable[2] = "two";
    hashTable[3] = "three";
    hashTable[4] = "four";
    hashTable[5] = "five";

    // Search for a value in the hash table using its key
    int key = 5;
    if (hashTable.count(key) > 0) {
        std::cout << "Value for key " << key << ": " << hashTable[key] << std::endl;
    }
    else {
        std::cout << "Key not found" << std::endl;
    }

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
