#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void addBook(vector<Book>& library)
{
    Book newBook;
    cout << "Enter book name: ";
    getline(cin >> ws, newBook.title);
    cout << "Enter author name: ";
    getline(cin, newBook.author);
    cout << "Enter publishing year: ";
    while (!(cin >> newBook.year))
    {
        cout << "Invalid input. Enter a valid year: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    library.push_back(newBook);
    cout << "Book successfully added!\n";
}

void showLibrary(const vector<Book>& library)
{
    if (library.empty())
    {
        cout << "The library is empty.\n";
        return;
    }
    cout << "Book list:\n";
    for (const auto& book : library)
        cout << "Title: " << book.title << ", Author: " << book.author << ", Date: " << book.year << endl;
}

void searchBook(const vector<Book>& library)
{
    string searchTitle;
    cout << "Enter book title to search: ";
    getline(cin >> ws, searchTitle);
    bool found = false;
    for (const auto& book : library)
        if (book.title.find(searchTitle) != string::npos)
        {
            cout << "Found: Name: " << book.title << ", Author: " << book.author << ", Date: " << book.year << endl;
            found = true;
        }
    if (!found) cout << "Book was not found.\n";
}

void removeBook(vector<Book>& library)
{
    string searchTitle;
    cout << "Enter book title to delete: ";
    getline(cin >> ws, searchTitle);

    bool found = false;
    for (auto i = library.begin(); i != library.end(); )
    {
        if (i->title.find(searchTitle) != string::npos)
        {
            i = library.erase(i);
            found = true;
        }
        else
        {
            ++i;
        }
    }
    if (found)
        cout << "Book(s) removed.\n";
    else
        cout << "Book not found.\n";
}

void sortBooks(vector<Book>& library)
{
    int j;
    cout << "Sort by:\n1. Title\n2. Author\n3. Year\nYour choice: ";
    while (!(cin >> j) || j < 1 || j > 3)
    {
        cout << "Invalid input. Choose 1, 2 or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (j) {
    case 1:
        sort(library.begin(), library.end(), [](const Book& a, const Book& b) { return a.title < b.title; });
        break;
    case 2:
        sort(library.begin(), library.end(), [](const Book& a, const Book& b) { return a.author < b.author; });
        break;
    case 3:
        sort(library.begin(), library.end(), [](const Book& a, const Book& b) { return a.year < b.year; });
        break;
    }
    cout << "Library sorted.\n";
}

void saveLibrary(const vector<Book>& library, const string& filename)
{
    ofstream outFile(filename);
    for (const auto& book : library)
        outFile << book.title << "," << book.author << "," << book.year << endl;
}

void loadLibrary(vector<Book>& library, const string& filename)
{
    ifstream inFile(filename);
    string title, author;
    int year;
    while (getline(inFile, title, ',') && getline(inFile, author, ',') && inFile >> year)
    {
        inFile.ignore();
        library.push_back({ title, author, year });
    }
}

int main()
{
    vector<Book> library;
    string filename = "library.txt";
    loadLibrary(library, filename);
    int choice;
    do
    {
        cout << "\n=== Home library ===\n";
        cout << "1. Show all books\n";
        cout << "2. Add a book\n";
        cout << "3. Remove a book\n";
        cout << "4. Find a book\n";
        cout << "5. Sort books\n";
        cout << "6. Exit\n";
        while (true)
        {
            cout << "Your option: ";
            if (!(cin >> choice) || choice < 1 || choice > 6)
            {
                cout << "Invalid input. Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        switch (choice)
        {
        case 1:
            showLibrary(library);
            break;
        case 2:
            addBook(library);
            saveLibrary(library, filename);
            break;
        case 3:
            removeBook(library);
            saveLibrary(library, filename);
            break;
        case 4:
            searchBook(library);
            break;
        case 5:
            sortBooks(library);
            break;
        case 6:
            break;
        }
    } while (choice != 6);
    saveLibrary(library, filename);
    return 0;
}