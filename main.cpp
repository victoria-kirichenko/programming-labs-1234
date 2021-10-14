#include "progr_date_time_labs_6.cpp"

int main() {
    DateTime d(34, 13, 2022, 78, 70, 60);
    d.CheckingDay(d.GetDay());
    d.CheckingMonth(d.GetMonth());
    d.CheckingHours(d.GetHours());
    d.CheckingMinutes(d.GetMinutes());
    d.CheckingSeconds(d.GetSeconds());
	DateTime d1(29, 2, 2021, 13, 14, 15);
	d1.CheckingYear(d1.GetYear());
    DateTime d2(0, 0, -1, -1, -1, -1);
    d2.CheckingDay(d2.GetDay());
    d2.CheckingMonth(d2.GetMonth());
    d2.CheckingHours(d2.GetHours());
    d2.CheckingMinutes(d2.GetMinutes());
    d2.CheckingSeconds(d2.GetSeconds());
    d2.CheckingYear(d2.GetYear());
}
