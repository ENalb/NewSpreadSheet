#include <string>
#include <vector>
#include "cell.h"

class Spreadsheet{
public:
	Spreadsheet() = default;
	Spreadsheet(int, int);
	int getRow();
	int getColumn();
	void printSheet();
	void setCellAt(int, int, Cell*);
	Cell* getCellAt(int, int);
	void setCellAt(int, int, const std::string&);
	void addRow(int, const std::vector<Cell*>&);
	void removeRow(int);
	void addColumn(int, const std::vector<Cell*>&);
	void removeColumn(int);
	void swapRows(int, int);
	void swapColumns(int, int);
	void writeCoordinatesToFile();
private:
	std::vector<std::vector<Cell*>> m_cells;
	int row;
	int column;
};
