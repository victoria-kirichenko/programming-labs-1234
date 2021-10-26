#ifndef CLASS_TIMESTRING_HPP_INCLUDED
#define CLASS_TIMESTRING_HPP_INCLUDED
#include "../labs123.hpp"

class TimeString : public DateTime {
public:

	TimeString() : time(new char[30]), DateTime() {
		time = "00:00:00";
	}

    TimeString(const char* timE, int day, int month, int year)
        : time(new char[8]), DateTime(day, month, year) {
			time = timE;
			hours = 10 * (time[0] - '0') + (time[1] - '0');
			minutes = 10 * (time[3] - '0') + (time[4] - '0');
			seconds = 10 * (time[6] - '0') + (time[7] - '0');
		}
	const char* GetTime();
	void SetTimeStr(char* valueTime);
	void SetTimeInt(int h, int m, int s);
	void SetTimeIntAfterOperators(int h, int m, int s);

	friend TimeString operator+ (const TimeString time, int value);
	friend TimeString operator- (const TimeString time, int value);
	
	~TimeString() { delete[] time; }

private:
    const char* time = new char[30];
};

#endif // CLASS_TIMESTRING_HPP_INCLUDED