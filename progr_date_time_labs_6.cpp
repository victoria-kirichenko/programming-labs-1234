#include  "progr_date_time_labs_6.hpp"

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

DateTime DateTime::operator= (const DateTime date) { // перегрузка оператора присваивания
	day = date.day;
	month = date.month;
	year = date.year;
	hours = date.hours;
	minutes = date.minutes;
	seconds = date.seconds;
	return *this;
}

DateTime DateTime::operator+ (const DateTime &date) { // перегрузка оператора сложения двух дат
	DateTime temp;
	temp.day = day + date.day;
	temp.month = month + date.month;
	temp.year = year + date.year;
	temp.hours = hours + date.hours;
	temp.minutes = minutes + date.minutes;
	temp.seconds = seconds +date.seconds;
	if (temp.seconds > 59) {
		temp.seconds = temp.seconds - 60;
		temp.minutes++;
		if (temp.minutes > 59) {
			temp.minutes = temp.minutes - 60;
			temp.hours++;
		}
		if (temp.hours > 23) {
			temp.hours = temp.hours - 24;
			temp.day++;
		}
		if (temp.day > 31) {
			temp.day = temp.day - 31;
			temp.month++;
		}
		if (temp.month > 12) {
			temp.month = temp.month - 12;
			temp.year++;
		}
	} else if (temp.minutes > 59) {
		temp.hours++;
		temp.minutes = temp.minutes - 60;
		if (temp.hours > 23) {
			temp.hours = temp.hours - 24;
			temp.day++;
		}
		if (temp.CheckingDate() == 1) {
			temp.day = temp.day - 31;
			temp.month++;
			while (temp.day < 1) {
				temp.day++;
			}
		}
		if (temp.CheckingDate() == 1) {
			temp.month = temp.month - 12;
			temp.year++;
		}
	} else if (temp.hours > 23) {
		temp.day++;
		temp.hours = temp.hours - 23;
		while (temp.CheckingDate() == 1) {
			if (temp.day > 31) {
				temp.month++;
				temp.day = temp.day - 31;
			}
		}
	} else if ((temp.day > 28 && temp.CheckingDate() == 1) || (temp.day > 29 && temp.CheckingDate() == 1) || (temp.day > 30 && temp.CheckingDate() == 1) || temp.day > 31) {
		temp.day = 1;
		temp.month++;
	} else if (temp.month > 12) {
		temp.month = temp.month - 12;
		temp.year++;
	}
	return temp;
}

DateTime DateTime::operator- (const DateTime &date) { // перегрузка вычитания двух дат
	DateTime temp;
	temp.day = day - date.day;
	temp.month = month - date.month;
	temp.year = year - date.year;
	temp.hours = hours - date.hours;
	temp.minutes = minutes - date.minutes;
	temp.seconds = seconds - date.seconds;
	if (temp.seconds < 0) {
		temp.seconds = 60 - abs(temp.seconds);
		temp.minutes--;
		if (temp.minutes < 0) {
			temp.minutes = 60 - abs(temp.minutes);
			temp.hours--;
		}
		if (temp.hours < 0) {
			temp.hours = 24 - abs(temp.hours);
			temp.day--;
		}
		if (temp.day < 1) {
			temp.day = 31 - abs(temp.day);
			temp.month--;
			if (temp.CheckingDate() == 1) {
				temp.day--;
			}
		}
		if (temp.month < 1) {
			temp.month = 12 - abs(temp.month);
			temp.year--;
		}
	} else if (temp.minutes < 0) {
		temp.hours--;
		temp.minutes = 60 - abs(temp.minutes);
		if (temp.hours < 0) {
			temp.hours = 24 - abs(temp.hours);
			temp.day--;
		}
		if (temp.CheckingDate() == 1) {
			temp.day = 31 - abs(temp.day);
			temp.month--;
			if (temp.CheckingDate() == 1) {
				temp.day--;
			}
		}
		if (CheckingDate() == 1) {
			temp.month = 12 - abs(temp.month);
			temp.year--;
		}
	} else if (temp.hours < 0) {
		temp.day--;
		temp.hours = 24 - abs(temp.hours);
		if (temp.CheckingDate() == 1) {
			if (temp.day < 1) {
				temp.day = 31 - abs(temp.day);
				temp.month--;
			}
			if (temp.CheckingDate() == 1) {
				temp.day--;
			}
		}
	} else if (temp.day < 1) {
		temp.day = 31 - abs(temp.day);
		temp.month--;
		if (temp.CheckingDate() == 1) {
			temp.day--;
		}
	} else if (temp.month < 1) {
		temp.month = 12 - abs(temp.month);
		temp.year--;
	}
	return temp;
}

