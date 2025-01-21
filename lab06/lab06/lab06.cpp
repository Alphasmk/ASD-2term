#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <windows.h>
#include <chrono>

using namespace std;

int table_size, key;

struct element {
    int phone;
    string FIO;
};

class HashTable {
private:
    vector<list<element>> table;
    int hashFunc(int key) {
        return key % table_size;
    }
public:
    HashTable() {
        table.resize(table_size);
    }

    void insert(int phone_number, string name) {
        key = hashFunc(phone_number);
        table[key].push_back({ phone_number, name });
    }

    void remove(int phone_number) {
        key = hashFunc(phone_number);
        for (auto pointer = table[key].begin(); pointer != table[key].end(); pointer++) {
            if (pointer->phone == phone_number) {
                table[key].erase(pointer);
                return;
            }
        }
    }

    vector<string> search(int phone_number) {
        key = hashFunc(phone_number);
        vector<string> results;
        for (auto element : table[key]) {
            if (element.phone == phone_number) {
                results.push_back(element.FIO);
            }
        }
        return results;
    }

    void display() {
        cout << "Хеш-таблица: " << endl;
        for (int i = 0; i < table_size; i++) {
            cout << "Элемент " << i + 1 << ": " << endl;
            for (auto pointer : table[i]) {
                cout << "Номер телефона: " << pointer.phone << endl;
                cout << "ФИО: " << pointer.FIO << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_CTYPE, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    do {
        cout << "Введите размер таблицы: ";
        cin >> table_size;
        if (table_size <= 0) {
            cout << "Размер таблицы должен быть положительным и не равным нулю! " << endl;
        }
    } while (table_size <= 0);

    HashTable phones;

    int number;
    string FIO;
    char choice;
    auto start_time = chrono::steady_clock::now();
    auto end_time = chrono::steady_clock::now();
    vector<string> results;
    cout << "1 - добавить элемент в хеш-таблицу" << endl
        << "2 - удалить элемент по номеру телефона" << endl
        << "3 - поиск по номеру телефона" << endl
        << "4 - вывести всю таблицу" << endl;
    while (true) {
        cout << "?: ";
        cin >> choice;
        switch (choice) {
        case '1':
            do {
                cout << "Введите номер телефона: ";
                cin >> number;
                if (number <= 0) {
                    cout << "Номер телефона должен быть положительным и не равным нулю! " << endl;
                }
            } while (number <= 0);
            cout << "Введите ФИО: ";
            cin.ignore();
            getline(cin, FIO);
            phones.insert(number, FIO);
            break;
        case '2':
            cout << "Введите номер телефона: ";
            cin >> number;
            phones.remove(number);
            break;
        case '3':
            cout << "Введите номер телефона: ";
            cin >> number;
            start_time = chrono::steady_clock::now();
            results = phones.search(number);
            end_time = chrono::steady_clock::now();
            for (auto result : results) {
                cout << "Элемент с номером телефона " << number << ": " << result << endl;
            }
            cout << "Время выполнения поиска: " << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count() << " наносекунд" << endl;
            break;
        case '4':
            phones.display();
            break;
        }
    }
}
