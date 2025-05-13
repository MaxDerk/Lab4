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
    cout << "Введiть назву книги: ";
    getline(cin >> ws, newBook.title);
    cout << "Введiть автора: ";
    getline(cin, newBook.author);
    cout << "Введiть рiк видання: ";
    cin >> newBook.year;

    library.push_back(newBook);
    cout << "Книгу додано!\n";
}

void showLibrary(const vector<Book>& library) {
    if (library.empty()) {
        cout << "Бiблiотека порожня.\n";
        return;
    }

    cout << "Список книг:\n";
    for (const auto& book : library) {
        cout << "Назва: " << book.title
            << ", Автор: " << book.author
            << ", Рiк: " << book.year << endl;
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    vector<Book> library = {};
    int choice, e;
    addBook(library);
    showLibrary(library);
    cout << "\nЩоб вийти з програми введьть будь яке значення ";
    cin >> e;
    return 0;
}