#include "CSVParser.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2)
        return -1;

    string f (argv[1]);
    CSVParser csv (f);

    string val = csv.getCell(0, 0);
    cout << val << endl;

    return 0;
}