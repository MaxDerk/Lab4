#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream> 
using namespace std;

struct Book
{
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
        cout << "Invalid input. Please enter a valid year: ";
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
    {
        cout << "Title: " << book.title
            << ", Author: " << book.author
            << ", Date: " << book.year << endl;
    }
}

void searchBook(const vector<Book>& library)
{
    string searchTitle;
    cout << "Enter book title to search: ";
    getline(cin >> ws, searchTitle);
    bool found = false;
    for (const auto& book : library)
    {
        if (book.title.find(searchTitle) != string::npos)
        {
            cout << "Found: "
                << "Name: " << book.title
                << ", Author: " << book.author
                << ", Date: " << book.year << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Book was not found.\n";
    }
}

void saveLibraryToFile(const vector<Book>& library, const string& filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cout << "File save error.\n";
        return;
    }
    for (const auto& book : library)
    {
        outFile << book.title << "," << book.author << "," << book.year << endl;
    }
}

void loadLibraryFromFile(vector<Book>& library, const string& filename)
{
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Save file not found.\n";
        return;
    }
    string title, author;
    int year;
    while (getline(inFile, title, ',') && getline(inFile, author, ',') && inFile >> year)
    {
        inFile.ignore();
        library.push_back({title, author, year});
    }
}

int main()
{
    vector<Book> library;
    string filename = "library.txt";
    loadLibraryFromFile(library, filename);
    int choice;
    do {
        cout << "\n=== Home library ===\n";
        cout << "1. Add a book\n";
        cout << "2. Show all books\n";
        cout << "3. Find a book\n";
        cout << "4. Exit\n";
        cout << "Your option: ";
        while (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice)
        {
        case 1:
            addBook(library);
            break;
        case 2:
            showLibrary(library);
            break;
        case 3:
            searchBook(library);
            break;
        case 4:
            break;
        default:
            cout << "Wrong option. Try again.\n";
        }
        if (choice == 1)
        {
            saveLibraryToFile(library, filename);
        }
    } while (choice != 4);
    saveLibraryToFile(library, filename);
    return 0;
}
