/*
1. Write a program showing the implementation of Linked list
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    n1->data = 11;  n1->next = n2;
    n2->data = 13;  n2->next = n3;
    n3->data = 15;  n3->next = NULL;
/*
| 11 , &n2 | -> | 13 , &n3 | -> | 15 , NULL |
*/
    std::cout << "Linked List :: ";
    std::cout << n1->data << " -> " << n2->data << " -> " << n3->data << std::endl;

    delete(n1); delete(n2); delete(n3);
    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
