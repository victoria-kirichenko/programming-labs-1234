#ifndef CLASS_EVENT_HPP_INCLUDED
#define CLASS_EVENT_HPP_INCLUDED
#include "../labs123.hpp"

class Event : public DateTime {
public:

	Event() : name(new char[30]), city(new char[30]), DateTime() {
		name = "Rave", city = "Moscow";
	}

    Event(const char* namE, const char* citY, int day, int month, int year, int hours, int minutes, int seconds)
        : name(new char[strlen(namE) + 1]), city(new char[strlen(citY) + 1]), DateTime(day, month, year, hours, minutes, seconds) {
			name = namE, city = citY;
		}

	void SetName(const char* valueName);
	const char* GetName();
	void SetCity(const char* valueCity);
	const char* GetCity();
	char* GetEvent();
	~Event() { delete[] name, city; }

private:
    const char* name = new char[30];
	const char* city = new char[30];
};

#endif // CLASS_EVENT_HPP_INCLUDED