#define CATCH_CONFIG_MAIN

#include "progr_date_time_labs_6.cpp"
#include "catch.hpp"  

TEST_CASE("combo and weird date (+Seconds/+Day)") {
	DateTime date(31, 12, 2021, 13, 40, 59);
	date.PlusSeconds();
	date.PlusDay();
    bool check = false;
    if (date.GetDay() == 1 && date.GetSeconds() == 0 && date.GetMonth() == 1 && date.GetYear() == 2022 && date.GetMinutes() == 41) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("1th march minus day") {
    DateTime date(1, 3, 2021, 10, 50, 30);
    date.MinusDay();
    bool check = false;
    if (date.GetDay() == 28 && date.GetMonth() == 2) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("Print() with parametres") {
    DateTime date(15, 10, 1345, 16, 32, 12);
    char* mas1 = { date.GetDateTime() };
    char mas2[20] = "15.10.1345 16:32:12";
    REQUIRE(!memcmp(mas1, mas2, 19));
}

TEST_CASE("Print() without parametres") {
    DateTime date;
    char* mas1 = { date.GetDateTime() };
    char mas2[20] = "01.01.1000 00:00:00";
    REQUIRE(!memcmp(mas1, mas2, 19));
}

TEST_CASE("24 hours + 1 hour") {
    DateTime date(4, 5, 2020, 23, 30, 40);
    bool check = false;
    date.PlusHours();
    if (date.GetHours() == 0 && date.GetDay() == 5) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("valid date: 31.07 - 1 month") {
    DateTime date(31, 7, 2020, 20, 30, 40);
    bool check = false;
    date.MinusMonth();
    if (date.GetMonth() == 6 && date.GetDay() == 30) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("Plus Year") {
    DateTime date(31, 7, 2020, 20, 30, 40);
    bool check = false;
    date.PlusYear();
    if (date.GetYear() == 2021) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("Plus Minute") {
    DateTime date(31, 7, 2020, 20, 32, 40);
    bool check = false;
    date.PlusMinutes();
    if (date.GetMinutes() == 33) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("copy") {
    DateTime date(31, 7, 2020, 20, 32, 40);
    DateTime date1(date);
    char* mas = { date.GetDateTime() };
    char* mas1 = { date1.GetDateTime() };
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("Minus hour + auto minus year") {
    DateTime date(1, 1, 2022, 0, 20, 40);
    date.MinusHours();
    char *mas = { date.GetDateTime() };
    char mas1[20] = "31.12.2021 23:20:40";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("Minus year + leap year") {
    DateTime date(29, 2, 2024, 22, 34, 12);
    date.MinusYear();
    char *mas = { date.GetDateTime() };
    char mas1[20] = "28.02.2023 22:34:12";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("Plus Month") {
    DateTime date(29, 2, 2024, 22, 34, 12);
    date.PlusMonth();
    char *mas = { date.GetDateTime() };
    char mas1[20] = "29.03.2024 22:34:12";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("Minus second + auto minus minute") {
    DateTime date(29, 2, 2024, 22, 34, 0);
    date.MinusSeconds();
    char *mas = { date.GetDateTime() };
    char mas1[20] = "29.02.2024 22:33:59";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("Minus minute + auto minus hour") {
    DateTime date(29, 2, 2024, 22, 0, 1);
    date.MinusMinutes();
    char *mas = { date.GetDateTime() };
    char mas1[20] = "29.02.2024 21:59:01";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("combo: copy + weird date + plus hour") {
    DateTime date(29, 2, 2024, 23, 7, 7);
    DateTime date1(date);
    bool check = false;
    char* mas = { date.GetDateTime() };
    char* mas1 = { date1.GetDateTime() };
    check = !memcmp(mas, mas1, 19);
    date1.PlusHours();
    char* mas2 = { date1.GetDateTime() };
    char mas3[20] = "01.03.2024 00:07:07";
    REQUIRE(!memcmp(mas2, mas3, 19));
}

TEST_CASE("operator =") {
    DateTime date1(29, 2, 2024, 23, 7, 7);
    DateTime date2(23, 1, 2021, 13, 12, 45);
    date1 = date2;
    char* mas = { date1.GetDateTime() };
    char mas1[20] = "23.01.2021 13:12:45";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("operator adding dates") {
    DateTime date1(3, 3, 2021, 13, 14, 15);
    DateTime date2(3, 3, 2021, 14, 12, 35);
    DateTime p = date1 + date2;
    char* mas = { p.GetDateTime() };
    char mas1[20] = "06.06.4042 27:26:50";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("operator subtracting dates") {
    DateTime date1(3, 3, 2021, 13, 14, 15);
    DateTime date2(2, 2, 2020, 12, 12, 10);
    DateTime p = date1 - date2;
    char* mas = { p.GetDateTime() };
    char mas1[20] = "01.01.0001 01:02:05";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("operator char*") {
    DateTime date1(3, 3, 2021, 13, 14, 15);
    char* r = date1;
    char mas1[20] = "03.03.2021 13:14:15";
    REQUIRE(!memcmp(r, mas1, 19));
}

TEST_CASE("operator adding number in year") {
    DateTime date1(3, 3, 2021, 13, 14, 15);
    date1 = date1 + 4;
    char mas1[20] = "03.03.2025 13:14:15";
    REQUIRE(!memcmp(date1, mas1, 19));
}

TEST_CASE("operator subtragting number in year") {
    DateTime date1(3, 3, 2021, 13, 14, 15);
    date1 = date1 - 4;
    char mas1[20] = "03.03.2017 13:14:15";
    REQUIRE(!memcmp(date1, mas1, 19));
}
