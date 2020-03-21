#include <iostream>
#include <fstream>
#include <string>

#include "CSVParser.h"
#include "util.h"

using namespace std;

CSVParser::CSVParser(char* fileName) {
    string line;
    ifstream f (fileName);
    unsigned int numHeaders = 0;

    if (getline(f, line)) {
        this->columnHeaders = split(line, ',', '\"');
        numHeaders = this->columnHeaders.size();
    }

    while (getline(f, line)) {
        if (line.empty())
            continue;
    
        vector<string> row = split(line, ',', '\"');
        
        if (row.size() != numHeaders)
            error("Row size does not match number of headers");

        this->csv.push_back(row);
    }
}

vector<void *> CSVParser::forEachRow(csvRowIterator_t f, void *args) {
    vector<void *> v;
    for (auto i = this->csv.begin(); i != this->csv.end(); i++) {
        v.push_back((void *) f(*i, args));
    }

    return v;
}

vector<string> CSVParser::getColumnHeaders() {
    return this->columnHeaders;
}

vector<string> CSVParser::getRow(int row) {
    return this->csv.at(row);
}

string CSVParser::getCell(int row, int column) {
    return this->csv.at(row).at(column);
}

string CSVParser::getCell(int row, string column) {
    int i = 0;
    for (auto val = this->columnHeaders.begin(); val != this->columnHeaders.end(); val++, i++) {
        if (column.compare(*val) == 0)
            break;
    }

    if (i >= (int) columnHeaders.size())
        return "";
    else
        return this->csv.at(row).at(i);
}

void CSVParser::setRowWidth(int rowWidth) {
    this->rowWidth = rowWidth;
}

void CSVParser::print() {
    printLine(this->columnHeaders, (void *) this->rowWidth);
    this->forEachRow(printLine, (void *) this->rowWidth);
}