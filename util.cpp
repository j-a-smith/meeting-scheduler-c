#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> split(std::string s, char c, char wrapper) {
    /*
     * split - splits string into substrings by character
     * 
     * s - string to split
     * c - character used to delineate string
     * wrapper - optional character that will be stripped if surrounding a substring
     * 
     * return - vector of substrings
     */

    std::vector<std::string> substrs;
    unsigned int start = 0;
    for (unsigned int end = s.find_first_of(c, start); end < s.length(); start = end + 1, end = s.find_first_of(c, start)) {
        if (wrapper) {
            unsigned int wrapped_start = s.find_first_of(wrapper, start);
            unsigned int wrapped_end = s.length();

            if (wrapped_start < end)    // If one wrapper char found, check for closing char
                wrapped_end = s.find_first_of(wrapper, wrapped_start + 1);
            
            if (wrapped_end < s.length()) // Treat single wrapper chars as part of cell values
                end = s.find_first_of(c, wrapped_end);    // Treat substring within wrapper char pair as one value

            if (end >= s.length())
                break;
        }

        if (start < s.length())
            substrs.push_back(s.substr(start, end - start));
    }

    if (start > s.length())
        substrs.push_back("");
    else
        substrs.push_back(s.substr(start));

    return substrs;
}

void *printLine(std::vector<std::string> row, void *args) {
    uint64_t rowWidth = (uint64_t) args;
    std::string rowString = "";
    for (auto i = row.begin(); i != row.end(); i++) {
        if (i != row.begin())
            rowString += " | ";

        int numSpaces = 0;
        if ((*i).length() < rowWidth) {
            numSpaces = rowWidth - (*i).length();
        }

        rowString += *i + std::string(numSpaces, ' ');
    }
    std::cout << rowString << std::endl;

    return NULL;
}

void error(std::string msg) {
    std::cout << msg << std::endl;
    exit(EXIT_FAILURE);
}