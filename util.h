#include <vector>
#include <string>

std::vector<std::string> split(std::string s, char c, char wrapper);
void *printLine(std::vector<std::string> row, void *args);
void error(std::string msg);