#include <iostream>
#include "test.h"
#include "spreadsheet.h"

int main()
{
	Tester t;
	t.testSetCellAt();
	t.testSetCellAt1();
	t.testGetCellAt();
	t.testAddRow();
	t.testRemoveRow();
	t.testAddColumn();
	t.testRemoveColumn();
	t.testSwapRows();
	t.testSwapColumns();
	Spreadsheet sp(3,3);
	sp.writeCoordinatesToFile();
	IntCell intcell(5, Color::red);
	DoubleCell doublecell(7.8, Color::blue);
	StringCell stringcell("cell", Color::pink);
	Date date(2001, 5, 24);
	DateCell datecell(date, Color::black);
	sp.setCellAt(1, 1, &intcell);
	sp.setCellAt(2, 2, &doublecell);
	sp.setCellAt(0, 1, &stringcell);
	sp.setCellAt(0, 2, &datecell);
	sp.writeCoordinatesToFile();
}
