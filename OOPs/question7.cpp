/*
Write a program to overload new and delete operator.
*/
#include<iostream>
#include<stdlib.h>  //for malloc and free
class num{
        int num_;
    public:
        num(int value) : num_(value) {}
        void display(){
            std::cout<< "Number : " << num_ << std::endl;
        }
        void * operator new(size_t size){
            std::cout<< "Overloading new operator with size: " << size << std::endl;
            void * p = malloc(size);
            return p;
        }
        void operator delete(void * p){
            std::cout<< "Overloading delete operator called" << std::endl;
            free(p);
        }
};
int main(){
	num * p = new num(14);
	p->display();
	delete p;
    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
}
