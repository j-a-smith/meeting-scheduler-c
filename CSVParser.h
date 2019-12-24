#include <vector>
#include <string>


typedef void* (*csvRowIterator_t)(std::vector<std::string>, void *);

class CSVParser {
    public:
    CSVParser(char* filename);
    std::vector<void *> forEachRow(csvRowIterator_t f, void *args);
    std::vector<std::string> getRow(int row);
    std::vector<std::string> getColumnHeaders();
    std::string getCell(int row, int column);
    std::string getCell(int row, std::string column);
    void print();
    void setRowWidth(int rowWidth);

    private:
    std::vector<std::string> columnHeaders;
    std::vector< std::vector<std::string> > csv;
    uint64_t rowWidth = 20;
};