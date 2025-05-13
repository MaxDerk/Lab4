#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void addBook(vector<Book>& library) {
    Book newBook;
    cout << "����i�� ����� �����: ";
    getline(cin >> ws, newBook.title);
    cout << "����i�� ������: ";
    getline(cin, newBook.author);
    cout << "����i�� �i� �������: ";
    cin >> newBook.year;

    library.push_back(newBook);
    cout << "����� ������!\n";
}

void showLibrary(const vector<Book>& library) {
    if (library.empty()) {
        cout << "�i��i����� �������.\n";
        return;
    }

    cout << "������ ����:\n";
    for (const auto& book : library) {
        cout << "�����: " << book.title
            << ", �����: " << book.author
            << ", �i�: " << book.year << endl;
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    vector<Book> library = {};
    int choice, e;

    cout << "\n=== ������� �i��i����� ===\n";
    cout << "1. ������ �����\n";
    cout << "2. �������� ��i �����\n";
    cout << "��� ���i�: ";
    cin >> choice;

    switch (choice) {
    case 1:
        addBook(library);
        break;
    case 2:
        showLibrary(library);
        break;
    default:
        cout << "���i���� ���i�. ��������� �� ���.\n";
    }
    cout << "\n��� ����� � �������� ������� ���� ��� �������� ";
    cin >> e;
    return 0;

}

