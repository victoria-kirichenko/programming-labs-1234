#include "class_TimeString.hpp"

const char* TimeString::GetTime() {
	const char *tmp = new char[8];
	tmp = time;
	return tmp;
}

void TimeString::SetTimeStr(char* valueTime) {
	time = valueTime;
}

void TimeString::SetTimeInt(int h, int m, int s) {
    DateTime::SetHours(h);
    DateTime::SetMinutes(m);
    DateTime::SetSeconds(s);
    char* timee;
    sprintf(timee, "%.2d:%.2d:%.2d", this->GetHours(), this->GetMinutes(), this->GetSeconds());
    SetTimeStr(timee);
}

void TimeString::SetTimeIntAfterOperators(int h, int m, int s) {
    char* timee;
    sprintf(timee, "%.2d:%.2d:%.2d", this->GetHours(), this->GetMinutes(), this->GetSeconds());
    SetTimeStr(timee);
}

TimeString operator+ (const TimeString time, int value) {
    TimeString temp = time;
     try {
        if (value < 0 || value > 12) {
            throw MyException("This value is out of range");
        }
	    temp.hours = time.hours + value;
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
    }
    catch (MyException &ex) {
		cerr << ex.what() << "\n";
    }
    return temp;
}

TimeString operator- (const TimeString time, int value) {
    TimeString temp = time;
     try {
        if (value < 0 || value > 12) {
            throw MyException("This value is out of range");
        }
        temp.hours = time.hours - value;
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
    }
    catch (MyException &ex) {
		cerr << ex.what() << "\n";
    }
    return temp;
}

int TimeString::SizeOfDate() {
    int size = strlen(this->GetStr());
    return size;
}

char* TimeString::GetStr() {
	char* tmp = new char[20];
	strcpy(tmp, DateTime::GetDateTime());
	return tmp;
}