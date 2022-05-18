#include <iostream>
#include <vector>
#include <string>
#include "main.h"

void throwError(std::string err_string) {
    std::cerr << err_string << std::endl;
    exit(EXIT_FAILURE);
}

template<typename T>
void PrintVector(T &v) {
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << ((i == v.size() - 1) ? "" : ",");
    std::cout << "\n\n";
}



int main()
{

    std::pair<int, int> coords = intersection({ -5, 1 }, { -1, 1 }, { 1, 1 }, { 5, 1 });
    if (coords.first == INT_MAX) std::cout << false << std::endl << std::endl;
    else std::cout << "X: " << coords.first << std::endl << "Y: " << coords.second << std::endl << std::endl;

    load();

    for (const auto& value : driver1) {
        std::cout << value.a1 << ", ";
        std::cout << value.a2 << ", ";
        std::cout << value.b1 << ", ";
        std::cout << value.b2 << std::endl << std::endl;
    }


    std::cin.get();

}