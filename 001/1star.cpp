#include <fstream>
#include <iostream>
#include <map>
#include <vector>

std::vector<std::string> readTextFile(const std::string &fileName)
{
    std::vector<std::string> str;
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return str;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        str.push_back(line);
    }
    
    inputFile.close();
    return str;
}

int main()
{
    std::string fileName = "text.txt";
    std::vector<std::string> str = readTextFile(fileName);
    std::vector<int> result;

    for (int i = 0; i < str.size(); i++)
    {
        std::vector<int> numbers;

        for (auto n : str[i])
            if (isdigit(n))
                numbers.push_back(n - '0');

        if (!numbers.empty())
        {
            if (numbers.size() == 1)
                result.push_back(numbers[0] * 10 + numbers[0]);
            else
                result.push_back(numbers[0] * 10 + numbers.back());
        }
    }

    int resultFinal = 0;
    for (auto num : result)
        resultFinal += num;

    std::cout << resultFinal << std::endl;
    return 0;
}

// Answer: 55712