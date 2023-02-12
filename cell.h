#include "date.h"
#include <string>
#include <sstream>

enum class Color{red = 1, blue, green, pink, purple, black, white, grey};

class Cell
{
public:
	void setColor(Color c) {color = c;}
	Color getColor() const {return color;}
	virtual std::string getStringValue() = 0;
private:
	Color color;
};

class IntCell : public Cell
{
public:
	IntCell(int v, Color c) : value{v} {setColor(c);}
	int getValue() const {return value;}
	void setValue(int v) {value = v;}
	std::string getStringValue() override {return std::to_string(value);}
private:
	int value;
};

class DoubleCell : public Cell
{
public:
	DoubleCell(double v, Color c) : value{v} {setColor(c);}
	double getValue() const {return value;}
	void setValue(double v) {value = v;}
	std::string getStringValue() override {return std::to_string(value);}
private:
	double value;
};

class StringCell : public Cell
{
public:
	StringCell(const std::string& v, Color c) : value{v} {setColor(c);}
	std::string getValue() const {return value;}
	void setValue(const std::string& v) {value = v;}
	std::string getStringValue() override {return value;}
private:
	std::string value;
};

class DateCell : public Cell
{
public:
	DateCell(const Date& d, Color c) : value{d} {setColor(c);}
	Date getValue() const {return value;}
	void setValue(const Date& d) {value = d;}
	std::string getStringValue() override
	{
		return std::to_string(value.getDay()) + "/" + std::to_string(value.getMonth()) + "/" + std::to_string(value.getYear());
	}
private:
	Date value;
};
