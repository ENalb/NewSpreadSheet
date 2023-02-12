#include <iostream>
#include <vector>
#include "test.h"

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
}