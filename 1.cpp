
//Пинчукова Гертруда ИВТ-22
#include "modul136a.h"
#include <iostream> 
#include <math.h> 
#include <ctime>
#include <cassert> 
#include <cstdlib>
#include <fstream> 
#include <execution> 
#include <vector>

template<typename T>
T SummEL(const std::vector<T>& array, unsigned size) {
    T sum = 0;
    for (unsigned i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

template<typename T>
void FillArray(std::vector<T>& array, unsigned size, T max_value, T min_value) {
    for (unsigned i = 0; i < size; i++) {
        array[i] = rand() % (max_value - min_value + 1) + min_value;
    }
}

template<typename T>
void printArray(const std::vector<T>& array, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    srand(time(nullptr));

    unsigned size = 3;
    std::vector<float> array_test = {1, 2, 3};
    std::cout << SummEL(array_test, size) << std::endl;

    std::vector<int> array_test_2 = {2, 3, 4};
    std::cout << SummEL(array_test_2, size) << std::endl;

    std::vector<double> array_test_3 = {0, 2, 3};
    std::cout << SummEL(array_test_3, size) << std::endl;

    unsigned arraySize;
    char check;
    int max_nam, min_nam;
    std::string NameF;

    std::cout << "Create a new array? y/n " << std::endl;
    std::cin >> check;

    if ((check == 'Y') or (check == 'y')) {
        std::cout << "Array size: ";
        std::cin >> arraySize;

        std::vector<float> array;
        array.resize(arraySize);

        std::cout << "write max value of numbers " << std::endl;
        std::cin >> max_nam;

        std::cout << "write min value of numbers " << std::endl;
        std::cin >> min_nam;

        FillArray(array, arraySize, max_nam, min_nam);
        printArray(array, arraySize);

        float p = SummEL(array, arraySize);
        std::cout << "sum of array: " << p << std::endl;

        std::cout << "Save array? y/n" << std::endl;
        std::cin >> check;
        if ((check == 'Y') or (check == 'y')) {
            std::cout << "Name of file?" << std::endl;
            std::cin >> NameF;
            printArrayToFile(array, arraySize, NameF);
        }

        array.clear();
    } else {
        std::cout << "Name of file?" << std::endl;
        std::cin >> NameF;

        std::cout << "array was loaded from file" << std::endl;

        try {
            unsigned size_testik = ArraySFromFile(NameF);
        } catch (const std::exception& error) {
            std::cout << error.what();
        }

        size = ArraySFromFile(NameF);
        std::vector<float> array;
        array.resize(size);

        ArrayFromFile(array, arraySize, NameF);
        printArray(array, size);

        float p = SummEL(array, arraySize);
        std::cout << "sum of array: " << p << std::endl;

        array.clear();
    }

    return 0;
}
