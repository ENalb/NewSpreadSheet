#include <iostream>
#include <string>
#include <fstream>
#include "spreadsheet.h"

Spreadsheet::Spreadsheet(int r, int c) : row{r}, column{c}
{
	m_cells.resize(row);
	for (int i = 0; i < r; ++i) {
    		m_cells[i].resize(column);
  	}
}

int Spreadsheet::getRow()
{
	return m_cells.size();
}

int Spreadsheet::getColumn()
{
	return m_cells[0].size();
}

void Spreadsheet::printSheet()
{
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < column; ++j){
			Cell* cell = getCellAt(i, j);
			if (cell) {
				std::cout << cell->getStringValue() << " ";
			} 
			else {
				std::cout << "0 ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Spreadsheet::setCellAt(int r, int c, Cell* cell)
{
	m_cells[r][c] = cell;
}

Cell* Spreadsheet::getCellAt(int r, int c) 
{
	return m_cells[r][c];
}

void Spreadsheet::setCellAt(int r, int c, const std::string& value)
{
	StringCell* stringCell = new StringCell(value, Color::blue);
    	m_cells[r][c] = stringCell;
}

void Spreadsheet::addRow(int r, const std::vector<Cell*>& vec)
{
	m_cells.insert(m_cells.begin() + r, vec);
	++row;
}

void Spreadsheet::removeRow(int r)
{
	m_cells.erase(m_cells.begin() + r);
	--row;
}

void Spreadsheet::addColumn(int c, const std::vector<Cell*>& vec)
{
	int rows = vec.size();
	for (int i = 0; i < row; i++) {
		m_cells[i].resize(column + 1);
        	if (i < rows) {
            		m_cells[i][c] = vec[i];
        	} 
		else {
            		m_cells[i][c] = nullptr;
        	}
	}
	++column;
}

void Spreadsheet::removeColumn(int c)
{
	int rows = m_cells.size();
    	int cols = m_cells[0].size();
    	for (int i = 0; i < rows; ++i) {
        	for (int j = c; j < cols - 1; ++j) {
            		m_cells[i][j] = m_cells[i][j+1];
        	}
        	m_cells[i].resize(cols - 1);
    	}
    	--column;
}

void Spreadsheet::swapRows(int r1, int r2)
{
	std::vector<Cell*> temp = m_cells[r1];
    	m_cells[r1] = m_cells[r2];
    	m_cells[r2] = temp;
}

void Spreadsheet::swapColumns(int c1, int c2)
{
	int rows = m_cells.size();
    	for (int i = 0; i < rows; ++i) {
		Cell* temp = m_cells[i][c1];
		m_cells[i][c1] = m_cells[i][c2];
		m_cells[i][c2] = temp;
    	}
}

void Spreadsheet::writeCoordinatesToFile()
{
	std::string filename = "coordinates.txt";

    	std::ofstream file(filename);

    	int rowCount = m_cells.size();
    	int columnCount = m_cells[0].size();

    	for (int i = 0; i < rowCount; i++)
    	{
		for (int j = 0; j < columnCount; j++)
		{
			Cell* cell = getCellAt(i, j);
				if (cell) {
					file << "(" << i << ";" << j << ") = " << cell->getStringValue() << "\n";
				} 
				else {
					file << "(" << i << ";" << j << ") = " << m_cells[i][j] << "\n";
				}
		}
    	}

    	file.close();
}
