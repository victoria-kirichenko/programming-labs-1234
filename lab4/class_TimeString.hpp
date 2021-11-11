#ifndef CLASS_TIMESTRING_HPP_INCLUDED
#define CLASS_TIMESTRING_HPP_INCLUDED
#include "../labs123.hpp"

class TimeString : public DateTime {
public:

	TimeString() : time("00:00:00"), DateTime() {
	}

    TimeString(const char* timE, int day, int month, int year)
        : time(timE), DateTime(day, month, year) {
			hours = 10 * (time[0] - '0') + (time[1] - '0');
			minutes = 10 * (time[3] - '0') + (time[4] - '0');
			seconds = 10 * (time[6] - '0') + (time[7] - '0');
		}

    TimeString(const char* timE, int day, int month, int year, int hours, int minutes, int seconds)
        : time(timE), DateTime(day, month, year, hours, minutes, seconds) {
		}
	const char* GetTime();
	void SetTimeStr(char* valueTime);
	void SetTimeInt(int h, int m, int s);
	void SetTimeIntAfterOperators(int h, int m, int s);

	friend TimeString operator+ (const TimeString time, int value);
	friend TimeString operator- (const TimeString time, int value);

	virtual int SizeOfDate();
	virtual char* GetStr();
	
	~TimeString() { delete[] time; }

private:
    const char* time = new char[30];
};

#endif // CLASS_TIMESTRING_HPP_INCLUDED