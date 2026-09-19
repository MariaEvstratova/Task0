#include "sortByFrequency.h"
#include <fstream>
#include <string>
#include <list>
#include <map>

std::list<std::pair<std::string, int>> sortByFrequency(std::map<std::string, int>& words) {
    std::list<std::pair<std::string, int>> mapToList(words.begin(), words.end());

    mapToList.sort([](const std::pair<std::string, int>& a,
                   const std::pair<std::string, int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    return mapToList;
}