#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include "sortByFrequency.h"
#include <iomanip>
#include <cctype>

int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cout << "Недостаточно аргументов" << "\n";
        return 1;
    }

    std::string input = argv[1];
    std::string output = argv[2];

    std::ifstream in(input);
    if (!in) {
        std::cerr << "Файл не найден\n";
        return 1;
    }
    std::list<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        lines.push_back(line);
    }
    in.close();


    std::map<std::string, int> words;
    int totalCount = 0;
    for (const std::string& l : lines) {
        std::string word;
        int count = 0;
        for (unsigned char symbol : l) {
            if (std::isalnum(symbol)) {
                word += static_cast<char>(std::tolower(symbol));
            } else if (!word.empty()) {
                    words[word] += 1;
                    totalCount += 1;
                    word.clear();
            }
        }
        if (!word.empty()) {
            words[word] += 1;
            totalCount += 1;
            word.clear();
        }
    }

    std::list<std::pair<std::string, int>> sortedList = sortByFrequency(words);

    std::ofstream out(argv[2]);

    out << "Слово,Частота,Частота(в %)\n";

    for (const auto& w : sortedList) {
        double percent = 100.0 * w.second / totalCount;
        out << w.first << "," << w.second << "," << percent << "\n";
    }

    return 0;
}
