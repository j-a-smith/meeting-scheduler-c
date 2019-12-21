#include <string>
#include <vector>

std::vector<std::string> split(std::string s, char c) {
    std::vector<std::string> substrs;
    int start = 0;
    for (int end = s.find_first_of(c, start); end != std::string::npos; start = end, end = s.find_first_of(c, start)) {
        substrs.push_back(s.substr(start, end));
    }

    substrs.push_back(s.substr(start));
    return substrs;
}