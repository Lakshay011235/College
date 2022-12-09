/*
Write a program to find the greatest of two given numbers in two different classes using friend
function.
*/
#include <iostream>
using namespace std;
    class a;    
    class b{
        private:
            int number;
        public:
            b(int x){
                number=x;
            }
        void friend greatest(a a1,  b b1);
    };
    
    class a{
        private:
            int number;
        public:
            a(int x){
                number=x;
            }
        void friend greatest(a a1,  b b1);
    };

    void greatest(a a1,b b1) {
        cout <<  "Greatest number is:" + to_string((a1.number>b1.number)? a1.number : b1.number) << endl;
    }
    
int main() {
    int num;
    cout << "A:";   cin >> num;a a1(num);
    cout << "B:";   cin >> num;b b1(num);
    
    greatest(a1,b1);

    cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}