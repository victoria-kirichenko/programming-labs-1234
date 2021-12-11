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
    
    cout << "Добавление элемента в любое место" << endl;
    before = clock();
    auto it = cont.insert(cont.begin() + 1, 3);
    cout << "Элементы после вставки: " << endl;
    for (auto it = cont.begin(); it != cont.end(); ++it) {
        cout << *it << " ";
        if (*it == 4) {
            break;
        }
    }
    cout << endl << "Время: " << clock() - before << "мс" << endl;

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
    cout << "MAP TEST DATETIME + DATETIME" << endl;
    map<DateTime, DateTime> Memories;
    vector<DateTime> vec;
    DateTime key(1, 1, 2021, 0, 0, 0);
    DateTime key1(1, 1, 2021, 0, 0, 0);
    DateTime date(26, 11, 2021, 9, 24, 0);
    DateTime date1(1, 1, 2022, 11, 11, 11);
    DateTime date2(12, 12, 2021, 12, 12, 12);
    cout << "Вставка 300 последовательных элементов" << endl;
    int before = clock();
    for (int i = 0; i < 300; i++) {
        if (i < 100) {
            Memories.insert(make_pair(key, date));
            key = key + 1;
        } else if (i >= 100 && i < 200) {
            Memories.insert(make_pair(key, date1));
            key = key + 1;
        } else {
            Memories.insert(make_pair(key, date2));
            key = key + 1;
        }
    }
    for (int i = 0; i < 300; i++) {
        if (i < 100) {
            vec.push_back(key1);
            key1 = key1 + 1;
        } else if (i >= 100 && i < 200) {
            vec.push_back(key1);
            key1 = key1 + 1;
        } else {
            vec.push_back(key1);
            key1 = key1 + 1;
        }
    }
    cout << "Количество элементов после вставки: " << Memories.size() << endl;
    cout << "Время: " << clock() - before << " мс" << endl;
    cout << "Поиск даты: ";
    before = clock();
    bool check = 1;
    DateTime number(1, 1, 2021, 12, 0, 0);
    vector<DateTime>::iterator iter = vec.begin();
    DateTime num(1, 1, 2021, 12, 0, 0);
    char *data = num;
    for (; iter != vec.end(); iter++) {
        char *r = *iter;
        if (!memcmp(r,data,19)) {
            check = 0;
            break;
        } else {
            r = new char[19];
            check = 1;
        }
    }
    if (check == 0) {
        cout << "Found: " << number.GetDateTime() << endl;
    } else {
        cout << "Not Found" << endl;
    }
    cout << "Время: " << clock() - before << " мс" << endl;
    cout << "Удаление 300 последовательных элементов из контейнера:" << endl;
    before = clock();
    for (auto it = Memories.begin(); it != Memories.end();) {
        it = Memories.erase(it);
    }
    cout << "Время: " << clock() - before << " мс" <<  endl;
    cout << "Количество элементов после удаления: " << Memories.size() << endl << endl;
}

int main() {
    VectorTest();
    VectorClassTest();
    MapTest();
}
