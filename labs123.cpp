#include  "labs123.hpp"

DateTime::DateTime() { // конструктор по умолчанию
    day = 1, month = 1, year = 1000, hours = 0, minutes = 0, seconds = 0;
}

DateTime::DateTime(int day_1, int month_1, int year_1, int hours_1, int minutes_1, int seconds_1) { // конструктор с параметрами
	day = day_1;
	month = month_1;
	year = year_1;
	hours = hours_1;
	minutes = minutes_1;
	seconds = seconds_1;
}

DateTime::DateTime(int day_1, int month_1, int year_1) {
	day = day_1;
	month = month_1;
	year = year_1;
}

DateTime::~DateTime() { // деструктор
	delete[] date_time;
}

bool DateTime::CheckingDate() { // валидность даты (1 - false, 0 - true)
	if (day <= 0 || month <= 0 || year <= 0) return 1;
	else if (month > 12) return 1;
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day <= 30)) return 0;
	else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31) return 0;
	else if (month == 2) {
		if ((year % 400 == 0 || year % 100 != 0) && (year % 4 == 0) && (day <= 29)) return 0;
		else if ((year % 4 != 0) && (day <= 28)) return 0;
		else return 1;
	}
	else return 1;
}

int DateTime::GetDay() {
	return day;
}

void DateTime::SetDay(int valueDay) {
	day = valueDay;
}

int DateTime::GetMonth() {
	return month;
}

void DateTime::SetMonth(int valueMonth) {
	month = valueMonth;
}

int DateTime::GetYear() {
	return year;
}

void DateTime::SetYear(int valueYear) {
	year = valueYear;
}

int DateTime::GetHours() {
	return hours;
}

void DateTime::SetHours(int valueHours) {
	hours = valueHours;
}

int DateTime::GetMinutes() {
	return minutes;
}

void DateTime::SetMinutes(int valueMinutes) {
	minutes = valueMinutes;
}

int DateTime::GetSeconds() {
	return seconds;
}

void DateTime::SetSeconds(int valueSeconds) {
	seconds = valueSeconds;
}

char* DateTime::GetDateTime() {
	CreateString();
	char *tmp = new char[20];
	strcpy(tmp, date_time);
	return tmp;
}

char* DateTime::ToString() {
	return GetDateTime();
}

void DateTime::PlusHours() {
	if (hours + 1 == 24) {
		day++;
		hours = 0;
	} else {
		hours++;
	}
	int res = CheckingDate();
	if(res == 1) {
		day = 1;
		month++;
	}
}

void DateTime::MinusHours() {
	if (hours - 1 == -1) {
		day--;
		hours = 23;
	} else {
		hours--;
	}
	int res = CheckingDate();
	if (res == 1) {
		day = 31;
		month--;
	}
	res = CheckingDate();
	if (res == 1) {
		month = 12;
		year--;
	}
}

void DateTime::PlusMinutes() {
	if (minutes + 1 == 60) {
		hours++;
		minutes = 0;
	} else {
		minutes++;
	}
}

void DateTime::MinusMinutes() {
	if (minutes - 1 == -1) {
		hours--;
		minutes = 59;
	} else {
		minutes--;
	}
}

void DateTime::PlusSeconds() {
	if (seconds + 1 == 60) {
		minutes++;
		seconds = 0;
	} else {
		seconds++;
	}
}

void DateTime::MinusSeconds() {
	if (seconds - 1 == -1) {
		minutes--;
		seconds = 59;
	} else {
		seconds--;
	}
}

void DateTime::PlusDay() {
	day++;
	int res = CheckingDate();
	if (res == 1) {
		month++;
		day = 1;
	}
	res = CheckingDate();
	if (res == 1) {
		year++;
		month = 1;
	}
}

void DateTime::MinusDay() {
	if (day - 1 == 0) {
		month--;
		day = 31;
	} else {
		day--;
	}
	int res = CheckingDate();
	while (res != 0) {
		day--;
		res = CheckingDate();
	}
}

void DateTime::PlusMonth() {
	if (month + 1 == 13) {
		year++;
		month = 1;
	} else {
		month++;
	}
	int res = CheckingDate();
	while (res != 0) {
		day--;
		res = CheckingDate();
	}
}

void DateTime::MinusMonth() {
	if (month - 1 == 0) {
		year--;
		month = 12;
	} else {
		month--;
	}
	int res = CheckingDate();
	while (res != 0) {
		day--;
		res = CheckingDate();
	}
}

void DateTime::PlusYear() {
	year++;
	int res = CheckingDate();
	while (res != 0) {
		day--;
		res = CheckingDate();
	}
}

void DateTime::MinusYear() {
	year--;
	int res = CheckingDate();
	while (res != 0) {
		day--;
		res = CheckingDate();
	}
}

void DateTime::CreateString() {
	sprintf(date_time, "%02d.%02d.%04d %02d:%02d:%02d", day, month, year, hours, minutes, seconds);
}

int DateTime::SizeOfDate() {
    int size = strlen(this->GetStr());
    return size;
}

char* DateTime::GetStr() {
	CreateString();
	char *tmp = new char[20];
	strcpy(tmp, date_time);
	return tmp;
}