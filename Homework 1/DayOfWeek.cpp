#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

namespace date
{
	const int DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const int LEAP_YEAR_SHIFT_IN_DAY_OF_MONTH[] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	const int NUMBER_OF_DAYS_IN_WEEK = 7;
	const string DAY_OF_WEEK_NAMES[] =
	{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

	const int START_UNIX_YEAR = 1970;
	const int START_UNIX_DAY_OF_WEEK = 3;

	const int NUMBER_OF_DAYS_IN_YEAR = 365;
	const int NUMBER_OF_DAYS_IN_LEAP_YEAR = 366;

	const int LEAP_YEAR_FREQUENCE = 4;
	const int LEAP_YEAR_REMAINDER = 0;
	bool is_leap_year(int year)
	{
		return year % LEAP_YEAR_FREQUENCE == LEAP_YEAR_REMAINDER;
	}

	int number_of_days_in_year(int year)
	{
		return is_leap_year(year) ? NUMBER_OF_DAYS_IN_LEAP_YEAR :
					NUMBER_OF_DAYS_IN_YEAR;
	}

	int number_of_days_in_month(int year,int month)
	{
		int number_of_days = DAYS_IN_MONTH[month];
		number_of_days += is_leap_year(year) ? 
				LEAP_YEAR_SHIFT_IN_DAY_OF_MONTH[month] : 0;
		return number_of_days;
	}

	int number_of_days_since_start(int year, int month, int day)
	{
		int number_of_days = 0;
		if ( year >= START_UNIX_YEAR )
		{
			for(int current_year = START_UNIX_YEAR; current_year < year; ++current_year)
			{
				number_of_days += number_of_days_in_year(current_year);
			}
		}
		else
		{
			for(int current_year = year; current_year < START_UNIX_YEAR; ++current_year)
			{
				number_of_days -= number_of_days_in_year(current_year);
			}
		}


		for (int current_month = 0; current_month < month; ++current_month)
		{
			number_of_days += number_of_days_in_month(year, current_month);			
		}

		number_of_days += day;

		return number_of_days;
	}

	int remainder_of_division_by_number_of_days_in_week(int number)
	{
		return ( ( number % NUMBER_OF_DAYS_IN_WEEK ) + NUMBER_OF_DAYS_IN_WEEK ) 
			% NUMBER_OF_DAYS_IN_WEEK;
	}

	int day_of_week(int year, int month, int day)
	{
		int number_of_days = number_of_days_since_start(year, month, day);

		return remainder_of_division_by_number_of_days_in_week( number_of_days + START_UNIX_DAY_OF_WEEK - 1 );

	}

	//  Numbering of month starts with 0,
	//  Numbering of days starts with 1
	string day_of_week_name(int year, int month, int day)
	{
		return DAY_OF_WEEK_NAMES[day_of_week(year, month, day)];
	}

}

int main()
{	
	cout << "\t\t" << "DAY OF WEEK TEST" << endl;
	cout << "06.10.2013 : " << date::day_of_week_name(2013, 9, 6) << endl;
	cout << "29.02.2012 : " << date::day_of_week_name(2012, 1, 29) << endl;
	cout << "31.12.2010 : " << date::day_of_week_name(2010, 11, 31) << endl;
	cout << "31.12.1969 : " << date::day_of_week_name(1969, 11, 31) << endl;
	cout << "29.02.1960 : " << date::day_of_week_name(1960, 1, 29) << endl;

	cout << "\t\t" << "LEAP YEAR TEST" << endl;
	cout << "Is 2013 leap year : " << date::is_leap_year(2013) << endl;
	cout << "Is 2012 leap year : " << date::is_leap_year(2012) << endl;
	cout << "Is 2011 leap year : " << date::is_leap_year(2011) << endl;

	
	return 0;
}