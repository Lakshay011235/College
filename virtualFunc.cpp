#include <iostream>

using namespace std;

class LIST{
    public:
        virtual void store() = 0;
        virtual void retrieve() = 0;
};
class Stack:public LIST{
    public:
        void store(){
            std::cout << "List in Stack Storage" << std::endl;
        }
        void retrieve(){
            std::cout << "List of elements in Stack" << std::endl;
        }
};
class Queue:public LIST{
    public:
        void store(){
            std::cout << "List in Queue Storage" << std::endl;
        }
        void retrieve(){
            std::cout << "List of elements in Queue" << std::endl;
        }
};
int main()
{
    
    Stack obj1;
    obj1.store();
    obj1.retrieve();
    
    Queue obj2;
    obj2.store();
    obj2.retrieve();
    return 0;
}

