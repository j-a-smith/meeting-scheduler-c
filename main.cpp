#include <string>
#include <iostream>

#include "CSVParser.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2)
        return -1;

    CSVParser csv (argv[1]);

    cout << csv.getCell(0, "First Name") << endl;
    cout << csv.getCell(0, "Age") << endl;

    return 0;
}