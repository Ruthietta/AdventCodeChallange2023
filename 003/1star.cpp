#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> readTextFile(const std::string &fileName) {
    std::vector<std::string> str;
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return str;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        str.push_back("."+line+".");
    }

    inputFile.close();
    return str;
}

int main() {
    std::string fileName = "text.txt";
    std::vector<std::string> str = readTextFile(fileName);

    bool isDigit = false;
    int number = 0;
    int result = 0;
    std::vector<int> place;

    for (int i = 0; i < str.size(); ++i) {
        for (int j = 0; j < str[i].length(); j++) {
            if (isdigit(str[i][j])) {
                isDigit = true;
                place.push_back(j);
                number = number * 10 + (str[i][j] - '0');
            } else if(isDigit) {
                    isDigit = false;
                    if(str[i][j] != '.') {
                        result += number;
                    } else {
                            for (int k = 0; k == place.size(); k++) {
                                if (str[i + 1][place[k]] != '.') {
                                    result += number;
                                    break;
                                } else if (str[i + 1][place[k] + 1] != '.') {
                                    result += number;
                                    break;
                                } else if (i >= 1) 
                                if (str[i - 1][place[k]] != '.') {
                                    result += number;
                                    break;
                                } else if (str[i - 1][place[k] + 1] != '.') {
                                    result += number;
                                    break;
                                } else if(str[i][place[k]+1] != '.') {
                                    result += number;
                                    break;
                                } else if (k++==place.size()) {
                                    if (str[i - 1][place[k] - 1] != '.') {
                                        result += number;
                                        break;
                                    } else if (str[i + 1][place[k] - 1] != '.') {
                                        result += number;
                                        break;
                                    } else if(str[i][place[k]-1] != '.') {
                                        result += number;
                                        break;
                                    }
                                }
                            }
                        }
                    number = 0;
                    place.clear();
            }
        }
    }

    std::cout << result;
    return 0;
    // answer is 520135
}