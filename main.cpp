#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string isbn, title, author, edition, publication;

public:
    void setIsbn(string a) { isbn = a; }
    void setTitle(string b) { title = b; }
    void setAuthor(string c) { author = c; }
    void setEdition(string d) { edition = d; }
    void setPublication(string e) { publication = e; }

    string getIsbn() { return isbn; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getEdition() { return edition; }
    string getPublication() { return publication; }
};

void addBook(int &counter, Book books[]);
void deleteBook(int &counter, Book books[]);
void editBook(int &counter, Book books[]);
void searchBook(int counter, Book books[]);
void viewAllBooks(int counter, Book books[]);
void quit();

int main() {
    string choice;
    int counter = 0;
    Book books[10];

    while (true) {
        cout << "LIBRARY MANAGEMENT SYSTEM\n\n";
        cout << "[1] ADD BOOK\n";
        cout << "[2] DELETE BOOK\n";
        cout << "[3] EDIT BOOK\n";
        cout << "[4] SEARCH BOOK\n";
        cout << "[5] VIEW ALL BOOKS\n";
        cout << "[6] QUIT\n\n";
        cout << "ENTER CHOICE: ";
        cin >> choice;

        switch (choice[0]) {
            case '1':
                addBook(counter, books);
                break;
            case '2':
                deleteBook(counter, books);
                break;
            case '3':
                editBook(counter, books);
                break;
            case '4':
                searchBook(counter, books);
                break;
            case '5':
                viewAllBooks(counter, books);
                break;
            case '6':
                quit();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

void addBook(int &counter, Book books[]) {
    string isbn, title, author, edition, publication;

    cout << "ADD BOOK\n\n";
    if (counter < 10) {
        cout << "Enter ISBN: ";
        cin.ignore();
        getline(cin, isbn);
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Edition: ";
        getline(cin, edition);
        cout << "Enter Publication: ";
        getline(cin, publication);

        books[counter].setIsbn(isbn);
        books[counter].setTitle(title);
        books[counter].setAuthor(author);
        books[counter].setEdition(edition);
        books[counter].setPublication(publication);

        counter++;

        cout << "\nBOOK ADDED SUCCESSFULLY!\n\n";
    } else {
        cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n\n";
    }

    cout << "Press Enter to continue . . .";
    cin.ignore();
    cin.get();
}

void deleteBook(int &counter, Book books[]) {
    string isbn;
    int choice;

    cout << "DELETE BOOK\n\n";
    if (counter == 0) {
        cout << "THERE IS NO BOOK TO DELETE!\n\n";
    } else {
        cout << "Enter ISBN: ";
        cin.ignore();
        getline(cin, isbn);

        for (int i = 0; i < counter; i++) {
            if (books[i].getIsbn() == isbn) {
                cout << "\nBOOK FOUND\n\n";
                cout << "Do you want to delete?\n[1] Yes\n[2] No\n\nEnter Choice: ";
                cin >> choice;
                if (choice == 1) {
                    for (int a = i; a < counter - 1; a++) {
                        books[a] = books[a + 1];
                    }
                    counter--;

                    cout << "\nBOOK SUCCESSFULLY DELETED!\n\n";
                }
                break;
            }
        }

        if (choice != 1) {
            cout << "BOOK NOT FOUND OR NOT DELETED!\n\n";
        }
    }

    cout << "Press Enter to continue . . .";
    cin.ignore();
    cin.get();
}

void editBook(int &counter, Book books[]) {
    string editIsbn, choice;
    string isbn, title, author, edition, publication;

    cout << "EDIT BOOK\n\n";
    if (counter == 0) {
        cout << "THERE IS NO BOOK TO EDIT!\n\n";
    } else {
        cout << "Enter ISBN: ";
        cin.ignore();
        getline(cin, editIsbn);

        for (int i = 0; i < counter; i++) {
            if (books[i].getIsbn() == editIsbn) {
                cout << "\nBOOK FOUND!\n\n";
                cout << "ISBN: " << books[i].getIsbn() << endl;
                cout << "TITLE: " << books[i].getTitle() << endl;
                cout << "AUTHOR: " << books[i].getAuthor() << endl;
                cout << "EDITION: " << books[i].getEdition() << endl;
                cout << "PUBLICATION: " << books[i].getPublication() << endl;
                cout << "\nDo you want to edit?\n[1] Yes\n[2] No\n\nEnter choice: ";
                cin >> choice;
                if (choice == "1") {
                    cout << "Enter ISBN: ";
                    cin.ignore();
                    getline(cin, isbn);
                    cout << "Enter Title: ";
                    getline(cin, title);
                    cout << "Enter Author: ";
                    getline(cin, author);
                    cout << "Enter Edition: ";
                    getline(cin, edition);
                    cout << "Enter Publication: ";
                    getline(cin, publication);

                    books[i].setIsbn(isbn);
                    books[i].setTitle(title);
                    books[i].setAuthor(author);
                    books[i].setEdition(edition);
                    books[i].setPublication(publication);

                    cout << "\nBOOK EDITED SUCCESSFULLY!\n\n";
                }
                break;
            }
        }

        if (choice != "1") {
            cout << "BOOK NOT FOUND OR NOT EDITED!\n\n";
        }
    }

    cout << "Press Enter to continue . . .";
    cin.ignore();
    cin.get();
}

void searchBook(int counter, Book books[]) {
    string isbn;

    cout << "SEARCH BOOK\n\n";
    if (counter == 0) {
        cout << "THERE IS NO BOOK TO SEARCH!\n\n";
    } else {
        cout << "Enter ISBN: ";
        cin.ignore();
        getline(cin, isbn);

        bool found = false;

        for (int i = 0; i < counter; i++) {
            if (books[i].getIsbn() == isbn) {
                cout << "\nBOOK FOUND!\n\n";
                cout << "ISBN: " << books[i].getIsbn() << endl;
                cout << "TITLE: " << books[i].getTitle() << endl;
                cout << "AUTHOR: " << books[i].getAuthor() << endl;
                cout << "EDITION: " << books[i].getEdition() << endl;
                cout << "PUBLICATION: " << books[i].getPublication() << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "BOOK NOT FOUND!\n\n";
        }
    }

    cout << "Press Enter to continue . . .";
    cin.ignore();
    cin.get();
}

void viewAllBooks(int counter, Book books[]) {
    cout << "VIEW ALL BOOKS\n\n";
    if (counter == 0) {
        cout << "THERE ARE NO BOOKS TO VIEW!\n\n";
    } else {
        for (int i = 0; i < counter; i++) {
            cout << "BOOK DETAILS\n\n";
            cout << "ISBN: " << books[i].getIsbn() << endl;
            cout << "TITLE: " << books[i].getTitle() << endl;
            cout << "AUTHOR: " << books[i].getAuthor() << endl;
            cout << "EDITION: " << books[i].getEdition() << endl;
            cout << "PUBLICATION: " << books[i].getPublication() << endl << endl;
        }
    }

    cout << "Press Enter to continue . . .";
    cin.ignore();
    cin.get();
}

void quit() {
    cout << "Exiting the program.\n";
    exit(0);
}
