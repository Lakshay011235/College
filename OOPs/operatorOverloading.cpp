#include <iostream>
#include <string>

using namespace std;

class str{
    public:
        string init;
        str(string text){
            this->init=text;
        }
        str operator + (str& nextstr){
            str final(init+(nextstr.init));
            return final;
        }
        str operator = (str& nextstr){
            str final(nextstr.init);
            return final;
        }
        int len(){
            return init.length();
        }
        bool operator <= (str& nextstr){
            return (this->len() <= nextstr.len()) ? true : false;
        }
        void toLower(){
            for (int i = 0; i < init.length(); i++) {
                init[i] = tolower(init[i]);
            }
        }
        void toUpper(){
            for (int i = 0; i < init.length(); i++) {
                init[i] = toupper(init[i]);
            }
        }
        void show(){
            std::cout << this->init << endl;
        }
};

int main()
{
    str A("Asdf");
    str B("qwerqwer");
    
    
    std::cout << "First string:\t\t\t";       A.show();
    std::cout << "Second string:\t\t\t";      B.show();
    str C = A+B;
    std::cout << "+ operator(add):\t\t";    C.show();
    str D = C;
    std::cout << "= operator(copy):\t\t";   D.show();
    
    std::cout << "<= operator:\t\t\t" << ((A<=B) ? "A <= B" : "B > A") << std::endl;
    
    std::cout << "len():\t\t\t\t" << A.len() << std::endl;
    
    return 0;
}
