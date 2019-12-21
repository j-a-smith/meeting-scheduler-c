#include <vector>
#include <string>


typedef bool (*csvRowIterator_t)(std::vector<std::string>);

class CSVParser {
    public:
    CSVParser(std::string filename);
    std::vector<void *> forEachRow(csvRowIterator_t f);
    std::vector<std::string> getRow(int row);
    std::vector<std::string> getColumnHeaders();
    std::string getCell(int row, int column);
    std::string getCell(int row, std::string column);

    private:
    std::vector<std::string> columnHeaders;
    std::vector<std::vector<std::string>> csv;
};