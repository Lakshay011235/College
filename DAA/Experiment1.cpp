/***
 * To implement the following algorithm using an array as a data structure and analyze its time complexity.
1) Merge sort
2) Quick sort
3) Bubble sort
4) Selection sort
5) Heap sort
*/

#include <iostream>
#include <chrono>
#include <functional>
#include <vector>
#include <map>
#include <windows.h>

#include <string>

using namespace std;

// std::ostream &operator<<(std::ostream &os, myclass const &m)
// {
//     return os << m.i;
// }
bool isValidColor(const std::map<std::string, int> &colorMap, const char *color)
{
    return colorMap.find(color) != colorMap.end();
}
template <typename T>
void coloredCout(T Message, const char *Color = "White", const char *BgColor = "Black")
{

    map<std::string, int> colorMap = {
        {"Black", 0},
        {"Blue", 1},
        {"Green", 2},
        {"Cyan", 3},
        {"Red", 4},
        {"Purple", 5},
        {"Dark Yellow", 6},
        {"White", 7},
        {"Gray", 8},
        {"Bright Blue", 9},
        {"Bright Green", 10},
        {"Bright Cyan", 11},
        {"Bright Red", 12},
        {"Pink", 13},
        {"Yellow", 14},
        {"Bright White", 15}};

    if (!isValidColor(colorMap, Color) || !isValidColor(colorMap, BgColor))
    {
        std::cerr << "Error: Undefined color detected!" << std::endl;
        return;
    }

    int textColor = colorMap[Color];
    int bgColor = colorMap[BgColor];

    if (bgColor > 8)
    {
        throw std::logic_error("Error: Background color not defined!");
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD defaultAttrs;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    defaultAttrs = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, textColor | (bgColor << 4));

    std::cout << Message;

    // Reset to default colors
    SetConsoleTextAttribute(hConsole, defaultAttrs);
}
vector<int> selectionSort(vector<int> arr)
{
    for (unsigned int i = 0; i < arr.size() - 1; i++)
    {
        unsigned int minIndex = i;
        for (unsigned int j = i; j < arr.size(); j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }

            cout << "i: " << i << "\tj: " << j << "\t";
            for (unsigned int k = 0; k < arr.size(); k++)
            {
                if (k == minIndex)
                {
                    coloredCout(arr[k], "Black", "White");
                }
                else
                {
                    coloredCout(arr[k]);
                }
                cout << " ";
            }
            cout << "\tminIndex: <<" << minIndex << ">>\tminValue: <<" << arr[minIndex] << ">>" << endl;
        }
        cout << endl;
        swap(arr[i], arr[minIndex]);
    }
    return arr;
}
// int main()
// {
//     cout << Color(12, "\N Hey! I'm in color!"); // Sets a color and prints the text
//     cout << Color(10, " Nice C:\n");            // Sets another color and prints the text
//     Color();                                    // Sets the color to default
//     /*Your favorite pausing goes here*/
//     return 0;
// }
int main()
{
    int size = 10;
    vector<int> arr(size);

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (size + 1);
    }

    vector<int> result = selectionSort(arr);

    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }


    // TODO:: Make a class of colored text  







    
    // coloredCout("Hello, colored world!", "Bluee");

    // string asdf = "Hello, colored world";

    // HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // for (int i = 0; i < 16*9; i++)
    // {
    //     SetConsoleTextAttribute(console, i);
    //     cout << "bg: " << i/16 << " col: " << i%16 << " "<<i << asdf << endl;
    // }
    return 0;
}