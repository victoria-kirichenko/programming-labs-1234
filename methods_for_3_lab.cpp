#include "labs123.hpp"

ofstream& operator<< (ofstream& os, DateTime& date) {
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

ifstream& operator>> (ifstream& is, DateTime& date) {
    char Date[10];
    char Time[8];
    is >> Date;
    if (Date[0] == '0') {
        date.day = Date[1] - '0';
    } else {
        date.day = 10 * (Date[0] - '0') + (Date[1] - '0');
    }
    if (Date[3] == '0') {
        date.month = Date[4] - '0';
    } else {
        date.month = 10 * (Date[3] - '0') + (Date[3] - '0');
    }
    if (Date[6] == '0') {
        if (Date[7] == '0') {
            if (Date[8] == '0') {
                date.year = Date[9] - '0';
            } else {
                date.year = 10 * (Date[8] - '0') + (Date[9] - '0');
            }
        } else {
            date.year = 100 * (Date[7] - '0') + 10 * (Date[8] - '0') + (Date[9] - '0');
        }
    } else {
        date.year = 1000 * (Date[6] - '0') + 100 * (Date[7] - '0') + 10 * (Date[8] - '0') + (Date[9] - '0');
    }
    is >> Time;
    if (Time[0] == '0') {
        date.hours = Time[1] - '0';
    } else {
        date.hours = 10 * (Time[0] - '0') + (Time[1] - '0');
    }
    if (Time[3] == '0') {
        date.minutes = Time[4] - '0';
    } else {
        date.minutes = 10 * (Time[3] - '0') + (Time[4] - '0');
    }
    if (Time[6] == '0') {
        date.seconds = Time[7] - '0';
    } else {
        date.seconds = 10 * (Time[6] - '0') + (Time[7] - '0');
    }

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
