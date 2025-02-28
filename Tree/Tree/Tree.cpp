#include <fstream>
#include <iostream>
#include <random>

bool createFileWithRandomNumbers(const std::string& fileName, const int NumbersCount, const int maxNumberValue) {
    std::ofstream file(fileName, std::ios::out);
    if (!file) {
        return false;
    }

    //Генерирует случайные числа
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(0, maxNumberValue);

    for (int i = 0; i < NumbersCount; ++i) {
        file << dis(mt) << std::endl;
    }

    file.close();
    return true;
}

bool isFileContainsSortedArray(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        return false;
    }

    int previous;
    int current;
    bool firstnumber = true;

    while (file >> current) {
        if (firstnumber) {
            previous = current;
            firstnumber = false;
        }
        else {
            if (current < previous)
                return false;
            previous = current;
        }
    }

    file.close();
    return true;
}

int main()
{
    std::string fileName = "file.txt";
    const int numbersCount = 10;
    const int maxNumberValue = 10;
    if (createFileWithRandomNumbers(fileName, numbersCount, maxNumberValue)) {
        std::cout << "Test passed" << std::endl;
    }
    else {
        std::cout << "Test failed: can't create file" << std::endl;
    }
    if (isFileContainsSortedArray(fileName)) {
        std::cout << "File is corted" << std::endl;
    }
    else {
        std::cout << "File isn't sorted" << std::endl;
    }
    return 0;
}
