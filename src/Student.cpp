#include "Student.hpp"
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

Student::Student(int id, string name, string gender, string email,
                 string course, float score, string contact, string dateOfBirth) {
    this->id          = id;
    this->name        = name;
    this->gender      = gender;
    this->email       = email;
    this->course      = course;
    this->score       = score;
    this->contact     = contact;
    this->dateOfBirth = dateOfBirth;
}

void Student::input() {
    cout << "Enter student Name: ";
    getline(cin, name);

    do {
        cout << "Enter student Gender (F/M): ";
        cin >> gender;
        if (gender.length() == 1) gender[0] = toupper(gender[0]);
        if (gender != "F" && gender != "M")
            cout << "Invalid input. Please enter F or M only." << endl;
    } while (gender != "F" && gender != "M");

    do {
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        cin >> dateOfBirth;
        if (dateOfBirth.length() != 10 ||
            dateOfBirth[2] != '/' || dateOfBirth[5] != '/') {
            cout << "Invalid format! Use DD/MM/YYYY." << endl;
            continue;
        }
        int day   = stoi(dateOfBirth.substr(0, 2));
        int month = stoi(dateOfBirth.substr(3, 2));
        int year  = stoi(dateOfBirth.substr(6, 4));
        if (day < 1 || day > 31) {
            cout << "Invalid day! Must be 01-31." << endl; continue;
        }
        if (month < 1 || month > 12) {
            cout << "Invalid month! Must be 01-12." << endl; continue;
        }
        if (year < 1900 || year > 2010) {
            cout << "Invalid year! Must be 1900-2010." << endl; continue;
        }
        break;
    } while (true);

    bool valid;
    do {
        cout << "Enter student Email: ";
        cin >> email;
        valid = true;
        if (count(email.begin(), email.end(), '@') != 1) valid = false;
        int atPos  = email.find('@');
        int dotPos = email.find('.', atPos);
        if (atPos <= 0 || dotPos == (int)string::npos ||
            dotPos <= atPos + 1 || dotPos == (int)email.length() - 1)
            valid = false;
        if (!valid) cout << "Invalid email format." << endl;
    } while (!valid);

    do {
        cout << "Enter student Contact (7 digits): ";
        cin >> contact;
        if (contact.length() != 7) {
            cout << "Must be exactly 7 digits!" << endl; continue;
        }
        if (!all_of(contact.begin(), contact.end(), ::isdigit)) {
            cout << "Numbers only!" << endl; continue;
        }
        break;
    } while (true);

    do {
        cout << "Enter student Course (Math/Physics): ";
        cin >> course;
        if (course != "Math" && course != "Physics")
            cout << "Invalid! Enter Math or Physics." << endl;
    } while (course != "Math" && course != "Physics");

    do {
        cout << "Enter student Score (0-100): ";
        cin >> score;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            continue;
        }
        if (score < 0 || score > 100)
            cout << "Score must be 0-100." << endl;
    } while (score < 0 || score > 100);
}

void Student::update() {
    cin.ignore();
    cout << "Enter student Name: "; getline(cin, name);

    do {
        cout << "Enter Gender (F/M): ";
        cin >> gender;
        if (gender != "F" && gender != "M")
            cout << "Invalid! Enter F or M." << endl;
    } while (gender != "F" && gender != "M");

    do {
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        cin >> dateOfBirth;
        if (dateOfBirth.length() != 10 ||
            dateOfBirth[2] != '/' || dateOfBirth[5] != '/') {
            cout << "Invalid format!" << endl; continue;
        }
        int day   = stoi(dateOfBirth.substr(0, 2));
        int month = stoi(dateOfBirth.substr(3, 2));
        int year  = stoi(dateOfBirth.substr(6, 4));
        if (day < 1 || day > 31 || month < 1 || month > 12 ||
            year < 1900 || year > 2010) {
            cout << "Invalid date!" << endl; continue;
        }
        break;
    } while (true);

    cout << "Enter Email: "; cin >> email;

    do {
        cout << "Enter Contact (7 digits): ";
        cin >> contact;
        if (contact.length() != 7 ||
            !all_of(contact.begin(), contact.end(), ::isdigit)) {
            cout << "Must be exactly 7 digits!" << endl; continue;
        }
        break;
    } while (true);

    do {
        cout << "Enter Course (Math/Physics): ";
        cin >> course;
        if (course != "Math" && course != "Physics")
            cout << "Invalid!" << endl;
    } while (course != "Math" && course != "Physics");

    do {
        cout << "Enter Score (0-100): ";
        cin >> score;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid!" << endl; continue;
        }
        if (score < 0 || score > 100)
            cout << "Score must be 0-100." << endl;
    } while (score < 0 || score > 100);
}

void Student::output() {
    cout << "ID:            " << id          << endl;
    cout << "Name:          " << name        << endl;
    cout << "Gender:        " << gender      << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
    cout << "Email:         " << email       << endl;
    cout << "Contact:       " << contact     << endl;
    cout << "Course:        " << course      << endl;
    cout << "Score:         " << score       << endl;
}
