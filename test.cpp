#include "test.h"
#include "spreadsheet.h"
#include <iostream>
#include <vector>
#include <string>

void Tester::testSetCellAt()
{
	Spreadsheet sp(3,3);
	IntCell c(5, Color::black);
	sp.setCellAt(2, 1, &c);
	if(sp.getCellAt(2,1)->getStringValue() != c.getStringValue())
	{
		std::cout << "setCellAt Test failed" << std::endl; 
	}
	else
	{
		std::cout << "setCellAt Test passed" << std::endl;
	}
}

void Tester::testSetCellAt1()
{
	Spreadsheet sp(4,4);
	sp.setCellAt(2,3,"H");
	if(sp.getCellAt(2,3)->getStringValue() != "H")
	{
		std::cout << "setCellAt1 Test failed" << std::endl; 
	}
	else
	{
		std::cout << "setCellAt1 Test passed" << std::endl;
	}
}

void Tester::testGetCellAt()
{
	Spreadsheet sp(4,4);
	sp.setCellAt(2,3,"O");
	if(sp.getCellAt(2,3)->getStringValue() != "O")
	{
		std::cout << "getCellAt Test failed" << std::endl; 
	}
	else
	{
		std::cout << "getCellAt Test passed" << std::endl;
	}
}

void Tester::testAddRow()
{
	Spreadsheet sp(2, 2);
	int rows = sp.getRow();
	std::vector<Cell*> row1{new IntCell(1, Color::red), new DoubleCell(2.5, Color::blue)};
	sp.addRow(1, row1);
	int new_rows = sp.getRow();
	if(new_rows == rows + 1)
	{
		std::cout << "addRow Test passed" << std::endl;
	}
	else
	{
		std::cout << "addRow Test failed" << std::endl;
	}
}

void Tester::testRemoveRow()
{
	Spreadsheet sp(2, 2);
	int rows = sp.getRow();
	sp.removeRow(1);
	int new_rows = sp.getRow();
	if(new_rows == rows - 1)
	{
		std::cout << "removeRow Test passed" << std::endl;
	}
	else
	{
		std::cout << "removeRow Test failed" << std::endl;
	}
}

void Tester::testAddColumn()
{
	Spreadsheet sp(3,3);
	int cols = sp.getColumn();
	Date date(2001, 5, 24);
    std::vector<Cell*> column1{new StringCell("x", Color::pink), new DateCell(date, Color::purple)};
	sp.addColumn(2, column1);
    int new_cols = sp.getColumn();
    if (new_cols == cols + 1) {
        std::cout << "addColumn Test passed" << std::endl;
    } else {
        std::cout << "addColumn Test failed" << std::endl;
    }
}

void Tester::testRemoveColumn()
{
	Spreadsheet sp(5, 5);
	int cols = sp.getColumn();
	sp.removeColumn(2);
	int new_cols = sp.getColumn();
	if (new_cols == cols - 1) {
        std::cout << "removeColumn Test passed" << std::endl;
    } else {
        std::cout << "removeColumn Test failed" << std::endl;
    }
}

void Tester::testSwapRows()
{
	Spreadsheet sp(3, 3);
	int row = sp.getRow();
	int column = sp.getColumn();
	Spreadsheet oldSp(row, column);
	sp.swapRows(1, 2);
	bool isSwapped = true;
	for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            if (oldSp.getCellAt(r,c) != sp.getCellAt(r,c)) {
                isSwapped = false;
                break;
            }
        }
    }
    for (int c = 0; c < column; c++) {
        if (oldSp.getCellAt(1,c) != sp.getCellAt(2,c) || oldSp.getCellAt(2,c) != sp.getCellAt(1,c)) {
            isSwapped = false;
            break;
        }
    }
    if (isSwapped) {
        std::cout << "swapRows Test passed" << std::endl;
    } 
    else {
        std::cout << "swapRows Test failed" << std::endl;
    }
}

void Tester::testSwapColumns()
{
	Spreadsheet sp(3, 3);
	int row = sp.getRow();
	int column = sp.getColumn();
	Spreadsheet oldSp(row, column);
	sp.swapColumns(1, 2);
	bool isSwapped = true;
	for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            if (oldSp.getCellAt(r,c) != sp.getCellAt(r,c)) {
                isSwapped = false;
                break;
            }
        }
    }
    for (int c = 0; c < column; c++) {
        if (oldSp.getCellAt(c,1) != sp.getCellAt(c,2) || oldSp.getCellAt(c,2) != sp.getCellAt(c,1)) {
            isSwapped = false;
            break;
        }
    }
    if (isSwapped) {
        std::cout << "swapColumns Test passed" << std::endl;
    } 
    else {
        std::cout << "swapColumns Test failed" << std::endl;
    }
}