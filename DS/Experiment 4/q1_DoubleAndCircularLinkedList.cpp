/*
1. Write a program showing the implementation of Doubly and Circular linked list?
*/
#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;
};

int main()
{
    Node* d1 = new Node();
    Node* d2 = new Node();
    Node* d3 = new Node();
    Node* d4 = new Node();
    Node* c1 = new Node();
    Node* c2 = new Node();
    Node* c3 = new Node();

    d1->prev = NULL; d1->data = 11; d1->next = d2; 
    d2->prev = d1; d2->data = 12; d2->next = d3; 
    d3->prev = d2; d3->data = 13; d3->next = d4; 
    d4->prev = d3; d4->data = 14; d4->next = NULL; 
    
    Node* temp = d1;
    std::cout << "Doubly Linked List :: \t\t";
    while (temp->next != NULL){
        std::cout << temp->data << " " << char(29) << " ";
        temp = temp->next;
    }
    std::cout << temp->data << std::endl;
    
    
    c1->prev = c3; c1->data = 21; c1->next = c2; 
    c2->prev = c2; c2->data = 22; c2->next = c3; 
    c3->prev = c1; c3->data = 23; c3->next = c1;  
    
    Node* temp2 = c1;
    std::cout << "Circular Linked List :: \t" << char(4) << " ";
    while (temp2->next != c1){
        std::cout << temp2->data << " " << char(29) << " ";
        temp2 = temp2->next;
    }
    std::cout << temp2->data << " " <<char(4) << std::endl;

    delete(d1);delete(d2);delete(d3);delete(d4);delete(c1);delete(c2);delete(c3);

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