DateTime::operator char*() { // оператор присваивания char*
	this->GetDateTime();
	return this->ToString();
}

DateTime operator+ (const DateTime date, int hours) { // дружественный оператор сложения числа часа
	DateTime temp = date;
	temp.hours = date.hours + hours;
	if (temp.hours > 23) {
		temp.hours = temp.hours - 24;
		temp.day++;
	} else if ((temp.day > 28 && temp.CheckingDate() == 1) || (temp.day > 29 && temp.CheckingDate() == 1) || (temp.day > 30 && temp.CheckingDate() == 1) || temp.day > 31) {
		temp.day = temp.day - 31;
		temp.month++;
		while (temp.day < 1) {
			temp.day++;
		}
	} else if (temp.month > 12) {
		temp.month = temp.month - 12;
		temp.year++;
	}
	return temp;
}

DateTime operator- (const DateTime date, int hours) { // дружественный оператор вычитания числа часа
	DateTime temp = date;
	temp.hours = date.hours - hours;
	if (temp.hours < 0) {
		temp.day--;
		temp.hours = 24 - abs(temp.hours);
		if (temp.CheckingDate() == 1) {
			if (temp.day < 1) {
				temp.day = 31 - abs(temp.day);
				temp.month--;
			}
			if (temp.CheckingDate() == 1) {
				temp.day--;
			}
		}
	} else if (temp.day < 1) {
		temp.day = 31 - abs(temp.day);
		temp.month--;
		if (temp.CheckingDate() == 1) {
			temp.day--;
		}
	} else if (temp.month < 1) {
		temp.month = 12 - abs(temp.month);
		temp.year--;
	}
	return temp;
}

DateTime::~DateTime() { // деструктор
	delete[] date_time;
}

void DateTime::CheckingDay(int day) {
	try {
		if (day > 31) {
			throw MyException("in month must be 31 or less days");
		} else if (day < 1) {
			throw MyException("in month mustn't be less then 1 day");
		}
		this->day = day;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DateTime::CheckingMonth(int month) {
	try {
		if (month > 12) {
			throw MyException("in year must be 12 or less month");
		} else if (month < 1) {
			throw MyException("in year mustn't be less then 1 month");
		}
		this->month = month;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DateTime::CheckingYear(int year) {
	try {
		if (year < 1) {
			throw MyException("year mustn't be less then 1");
		} else if (CheckingDate()) {
			throw MyException("date with this year aren't valid");
		}
		this->year = year;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DateTime::CheckingHours(int hours) {
	try {
		if (hours < 0) {
			throw MyException("hours mustn't be less then 0");
		} else if (hours > 23) {
			throw MyException("24th hour must be 0");
		}
		this->hours = hours;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DateTime::CheckingMinutes(int minutes) {
	try {
		if (minutes < 0) {
			throw MyException("minutes mustn't be less then 0");
		} else if (minutes > 59) {
			throw MyException("60th must be 0");
		}
		this->minutes = minutes;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DateTime::CheckingSeconds(int seconds) {
	try {
		if (seconds < 0) {
			throw MyException("seconds mustn't be less then 0");
		} else if (seconds > 59) {
			throw MyException("60th seconds must be 0");
		}
		this->seconds = seconds;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
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
	tmp = date_time;
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
