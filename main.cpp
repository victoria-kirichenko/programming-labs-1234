#include "labs123.cpp"
#include "methods_for_2_lab.cpp"
#include "methods_for_3_lab.cpp"
#include "lab4/class_Event.cpp"
#include "lab4/class_TimeString.cpp"
#include "lab5/stack.cpp"

int main() {
   /* DateTime d(1,12,2022,12,12,12);
    DateTime d2;
    ofstream out("txt_and_dat_files/text.txt");
    ifstream in("txt_and_dat_files/text.txt");
    out << d;
    char mas[20];
    char* mas1;
    bool check = true;
    out.close();
    while (!in.eof()) {
        in.getline(mas, 20);
    }
   // in >> mas1;
    check = !memcmp(mas, mas1, 19);
    cout << check;
    in.close(); */

  //  ifstream is("../txt_and_dat_files/text1.txt");
  //  is >> d;
  //  cout << d.GetDateTime();

//  ofstream binary("txt_and_dat_files/binary.dat");
 // writeBinary(binary, d);
 // binary.close();

//ifstream frombinary("txt_and_dat_files/binary.dat");
//readBinary(frombinary, d2);
//cout << d2.GetDateTime();
//frombinary.close();

//Event Event("rave", "ebny room nsk", 25, 6, 2021, 22, 0, 0);
//cout << Event.GetEvent();

// TimeString time("00:00:00", 13, 10, 2021);
// time = time-10;
// time.SetTimeIntAfterOperators(time.GetHours(), time.GetMinutes(), time.GetSeconds());
// cout << time.GetTime() << " " << time.GetDateTime();

  DateTime date(12, 12, 2021, 10, 11, 12);
    TimeString time("10:10:10", 3, 11, 2021);
    Event event("Angina", "NSK", 6, 11, 2021, 9, 0, 0);
    List list;
    list.Push(date);
    list.Push(time);
    list.Push(event);
   // cout << list.Show();
    char *mas = { list.Show() };
    int s = event.SizeOfDate();
    char *mas1 = new char[s];
    strcpy(mas1, event.GetEvent());
    strcat(mas1, "\n");
    strcat(mas1, time.GetDateTime());
    strcat(mas1, "\n");
    strcat(mas1, date.GetDateTime());
    strcat(mas1, "\n");
    cout << mas;
    cout << mas1;
}
