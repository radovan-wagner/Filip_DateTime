#include <iostream>
#include <iomanip>
#include <string>
#include "DateTime_Lib.h"

DateTime::DateTime()
{
	this->day = -1;
	this->month = -1;
	this->year = -1;
	this->second = -1;
	this->minute = -1;
	this->hour = -1;
}

DateTime::DateTime(int day, int month, int year, int hour, int minute, int second)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->second = second;
	this->minute = minute;
	this->hour = hour;
}

DateTime::DateTime(std::string dateTime, std::string delimiter1, std::string delimiter2, std::string delimiter3)
{
	size_t			pos = 0;
	std::string		date;
	std::string		time;
	std::string		tmpStr;
	int				tmp[2] = { 0,0 };
	int				i = 0;

	pos = dateTime.find(delimiter2);
	if (pos == -1)
	{
		exit(-1);
	}

	date = dateTime.substr(0, pos);
	dateTime.erase(0, pos + delimiter2.length());
	time = dateTime;

	while (pos = date.find(delimiter1) != std::string::npos)
	{
		tmpStr = date.substr(0, pos + delimiter1.length());
		date.erase(0, pos + 2 * delimiter1.length());
		tmp[i] = std::stoi(tmpStr);
		i++;
	}

	this->day = tmp[0];
	this->month = tmp[1];
	this->year = std::stoi(date);

	i = 0;

	while (pos = time.find(delimiter3) != std::string::npos)
	{
		tmpStr = time.substr(0, pos + delimiter3.length());
		time.erase(0, pos + 2 * delimiter3.length());
		tmp[i] = std::stoi(tmpStr);
		i++;
	}

	this->hour = tmp[0];
	this->minute = tmp[1];
	this->second = std::stoi(time);
}

DateTime& DateTime::operator++()
{
	int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	second++;

	if (second == 60)
	{
		second = 0;
		minute++;

		if (minute == 60)
		{
			minute = 0;
			hour++;

			if (hour == 24)
			{
				hour = 0;
				day++;

				if (day == Month[month - 1] + 1)
				{
					day = 1;
					month++;

					if (month == 13)
					{
						month = 1;
						year++;
					}
				}
			}
		}
	}

	return *this;
}

DateTime& DateTime::operator--()
{
	int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	second--;

	if (second == -1)
	{
		second = 59;
		minute--;

		if (minute == -1)
		{
			minute = 59;
			hour--;

			if (hour == -1)
			{
				hour = 23;
				day--;

				if (day == 0)
				{
					if (month == 1)
					{
						day = 31;
						month = 12;
						year--;
					}
					else
					{
						day = Month[month - 2];
						month--;
					}
				}
			}
		}
	}

	return *this;
}

DateTime DateTime::operator++(int)
{
	int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int s = second, mi = minute, h = hour, d = day, mo = month, y = year;

	second++;

	if (second == 60)
	{
		second = 0;
		minute++;

		if (minute == 60)
		{
			minute = 0;
			hour++;

			if (hour == 24)
			{
				hour = 0;
				day++;

				if (day == Month[month - 1] + 1)
				{
					day = 1;
					month++;

					if (month == 13)
					{
						month = 1;
						year++;
					}
				}
			}
		}
	}

	return DateTime(y, mo, d, h, mi, s);
}

DateTime DateTime::operator--(int)
{
	int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int s = second, mi = minute, h = hour, d = day, mo = month, y = year;

	second--;

	if (second == -1)
	{
		second = 59;
		minute--;

		if (minute == -1)
		{
			minute = 59;
			hour--;

			if (hour == -1)
			{
				hour = 23;
				day--;

				if (day == 0)
				{
					if (month == 1)
					{
						day = 31;
						month = 12;
						year--;
					}
					else
					{
						day = Month[month - 2];
						month--;
					}
				}
			}
		}
	}

	return DateTime(y, mo, d, h, mi, s);
}

DateTime DateTime::operator+(int value)
{
	int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	second += value;

	if (second >= 60)
	{
		minute += second / 60;
		second = second % 60;

		if (minute >= 60)
		{
			hour += minute / 60;
			minute = minute % 60;

			if (hour >= 24)
			{
				day += hour / 24;
				hour = hour % 24;

				if (day > Month[month - 1])
				{
					while (day / Month[month - 1] != 0)
					{
						day -= Month[month - 1];
						month++;

						if (month > 12)
						{
							month = 1;
							year++;
						}
					}
				}
			}
		}
	}

	return DateTime(year, month, day, hour, minute, second);
}

DateTime DateTime::operator-(int value)
{
	int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	second -= value;
	if (second < 0)
	{
		minute += value / 60;
		second = 60 + (second % 60);

		if (minute < 0)
		{
			hour += minute / 60;
			minute = 60 + (minute % 60);

			if (hour < 0)
			{
				day += hour / 24;
				hour = 24 + (hour % 24);

				if (day < 1)
				{
					do
					{
						if (month == 1)
						{
							day += Month[11];
							month = 12;
							year--;
						}
						else
						{
							day += Month[month - 2];
							month--;
						}

					} while (day / Month[month - 1] != 0);
				}

			}
		}
	}

	return DateTime(year, month, day, hour, minute, second);
}

