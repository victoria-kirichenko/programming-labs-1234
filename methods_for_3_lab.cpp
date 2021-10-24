#include "labs123.hpp"

ofstream& operator<< (ofstream& os, DateTime& date) { // в файл
    try {
        if (date.day < 1 || date.month < 1 || date.year < 1 || date.hours < 0 || date.minutes < 0 || date.seconds < 0) {
            throw MyException("Date and time format is uncorrect");
        }
        os << setfill('0') << setw(2) << date.day << "." << setfill('0') << setw(2) << date.month << "." << setfill('0') << setw(2) << date.year << " "
        << setfill('0') << setw(2) << date.hours << ":" << setfill('0') << setw(2) << date.minutes << ":" << setfill('0') << setw(2) << date.seconds;
    }
    catch (MyException &ex) {
		cerr << ex.what() << "\n";
    }
    return os;
}

ifstream& operator>> (ifstream& is, DateTime& date) { // из файла
    int Day, Month, Year, Hours, Minutes, Seconds;
    char Date[10];
    char Time[8];
    is >> Date;
    if (Date[0] == '0') {
        Day = Date[1] - '0';
    } else {
        Day = 10 * (Date[0] - '0') + (Date[1] - '0');
    }
    if (Date[3] == '0') {
        Month = Date[4] - '0';
    } else {
        Month = 10 * (Date[3] - '0') + (Date[3] - '0');
    }
    if (Date[6] == '0') {
        if (Date[7] == '0') {
            if (Date[8] == '0') {
                Year = Date[9] - '0';
            } else {
                Year = 10 * (Date[8] - '0') + (Date[9] - '0');
            }
        } else {
            Year = 100 * (Date[7] - '0') + 10 * (Date[8] - '0') + (Date[9] - '0');
        }
    } else {
        Year = 1000 * (Date[6] - '0') + 100 * (Date[7] - '0') + 10 * (Date[8] - '0') + (Date[9] - '0');
    }
    is >> Time;
    if (Time[0] == '0') {
        Hours = Time[1] - '0';
    } else {
        Hours = 10 * (Time[0] - '0') + (Time[1] - '0');
    }
    if (Time[3] == '0') {
        Minutes = Time[4] - '0';
    } else {
        Minutes = 10 * (Time[3] - '0') + (Time[4] - '0');
    }
    if (Time[6] == '0') {
        Seconds = Time[7] - '0';
    } else {
        Seconds = 10 * (Time[6] - '0') + (Time[7] - '0');
    }
    date.SetDay(Day);
    date.SetMonth(Month);
    date.SetYear(Year);
    date.SetHours(Hours);
    date.SetMinutes(Minutes);
    date.SetSeconds(Seconds);
    try {
        if (date.day < 1 || date.month < 1 || date.year < 1 || date.hours < 0 || date.minutes < 0 || date.seconds < 0) {
            throw MyException("Date and time format is uncorrect");
        }
    }
    catch (MyException &ex) {
		cerr << ex.what() << "\n";
    }
   return is;
}

ofstream& writeBinary (ofstream &os , DateTime& date) {
    try {
        if (!os.is_open()) {
            throw MyException("File cannot open");
        } else {
            os.write((char*)&date.day, sizeof(int));
            os.write((char*)&date.month, sizeof(int));
            os.write((char*)&date.year, sizeof(int));
            os.write((char*)&date.hours, sizeof(int));
            os.write((char*)&date.minutes, sizeof(int));
            os.write((char*)&date.seconds, sizeof(int));

            os.close();
        }
    }
    catch (MyException &ex) {
		cerr << ex.what() << "\n";
    }
   return os;
}

ifstream& readBinary (ifstream &is , DateTime& date) {
    try {
        if (!is.is_open()) {
            throw MyException("File cannot open");
        } else {
            is.read((char*)&date, sizeof(DateTime));
            date.GetDateTime();
            is.close();
        }
    }
    catch (MyException &ex) {
		cerr << ex.what() << "\n";
    }
   return is;
}
