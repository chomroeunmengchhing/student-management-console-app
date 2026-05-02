
#include "MenuUtils.hpp"
#include "ExcelUtils.hpp"
#include <tabulate/table.hpp>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace tabulate;

void printMenuAsTable(vector<string> menulist) {
    Table table;
    table.add_row({"Student Management Console App"});
    for (int i = 0; i < (int)menulist.size(); i++)
        table.add_row({menulist[i]});
    table[0].format()
        .font_style({FontStyle::bold})
        .font_align({FontAlign::center});
    cout << table << endl;
}

void printStudentAsTable(vector<Student> studentList) {
    Table table;
    table.add_row({"ID","Name","Gender","DateOfBirth","Email","Contact","Course","Score"});
    for (auto student : studentList) {
        table.add_row({
            to_string(student.getId()),
            student.getName(),
            student.getGender(),
            student.getDateOfBirth(),
            student.getEmail(),
            student.getContact(),
            student.getCourse(),
            to_string(student.getScore())
        });
    }
    table[0].format()
        .font_style({FontStyle::bold})
        .font_align({FontAlign::center});
    cout << table << endl;
}

void printLabel(string label) {
    Table table;
    table.add_row({label});
    table[0].format()
        .font_style({FontStyle::bold})
        .font_align({FontAlign::center});
    cout << table << endl;
}

void printLoginTable() {
    Table table;
    table.add_row({"LOGIN SYSTEM"});
    table.add_row({"Enter your username and password"});
    table[0].format()
        .font_style({FontStyle::bold})
        .font_align({FontAlign::center});
    cout << table << endl;
}

void pressEnter() {
    cout << "-----Press Enter to continue-----" << endl;
    cin.ignore();
    cin.get();
}

bool isIdExist(const vector<Student>& list, int id) {
    return any_of(list.begin(), list.end(),
        [&](const Student& s){ return s.getId() == id; });
}

bool isUsernameExist(const vector<User>& users, const string& username) {
    for (auto& u : users)
        if (u.getUsername() == username) return true;
    return false;
}

User* login(vector<User>& users) {
    string username, password;
    printLoginTable();
    cout << "Please enter Username: "; cin >> username;
    cout << "Please enter Password: "; cin >> password;
    for (auto& user : users)
        if (user.getUsername() == username &&
            user.getPassword() == password)
            return &user;
    return nullptr;
}

void registerUser(vector<User>& users, const string& filename) {
    string username, password, role;
    printLabel("REGISTER NEW USER");
    do {
        cout<<"Enter username: ";cin>>username;
        if (isUsernameExist(users, username))
            cout<<"Username already taken! Please try another."<<endl;
    } while(isUsernameExist(users, username));
    cout<<"Enter password: "; cin>>password;
    do{
        cout<<"Enter role (teacher/student): ";cin>>role;
        if(role != "teacher" && role != "student")
            cout<<"Invalid! Enter teacher or student."<<endl;
    }while(role != "teacher" && role != "student");
    users.push_back(User(username, password, role));
    writeUsersToExcel(filename, users);
    cout<<"Registered successfully! You can now login."<<endl;
}