bool DateTime::operator==(const DateTime& dateTime)
{
	if (year == dateTime.year && month == dateTime.month && day == dateTime.day && hour == dateTime.hour && minute == dateTime.minute && second == dateTime.second)
		return true;
	else
		return false;
}

bool DateTime::operator!=(const DateTime& dateTime)
{
	if (year == dateTime.year && month == dateTime.month && day == dateTime.day && hour == dateTime.hour && minute == dateTime.minute && second == dateTime.second)
		return false;
	else
		return true;
}

bool DateTime::operator>(const DateTime& dateTime)
{
	if (year > dateTime.year)
	{
		return true;
	}
	else if (year < dateTime.year)
	{
		return false;
	}
	else
	{
		if (month > dateTime.month)
		{
			return true;
		}
		else if (month < dateTime.month)
		{
			return false;
		}
		else
		{
			if (day > dateTime.day)
			{
				return true;
			}
			else if (day < dateTime.day)
			{
				return false;
			}
			else
			{
				if (hour > dateTime.hour)
				{
					return true;
				}
				else if (hour < dateTime.hour)
				{
					return false;
				}
				else
				{
					if (minute > dateTime.minute)
					{
						return true;
					}
					else if (minute < dateTime.minute)
					{
						return false;
					}
					else
					{
						if (second > dateTime.second)
						{
							return true;
						}
						else if (second < dateTime.second)
						{
							return false;
						}
						else if (second == dateTime.second)
						{
							return false;
						}
					}
				}
			}
		}
	}
}

bool DateTime::operator<(const DateTime& dateTime)
{
	if (year > dateTime.year)
	{
		return false;
	}
	else if (year < dateTime.year)
	{
		return true;
	}
	else
	{
		if (month > dateTime.month)
		{
			return false;
		}
		else if (month < dateTime.month)
		{
			return true;
		}
		else
		{
			if (day > dateTime.day)
			{
				return false;
			}
			else if (day < dateTime.day)
			{
				return true;
			}
			else
			{
				if (hour > dateTime.hour)
				{
					return false;
				}
				else if (hour < dateTime.hour)
				{
					return true;
				}
				else
				{
					if (minute > dateTime.minute)
					{
						return false;
					}
					else if (minute < dateTime.minute)
					{
						return true;
					}
					else
					{
						if (second > dateTime.second)
						{
							return false;
						}
						else if (second < dateTime.second)
						{
							return true;
						}
						else if (second == dateTime.second)
						{
							return false;
						}
					}
				}
			}
		}
	}
}

int DateTime::operator[](int index)
{
	switch (index)
	{

	case 0:
		return second;
		break;
	case 1:
		return minute;
		break;
	case 2:
		return hour;
		break;
	case 3:
		return day;
		break;
	case 4:
		return year;
		break;
	case 5:
		return year;
		break;
	default:
		std::cout << "Error." << std::endl;
		return -1;
	}

}

int DateTime::operator-(const DateTime& dateTime)
{
	int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int s = 0, y = 0, m = 0, d = 0, h = 0, m = 0;
	DateTime tmpDT(dateTime.month, dateTime.day, dateTime.year, dateTime.hour, dateTime.minute, dateTime.second);

	if (*this == tmpDT)
		return 0;

	if (year > tmpDT.year)
	{
		y = year - tmpDT.year;
		m = month - tmpDT.month;

		if (m < 0)
			y--;

		d += (Month[tmpDT.month - 1] - tmpDT.day) + 1;
		tmpDT.day = 1;
		tmpDT.month++;
		if (tmpDT.month == 13)
			tmpDT.month = 1;

		while (month != tmpDT.month)
		{
			d += Month[tmpDT.month - 1];
			tmpDT.month++;
		};

		d += day;
	}
	else if (year < dateTime.year)
	{

	}
	else if (year == dateTime.year)
	{

	}

	d += (y * 365);

	return d;
}

std::ostream& operator<<(std::ostream& output, const DateTime& dateTime)
{
	output << std::setfill('0') << std::setw(2) << dateTime.day << "." << std::setfill('0') << std::setw(2) << dateTime.month << "." << dateTime.year << " " << std::setfill('0') << std::setw(2) << dateTime.hour << ":" << std::setfill('0') << std::setw(2) << dateTime.minute << ":" << std::setfill('0') << std::setw(2) << dateTime.second << std::endl;

	return output;
}

void DateTime::show()
{
	std::cout << std::setfill('0') << std::setw(2) << day << "." << std::setfill('0') << std::setw(2) << month << "." << year << " " << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << minute << ":" << std::setfill('0') << std::setw(2) << second << std::endl;
}
