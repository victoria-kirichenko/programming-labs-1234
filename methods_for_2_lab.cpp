#include "labs123.hpp"

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

bool operator< (DateTime date, DateTime date1) {
	if (date.GetYear() > date1.GetYear()) {
		return false;
	} else if (date.GetYear() < date1.GetYear()) {
		return true;
	} else if (date.GetYear() == date1.GetYear()) {
		if (date.GetMonth() > date1.GetMonth()) {
			return false;
		} else if (date.GetMonth() < date1.GetMonth()) {
			return true;
		} else if (date.GetMonth() == date1.GetMonth()) {
			if (date.GetDay() > date1.GetDay()) {
				return false;
			} else if (date.GetDay() < date1.GetDay()) {
				return true;
			} else if (date.GetDay() == date1.GetDay()) {
				if (date.GetHours() > date1.GetHours()) {
					return false;
				} else if (date.GetHours() < date1.GetHours()) {
					return true;
				} else if (date.GetHours() == date1.GetHours()) {
					if (date.GetMinutes() > date1.GetMinutes()) {
						return false;
					} else if (date.GetMinutes() < date1.GetMinutes()) {
						return true;
					} else if (date.GetMinutes() == date1.GetMinutes()) {
						if (date.GetSeconds() > date1.GetSeconds()) {
							return false;
						} else if (date.GetSeconds() < date1.GetSeconds()) {
							return true;
						} else {
							return true;
						}
					}
				}
			}
		}
	}
	return true;
}