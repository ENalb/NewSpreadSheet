#include <string>
#include <vector>
#include <memory>
#include "cell.h"
// #include "intcell.h"
// #include "doublecell.h"
// #include "stringcell.h"
// #include "datecell.h"

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
private:
	std::vector<std::vector<Cell*>> m_cells;
	int row;
	int column;
};