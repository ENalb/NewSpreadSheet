class Date
{
public:
	Date(int, int, int);
	Date toDate(const std::string&);
	void setYear(int);
	int getYear() const;
	void setMonth(int);
	int getMonth() const;
	void setDay(int);
	int getDay() const;
private:
	int year;
	int month;
	int day;
};