/*

*/
#include <iostream>

class CircularLinkedList {
private:
// Definition for a node in the linked list
struct Node {
int data;
Node* next;
};

Node* head;
int size;

public:
CircularLinkedList() {
head = nullptr;
size = 0;
}

// Insert a new node at the front of the list
void push_front(int data) {
Node* newNode = new Node;
newNode->data = data;
newNode->next = head;
if (head != nullptr) {
Node* temp = head;
while (temp->next != head) {
temp = temp->next;
}
temp->next = newNode;
} else {
newNode->next = newNode;
}
head = newNode;
size++;
}

// Insert a new node at the back of the list
void push_back(int data) {
Node* newNode = new Node;
newNode->data = data;
newNode->next = head;
if (head != nullptr) {
Node* temp = head;
while (temp->next != head) {
temp = temp->next;
}
temp->next = newNode;
} else {
head = newNode;
}
size++;
}

// Remove the front node of the list
void pop_front() {
if (head == nullptr) {
return;
}
Node* temp = head;
if (head->next == head) {
head = nullptr;
} else {
Node* temp2 = head;
while (temp2->next != head) {
temp2 = temp2->next;
}
temp2->next = head->next;
head = head->next;
}
delete temp;
size--;
}

// Remove the back node of the list
void pop_back() {
if (head == nullptr) {
return;
}
Node* temp = head;
if (head->next == head) {
head = nullptr;
} else {
Node* temp2 = head;
while (temp2->next != head) {
temp = temp2;
temp2 = temp2->next;
}
temp->next = head;
}
delete temp2;
size--;
}

// Return the data of the front node
int front() {
if (head == nullptr) {
return -1;
}
return head->data;
}

// Return the data of the back node
int back() {
if (head == nullptr) {
return -1;
}
Node* temp = head;
while (temp->next != head) {
temp = temp->next;
}
return temp->data;
}

// Return the number of nodes in the list
int get_size() {
return size;
}

// Check if the list is empty
bool empty() {
return size == 0;
}
};

int main() {
CircularLinkedList list;

list.push_back(1);
list.push_back(2);
list.push_front(3);
list.push_front(4);

std::cout << "Size: " << list.get_size() << std::endl;
std::cout << "Front: " << list.front() << std::endl;
std::cout << "Back: " << list.back() << std::endl;

list.pop_front();
list.pop_back();

std::cout << "Size: " << list.get_size() << std::endl;
std::cout << "Front: " << list.front() << std::endl;
std::cout << "Back: " << list.back() << std::endl;

return 0;
}