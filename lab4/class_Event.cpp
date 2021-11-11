#include "class_Event.hpp"

const char* Event::GetName() {
	const char *tmp = new char[30];
	tmp = name;
	return tmp;
}

void Event::SetName(const char* valueName) {
	name = valueName;
}

const char* Event::GetCity() {
	const char *tmp = new char[30];
	tmp = city;
	return tmp;
}

void Event::SetCity(const char* valueCity) {
	city = valueCity;
}

char* Event::GetEvent() {
	char* tmp = new char[100];
	strcpy(tmp, GetName());
	strcat(tmp, " ");
	strcat(tmp, GetCity());
	strcat(tmp, " ");
	strcat(tmp, DateTime::GetDateTime());
	return tmp;
}

int Event::SizeOfDate() {
    int size = strlen(this->GetStr());
    return size;
}

char* Event::GetStr() {
	char* tmp = new char[100];
	strcpy(tmp, GetName());
	strcat(tmp, " ");
	strcat(tmp, GetCity());
	strcat(tmp, " ");
	strcat(tmp, DateTime::GetDateTime());
	return tmp;
}