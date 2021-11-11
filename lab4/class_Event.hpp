#ifndef CLASS_EVENT_HPP_INCLUDED
#define CLASS_EVENT_HPP_INCLUDED
#include "../labs123.hpp"

class Event : public DateTime {
public:

	Event() : name("Rave"), city("Moscow"), DateTime() {
	}

    Event(const char* namE, const char* citY, int day, int month, int year, int hours, int minutes, int seconds)
        : name(namE), city(citY), DateTime(day, month, year, hours, minutes, seconds) {
		}

	void SetName(const char* valueName);
	const char* GetName();
	void SetCity(const char* valueCity);
	const char* GetCity();
	char* GetEvent();

	virtual int SizeOfDate();
	virtual char *GetStr();

	~Event() { delete[] name, city; }

private:
    const char* name = new char[30];
	const char* city = new char[30];
};

#endif // CLASS_EVENT_HPP_INCLUDED