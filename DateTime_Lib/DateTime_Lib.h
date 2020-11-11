#pragma once

class DateTime
{

private:

	int year, month, day;
	int hour, minute, second;

public:

	DateTime();
	DateTime(int day, int month, int year, int hour, int minute, int second);
	DateTime(std::string dateTime, std::string delimiter1, std::string delimiter2, std::string delimiter3);

	int		getDay() { return day; }
	int		getMonth() { return month; }
	int		getYear() { return year; }
	int		getSecond() { return second; }
	int		getMinute() { return minute; }
	int		getHour() { return hour; }

	DateTime& operator ++();
	DateTime& operator --();
	DateTime				operator ++(int);
	DateTime				operator --(int);
	DateTime				operator +(int value);
	DateTime				operator -(int value);

	bool					operator ==(const DateTime& DT);
	bool					operator !=(const DateTime& DT);
	bool					operator >(const DateTime& DT);
	bool					operator <(const DateTime& DT);

	friend std::ostream& operator <<(std::ostream& output, const DateTime& DT);

	int						operator [](int index);
	int						operator -(const DateTime& DT);

	void	show();

};
