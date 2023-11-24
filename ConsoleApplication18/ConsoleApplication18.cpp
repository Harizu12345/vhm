#include <iostream>

using namespace std;


//1

/*
const int MAX_ROWS = 100; // Максимальное количество строк
const int MAX_COLS = 100; // Максимальное количество столбцов

// Функция для транспонирования матрицы
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int transposed[MAX_COLS][MAX_ROWS];

    // Проходим по исходной матрице и заполняем транспонированную
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Выводим транспонированную матрицу
    cout << "transposed matrix:" << endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    int matrix[MAX_ROWS][MAX_COLS];

    // Вводим количество строк и столбцов матрицы
    cout << "rows matrix: ";
    cin >> rows;
    cout << "cols matrix: ";
    cin >> cols;

    // Вводим элементы матрицы
    cout << "element matrix: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Вызываем функцию для транспонирования матрицы
    transposeMatrix(matrix, rows, cols);

    return 0;
}
*/


//2

#include <iostream>
#include <string>

using namespace std;

const int MAX_CONTACTS = 100;

struct Contact {
    string name;
    string phone;
};

void searchByName(Contact contacts[], int size, const string& name) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].name == name) {
            cout << "contact:" << endl;
            cout << "Name: " << contacts[i].name << endl;
            cout << "phone: " << contacts[i].phone << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "contact '" << name << "' not find" << endl;
    }
}

void searchByPhone(Contact contacts[], int size, const string& phone) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].phone == phone) {
            cout << "contact:" << endl;
            cout << "Name: " << contacts[i].name << endl;
            cout << "phone: " << contacts[i].phone << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "contact '" << phone << "' not find" << endl;
    }
}

int main() {
    Contact* contacts = new Contact[MAX_CONTACTS];
    int contactsCount = 0;

    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add a contact" << endl;
        cout << "2. Search by name" << endl;
        cout << "3. Search by phone number" << endl;
        cout << "4. Exit" << endl;
        cout << "Select : ";
        cin >> choice;

        switch (choice) {
        case '1': {
            if (contactsCount < MAX_CONTACTS) {
                cout << "name: ";
                cin >> contacts[contactsCount].name;
                cout << "numebr of phone: ";
                cin >> contacts[contactsCount].phone;
                contactsCount++;
            }
            else {
                cout << "u have max contact." << endl;
            }
            break;
        }
        case '2': {
            string name;
            cout << "name for search: ";
            cin >> name;
            searchByName(contacts, contactsCount, name);
            break;
        }
        case '3': {
            string phone;
            cout << "number for search: ";
            cin >> phone;
            searchByPhone(contacts, contactsCount, phone);
            break;
        }
        case '4':
            break;
        default:
            cout << "error" << endl;
        }
    } while (choice != '4');

    delete[] contacts;

    return 0;
}
