#include "stl.hpp"

void VectorTest() {
    vector<int> cont;
    cout << "VECTOR TEST INT" << endl;
    cout << "Вставка 1000 последовательных элементов (от 0 до 1000)" << endl;
    int before = clock();
    for (int i = 0; i < 1000; i++) {
        cont.push_back(i);
    }
    cout << "Количество элементов после вставки: " << cont.size() << endl;
    cout << "Время: " << clock() - before << "мс" << endl;
    
    cout << "Сортировка вектора" << endl;
    before = clock();
    sort(cont.begin(),cont.end());
    cout << "Время: " << clock() - before << "мс" << endl;
    
    cout << "Удаление 998 последовательных элементов из контейнера" << endl;
    before = clock();
    while (cont.size() != 2) {
        cont.pop_back();
    }
    cout << "Количество элементов после удаления: " << cont.size() << endl;
    cout << "Время: " << clock() - before << "мс" << endl << endl;
}

void VectorClassTest() {
    cout << "VECTOR CLASS TEST DATETIME" << endl;
    vector<DateTime> cont;
    DateTime date(10, 12, 2021, 1, 1, 1);
    cout << "Вставка 1000 последовательных объектов (от 0 до 1000)" << endl;
    int before = clock();
    for (int i = 0; i < 1000; i++) {
        cont.push_back(date);
    }
    cout << "Количество элементов после вставки: " << cont.size() << endl;
    cout << "Время: " << clock() - before << "мс" <<endl;
    
    cout << "Удаление 500 последовательных объектов из контейнера" << endl;
    before = clock();
    while (cont.size() != 500) {
        cont.pop_back();
    }
    cout << "Количество элементов после удаления: " << cont.size() << endl;
    cout << "Время: " << clock() - before << "мс" << endl << endl;
}

void MapTest() {
    cout << "MAP TEST INT + DATETIME" << endl;
    typedef std::map<int, DateTime> Memories;
    Memories today;
    int num = 1;
    DateTime date(26, 11, 2021, 9, 24, 0);
    DateTime date1(1, 1, 2022, 11, 11, 11);
    DateTime date2(12, 12, 2021, 12, 12, 12);
    cout << "Вставка 300 последовательных элементов" << endl;
    int before = clock();
    for (int i = 0; i < 300; i++) {
        if (i < 100) {
            today.insert(Memories::value_type(num, date));
            num++;
        } else if (i >= 100 && i < 200) {
            today.insert(Memories::value_type(num, date1));
            num++;
        } else {
            today.insert(Memories::value_type(num, date2));
            num++;
        }
    }
    cout << "Количество элементов после вставки: " << today.size() << endl;
    cout << "Время: " << clock() - before << " мс" << endl;
    cout << "Поиск даты: ";
    before = clock();
    int number = 134;
    auto search = today.find(number);
    if (search != today.end()) {
        std::cout << "Found, ";
        map <int, DateTime> :: iterator it = today.begin();
        for (int i = 0; it != today.end(); it++, i++) {
            if (i == number) {
                char* mas = it->second.GetDateTime();
                printf("%s\n", mas);
            }
        }
    } else {
        std::cout << "Not found\n";
    }
    cout << "Время: " << clock() - before << " мс" << endl;
    cout << "Удаление 300 последовательных элементов из контейнера:" << endl;
    before = clock();
    for (auto it = today.begin(); it != today.end();) {
        it = today.erase(it);
    }
    cout << "Время: " << clock() - before << " мс" <<  endl;
    cout << "Количество элементов после удаления: " << today.size() << endl << endl;
}

int main() {
    VectorTest();
    VectorClassTest();
    MapTest();
}
