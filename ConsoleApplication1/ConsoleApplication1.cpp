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
    cout << "Enter the book title: ";
    getline(cin >> ws, newBook.title);
    cout << "Enter the author: ";
    getline(cin, newBook.author);
    cout << "Enter the publication year: ";
    cin >> newBook.year;

    library.push_back(newBook);
    cout << "Book added!\n";
}

void showLibrary(const vector<Book>& library) {
    if (library.empty()) {
        cout << "The library is empty.\n";
        return;
    }

    cout << "List of books:\n";
    for (const auto& book : library) {
        cout << "Title: " << book.title
            << ", Author: " << book.author
            << ", Year: " << book.year << endl;
    }
}

int main() {
    vector<Book> library = {
        {"Kobzar", "Taras Shevchenko", 1840},
        {"Forest Song", "Lesya Ukrainka", 1911},
        {"Do the Oxen Roar When the Manger is Full?", "Panas Myrnyi", 1880},
        {"Enchanted Desna", "Oleksandr Dovzhenko", 1942},
        {"City", "Valerian Pidmohylnyi", 1928}
    };
    int choice;

    do {
        cout << "\n=== Home Library ===\n";
        cout << "1. Add a book\n";
        cout << "2. Show all books\n";
        cout << "3. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook(library);
            break;
        case 2:
            showLibrary(library);
            break;
        case 3:
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}