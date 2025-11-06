#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// Book class
class Book {
public:
    string bno, bname, aname;

    void createBook() {
        cout << "Enter Book No: "; cin >> bno;
        cin.ignore();
        cout << "Enter Book Name: "; getline(cin, bname);
        cout << "Enter Author Name: "; getline(cin, aname);
    }

    void showBook() const {
        cout << "\nBook No: " << bno
             << "\nBook Name: " << bname
             << "\nAuthor Name: " << aname << endl;
    }
};

// Student class
class Student {
public:
    string admno, name, stbno,adress;
    int token = 0;

    void createStudent() {
        cout << "Enter USN: "; cin >> admno;
        cin.ignore();
        cout << "Enter Student Name: "; getline(cin, name);
        cout<<"Enter adress :";getline(cin,adress);
        token = 0;
        stbno = "";
    }

    void showStudent() const {
        cout << "\n USN No: " << admno
             << "\nStudent Name: " << name
             << "\nBooks Issued: " << token<<"\nAdress : "<<adress;
        if (token == 1)
            cout << "\nBook No: " << stbno;
        cout << endl;
    }
};

// Global vectors
vector<Book> books;
vector<Student> students;

// File I/O
void loadBooks() {
    books.clear();
    ifstream fin("books.dat");
    while (fin) {
        Book b;
        getline(fin, b.bno);
        if (b.bno.empty()) break;
        getline(fin, b.bname);
        getline(fin, b.aname);
        books.push_back(b);
    }
    fin.close();
}

void saveBooks() {
    ofstream fout("books.dat");
    for (auto& b : books) {
        fout << b.bno << '\n' << b.bname << '\n' << b.aname << '\n';
    }
    fout.close();
}

void loadStudents() {
    students.clear();
    ifstream fin("students.dat");
    while (fin) {
        Student s;
        getline(fin, s.admno);
        if (s.admno.empty()) break;
        getline(fin, s.name);
        fin >> s.token; fin.ignore();
        getline(fin, s.stbno);
        students.push_back(s);
    }
    fin.close();
}

void saveStudents() {
    ofstream fout("students.dat");
    for (auto& s : students) {
        fout << s.admno << '\n' << s.name << '\n' << s.token << '\n' << s.stbno << '\n';
    }
    fout.close();
}

// Book management
void addBook() {
    Book b;
    b.createBook();
    books.push_back(b);
    saveBooks();
    cout << "Book Added!\n";
}

void displayAllBooks() {
    cout << "\nAll Books:\n";
    for (auto& b : books) b.showBook();
}

void searchBook() {
    string bno;
    cout << "Enter Book No to search: ";
    cin >> bno;
    auto it = find_if(books.begin(), books.end(), [&](Book& b) { return b.bno == bno; });
    if (it != books.end()) it->showBook();
    else cout << "Book not found.\n";
}

void modifyBook() {
    string bno;
    cout << "Enter Book No to modify: ";
    cin >> bno;
    auto it = find_if(books.begin(), books.end(), [&](Book& b) { return b.bno == bno; });
    if (it != books.end()) {
        cout << "Enter new details:\n";
        it->createBook();
        saveBooks();
        cout << "Book modified!\n";
    } else cout << "Book not found.\n";
}

void deleteBook() {
    string bno;
    cout << "Enter Book No to delete: ";
    cin >> bno;
    auto it = remove_if(books.begin(), books.end(), [&](Book& b) { return b.bno == bno; });
    if (it != books.end()) {
        books.erase(it, books.end());
        saveBooks();
        cout << "Book deleted!\n";
    } else cout << "Book not found.\n";
}

// Student management
void addStudent() {
    Student s;
    s.createStudent();
    students.push_back(s);
    saveStudents();
    cout << "Student Added!\n";
}

void displayAllStudents() {
    cout << "\nAll Students:\n";
    for (auto& s : students) s.showStudent();
}

void searchStudent() {
    string admno;
    cout << "Enter USN to search: ";
    cin >> admno;
    auto it = find_if(students.begin(), students.end(), [&](Student& s) { return s.admno == admno; });
    if (it != students.end()) it->showStudent();
    else cout << "Student not found.\n";
}

void modifyStudent() {
    string admno;
    cout << "Enter USN to modify: ";
    cin >> admno;
    auto it = find_if(students.begin(), students.end(), [&](Student& s) { return s.admno == admno; });
    if (it != students.end()) {
        cout << "Enter new details:\n";
        it->createStudent();
        saveStudents();
        cout << "Student modified!\n";
    } else cout << "Student not found.\n";
}

void deleteStudent() {
    string admno;
    cout << "Enter USN to delete: ";
    cin >> admno;
    auto it = remove_if(students.begin(), students.end(), [&](Student& s) { return s.admno == admno; });
    if (it != students.end()) {
        students.erase(it, students.end());
        saveStudents();
        cout << "Student deleted!\n";
    } else cout << "Student not found.\n";
}

// Book issue/return
void bookIssue() {
    string admno, bno;
    cout << "Enter USN : ";
    cin >> admno;
    auto sit = find_if(students.begin(), students.end(), [&](Student& s) { return s.admno == admno; });
    if (sit == students.end()) {
        cout << "Student not found.\n";
        return;
    }
    if (sit->token == 1) {
        cout << "Student already has a book issued.\n";
        return;
    }

    cout << "Enter Book No to issue: ";
    cin >> bno;
    auto bit = find_if(books.begin(), books.end(), [&](Book& b) { return b.bno == bno; });
    if (bit == books.end()) {
        cout << "Book not found.\n";
        return;
    }

    sit->token = 1;
    sit->stbno = bno;
    saveStudents();
    cout << "Book issued successfully!\n";
}

void bookDeposit() {
    string admno;
    cout << "Enter USN : ";
    cin >> admno;
    auto sit = find_if(students.begin(), students.end(), [&](Student& s) { return s.admno == admno; });
    if (sit == students.end()) {
        cout << "Student not found.\n";
        return;
    }
    if (sit->token == 0) {
        cout << "No book issued to this student.\n";
        return;
    }

    int days;
    cout << "Enter number of days book was issued for: ";
    cin >> days;
    if (days > 15)
        cout << "Late return! Fine: Rs. " << (days - 15) * 1 << endl;

    sit->token = 0;
    sit->stbno = "";
    saveStudents();
    cout << "Book deposited successfully!\n";
}

// Main menu
void adminMenu() {
    while (true) {
        cout << "\n--- ADMIN MENU ---\n";
        cout << "1. Add Student\n2. Show All Students\n3. Search Student\n4. Modify Student\n5. Delete Student\n";
        cout << "6. Add Book\n7. Show All Books\n8. Search Book\n9. Modify Book\n10. Delete Book\n11. Back to Main Menu\n";
        cout << "Enter choice: ";
        int ch; cin >> ch;
        switch (ch) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6: addBook(); break;
            case 7: displayAllBooks(); break;
            case 8: searchBook(); break;
            case 9: modifyBook(); break;
            case 10: deleteBook(); break;
            case 11: return;
            default: cout << "Invalid choice!\n";
        }
    }
}

int main() {
    loadBooks();
    loadStudents();

    while (true) {
        cout << "\n--- LIBRARY MANAGEMENT SYSTEM ---\n";
        cout << "1. Book Issue\n2. Book Deposit\n3. Admin Menu\n4. Exit\nEnter choice: ";
        int ch; cin >> ch;
        switch (ch) {
            case 1: bookIssue(); break;
            case 2: bookDeposit(); break;
            case 3: adminMenu(); break;
            case 4: exit(0);
            default: cout << "Invalid choice!\n";
        }
    }
}

