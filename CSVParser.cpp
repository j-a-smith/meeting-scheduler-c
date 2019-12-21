#include <iostream>
#include <fstream>
#include <string>

#include "CSVParser.h"
#include "util.h"

using namespace std;

CSVParser::CSVParser(string fileName) {
    string line;
    ifstream f;
    f.open(fileName);

    if (getline(f, line)) {
        this->columnHeaders = split(line, ',');
    }

    while (getline(f, line)) {
        vector<string> row = split(line, ',');
        this->csv.push_back(row);
    }
}

vector<void *> CSVParser::forEachRow(csvRowIterator_t f) {
    vector<void *> v;
    for (auto i = this->csv.begin(); i != this->csv.end(); i++) {
        v.push_back((void *) f(*i));
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
    int idx = 0, i = 0;
    for (auto val = this->columnHeaders.begin(); val != this->columnHeaders.end(); val++, i++) {
        if (column.compare(*val)) {
            idx = i;
            break;
        }
    }

    return this->csv.at(row).at(idx);
}