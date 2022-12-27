/*
Write a program to perform the deletion of white spaces such as horizontal tab, vertical tab, space ,line feed  ,new  line  and  carriage  return  from  a  text  file  and  store  the  contents  of  the  file without  the  white spaces on another file.
*/
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream input("input.txt");  // open input file
    std::ofstream output("output.txt");  // open output file

    std::string line;
    std::string new_line;
    while (std::getline(input, line)) {  // read line from input file
        for (char c : line) {  // iterate over characters in line
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '\f') {
            // if character is not a white space, add it to new_line
            new_line += c;
        }
        }
    }
    output << new_line << std::endl;  // write new_line to output file
    input.close();  // close input file
    output.close();  // close output file

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
