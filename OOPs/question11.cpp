/*
Create a class which keep track of number of its instances. Use static data member, constructors and 
destructors to maintain updated information about active objects.
*/
#include <iostream>

class car{
    static int cars_sold;   //Static member declared
    public:
        car(){              // Constructor
            cars_sold++; status();
        }
        ~car(){             // Destructor
            cars_sold--; status();
        }
        static void status(){
            std::cout << "Cars Active:\t" << cars_sold << std::endl;
        }
};
int car::cars_sold = 0;     //Static member initialized
int main()
{
    std::cout << ">>> Car 1,2,3 created" << std::endl;
    car *c1 = new car();
    car *c2 = new car();
    car *c3 = new car();
    std::cout << ">>> Car 3 deleted" << std::endl;
    delete c3;
    std::cout << ">>> Car 4 created" << std::endl;
    car *c4 = new car();
    std::cout << ">>> End of Program" << std::endl;
    delete c4;
    delete c2;
    delete c1;
    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
