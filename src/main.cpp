#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <tabulate/table.hpp>
#include "MenuUtils.hpp"
#include "ExcelUtils.hpp"

using namespace std;
using namespace tabulate;

int main() {
    system("cls");

    string studentFile = "studentdata.xlsx";
    string userFile    = "userdata.xlsx";
    vector<string>menulist;
    vector<User> users = readUsersFromExcel(userFile);
    if (users.empty()) {
        users.push_back(User("admin", "admin123", "teacher"));
        writeUsersToExcel(userFile, users);
        cout << "First run! Default: admin / admin123" << endl;
    }

    bool running = true;
    while (running) {
        User* currentUser = nullptr;

        while (currentUser == nullptr) {
            Table authTable;
            authTable.add_row({"STUDENT MANAGEMENT SYSTEM"});
            authTable.add_row({"1. Login"});
            authTable.add_row({"2. Register"});
            authTable.add_row({"3. Exit"});
            authTable[0].format()
                .font_style({FontStyle::bold})
                .font_align({FontAlign::center});
            cout << authTable << endl;

            int authChoice;
            cout << "Please choose your option: ";
            cin >> authChoice;

            if (authChoice == 1) {
                currentUser = login(users);
                if (currentUser == nullptr)
                    cout << "Incorrect username or password." << endl;
            }
            else if (authChoice == 2) {
                registerUser(users, userFile);
            }
            else if (authChoice == 3) {
                running = false;
                break;
            }
            else {
                cout << "Invalid option!" << endl;
            }
        }

        if (!running) break;

        cout << "Welcome, " << currentUser->getUsername()
             << "! Role: "  << currentUser->getRole() << endl;

        vector<Student> studentList = readStudentFromExcel(studentFile);

        int option;
        do {
            if (currentUser->getRole() == "teacher") {
                printMenuAsTable({
                    "1. Add New Student Data",
                    "2. Update Student Data",
                    "3. Delete Student Data",
                    "4. Show all Student Data",
                    "5. Search Student Data",
                    "6. Sort Student Data",
                    "7. Logout"
                });
                cout << ">>>> Choose your option: ";
                cin >> option;

                switch(option) {
                    case 1: {
                        printLabel("Add New Student Data");
                        Student newStudent;
                        int id;
                        do {
                            cout << "Enter Student ID (4 digits): "; cin >> id;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Numbers only!" << endl; continue;
                            }
                            if (id < 1000 || id > 9999) {
                                cout << "Must be exactly 4 digits!" << endl; continue;
                            }
                            if (isIdExist(studentList, id))
                                cout << "ID already exists!" << endl;
                        } while (id < 1000 || id > 9999 || isIdExist(studentList, id));
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        newStudent.setId(id);
                        newStudent.input();
                        studentList.push_back(newStudent);
                        writeVectorToExcel(studentFile, studentList);
                        cout << "Successfully added student!" << endl;
                        break;
                    }
                    case 2: {
                        int studentId;
                        printLabel("Update Student Data");
                        cout << "Enter Student ID to update: "; cin >> studentId;
                        auto result = find_if(studentList.begin(), studentList.end(),
                            [&](Student s){ return s.getId() == studentId; });
                        if (result != studentList.end()) {
                            cout << "Student Found!" << endl;
                            result->update();
                            cout << "Successfully updated!" << endl;
                        } else {
                            cout << "Student ID " << studentId << " not found!" << endl;
                        }
                        writeVectorToExcel(studentFile, studentList);
                        pressEnter();
                        break;
                    }
                    case 3: {
                        int studentId;
                        printLabel("Delete Student Data");
                        cout << "Enter Student ID to delete: "; cin >> studentId;
                        auto result = find_if(studentList.begin(), studentList.end(),
                            [&](Student s){ return s.getId() == studentId; });
                        if (result != studentList.end()) {
                            char confirm;
                            cout << "Are you sure? (y/n): "; cin >> confirm;
                            if (confirm == 'y') {
                                studentList.erase(result);
                                cout << "Deleted successfully." << endl;
                            }
                        } else {
                            cout << "Student not found!" << endl;
                        }
                        writeVectorToExcel(studentFile, studentList);
                        pressEnter();
                        break;
                    }
                    case 4: {
                        printStudentAsTable(studentList);
                        pressEnter();
                        break;
                    }
                    case 5: {
                        int searchOption;
                        printLabel("Search Student Data");
                        cout << "1. Search by ID"      << endl;
                        cout << "2. Search by Name"    << endl;
                        cout << "3. Search by Contact" << endl;
                        cout << "Choose: "; cin >> searchOption;
                        switch(searchOption) {
                            case 1: {
                                int sid;
                                cout << "Enter Student ID: "; cin >> sid;
                                auto it = find_if(studentList.begin(), studentList.end(),
                                    [&](Student& s){ return s.getId() == sid; });
                                if (it != studentList.end()) it->output();
                                else cout << "Student not found." << endl;
                                break;
                            }
                            case 2: {
                                string sname;
                                cout << "Enter Student Name: "; cin >> sname;
                                auto it = find_if(studentList.begin(), studentList.end(),
                                    [&](Student& s){ return s.getName() == sname; });
                                if (it != studentList.end()) it->output();
                                else cout << "Student not found." << endl;
                                break;
                            }
                            case 3: {
                                string scontact;
                                cout << "Enter Contact: "; cin >> scontact;
                                auto it = find_if(studentList.begin(), studentList.end(),
                                    [&](Student& s){ return s.getContact() == scontact; });
                                if (it != studentList.end()) it->output();
                                else cout << "Student not found." << endl;
                                break;
                            }
                            default:
                                cout << "Invalid option!" << endl; break;
                        }
                        pressEnter();
                        break;
                    }
                    case 6: {
                        int sortOption;
                        printLabel("Sort Student Data");
                        cout << "1. Sort by ID (Ascending)"     << endl;
                        cout << "2. Sort by ID (Descending)"    << endl;
                        cout << "3. Sort by Score (Ascending)"  << endl;
                        cout << "4. Sort by Score (Descending)" << endl;
                        cout << "Choose: "; cin >> sortOption;
                        switch(sortOption) {
                            case 1:
                                sort(studentList.begin(), studentList.end(),
                                    [](Student a, Student b){ return a.getId() < b.getId(); });
                                cout << "Sorted by ID Ascending." << endl; break;
                            case 2:
                                sort(studentList.begin(), studentList.end(),
                                    [](Student a, Student b){ return a.getId() > b.getId(); });
                                cout << "Sorted by ID Descending." << endl; break;
                            case 3:
                                sort(studentList.begin(), studentList.end(),
                                    [](Student a, Student b){ return a.getScore() < b.getScore(); });
                                cout << "Sorted by Score Ascending." << endl; break;
                            case 4:
                                sort(studentList.begin(), studentList.end(),
                                    [](Student a, Student b){ return a.getScore() > b.getScore(); });
                                cout << "Sorted by Score Descending." << endl; break;
                            default:
                                cout << "Invalid option!" << endl; break;
                        }
                        writeVectorToExcel(studentFile, studentList);
                        printStudentAsTable(studentList);
                        pressEnter();
                        break;
                    }
                    case 7: {
                        cout << "Logged out successfully." << endl;
                        break;
                    }
                    default:
                        cout << "Invalid option! Choose 1-7." << endl;
                        break;
                }

            } else {
                printMenuAsTable({
                    "1. Show all Student Data",
                    "2. Search Student Data",
                    "3. Logout"
                });
                cout << ">>>> Choose your option: ";
                cin >> option;

                switch(option) {
                    case 1: {
                        printStudentAsTable(studentList);
                        pressEnter();
                        break;
                    }
                    case 2: {
                        int searchOption;
                        printLabel("Search Student Data");
                        cout << "1. Search by ID"      << endl;
                        cout << "2. Search by Name"    << endl;
                        cout << "3. Search by Contact" << endl;
                        cout << "Choose: "; cin >> searchOption;
                        switch(searchOption) {
                            case 1: {
                                int sid;
                                cout << "Enter Student ID: "; cin >> sid;
                                auto it = find_if(studentList.begin(), studentList.end(),
                                    [&](Student& s){ return s.getId() == sid; });
                                if (it != studentList.end()) it->output();
                                else cout << "Student not found." << endl;
                                break;
                            }
                            case 2: {
                                string sname;
                                cout << "Enter Student Name: "; cin >> sname;
                                auto it = find_if(studentList.begin(), studentList.end(),
                                    [&](Student& s){ return s.getName() == sname; });
                                if (it != studentList.end()) it->output();
                                else cout << "Student not found." << endl;
                                break;
                            }
                            case 3: {
                                string scontact;
                                cout << "Enter Contact: "; cin >> scontact;
                                auto it = find_if(studentList.begin(), studentList.end(),
                                    [&](Student& s){ return s.getContact() == scontact; });
                                if (it != studentList.end()) it->output();
                                else cout << "Student not found." << endl;
                                break;
                            }
                            default:
                                cout << "Invalid option!" << endl; break;
                        }
                        pressEnter();
                        break;
                    }
                    case 3: {
                        cout << "Logged out successfully." << endl;
                        option = 7;
                        break;
                    }
                    default:
                        cout << "Invalid option! Choose 1-3." << endl;
                        break;
                }
            }

        } while (option != 7);

    }

    return 0;
}