
#include "ExcelUtils.hpp"
#include "MenuUtils.hpp"
#include <xlnt/xlnt.hpp>
#include <iostream>
using namespace std;
using namespace xlnt;

void writeVectorToExcel(const string& filename, vector<Student> studentList) {
    workbook wb;
    worksheet ws = wb.active_sheet();
    ws.title("Studentdata");
    ws.cell("A1").value("ID");
    ws.cell("B1").value("Name");
    ws.cell("C1").value("Gender");
    ws.cell("D1").value("DateOfBirth");
    ws.cell("E1").value("Email");
    ws.cell("F1").value("Contact");
    ws.cell("G1").value("Course");
    ws.cell("H1").value("Score");
    int row = 2;
    for (auto student : studentList) {
        ws.cell("A" + to_string(row)).value(to_string(student.getId()));
        ws.cell("B" + to_string(row)).value(student.getName());
        ws.cell("C" + to_string(row)).value(student.getGender());
        ws.cell("D" + to_string(row)).value(student.getDateOfBirth());
        ws.cell("E" + to_string(row)).value(student.getEmail());
        ws.cell("F" + to_string(row)).value(student.getContact());
        ws.cell("G" + to_string(row)).value(student.getCourse());
        ws.cell("H" + to_string(row)).value(to_string(student.getScore()));
        row++;
    }
    wb.save(filename);
    cout << "Successfully Saved Data to Excel file." << endl;
}

vector<Student> readStudentFromExcel(const string& filename) {
    vector<Student> studentList;
    workbook wb;
    try { wb.load(filename); }
    catch (...) {
        cout << "Unable to read data from file." << endl;
        return studentList;
    }
    worksheet ws = wb.active_sheet();
    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "ID") continue;
        int    id          = stoi(row[0].to_string());
        string name        = row[1].to_string();
        string gender      = row[2].to_string();
        string dateOfBirth = row[3].to_string();
        string email       = row[4].to_string();
        string contact     = row[5].to_string();
        string course      = row[6].to_string();
        float  score       = stof(row[7].to_string());
        studentList.push_back(
            Student(id, name, gender, email, course, score, contact, dateOfBirth)
        );
    }
    return studentList;
}

void writeUsersToExcel(const string& filename, const vector<User>& users) {
    workbook wb;
    worksheet ws = wb.active_sheet();
    ws.title("Users");
    ws.cell("A1").value("Username");
    ws.cell("B1").value("Password");
    ws.cell("C1").value("Role");
    int row = 2;
    for (auto& u : users) {
        ws.cell("A" + to_string(row)).value(u.getUsername());
        ws.cell("B" + to_string(row)).value(u.getPassword());
        ws.cell("C" + to_string(row)).value(u.getRole());
        row++;
    }
    wb.save(filename);
    cout << "User data saved." << endl;
}

vector<User> readUsersFromExcel(const string& filename) {
    vector<User> users;
    workbook wb;
    try { wb.load(filename); }
    catch (...) { return users; }
    worksheet ws = wb.active_sheet();
    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "Username") continue;
        users.push_back(User(
            row[0].to_string(),
            row[1].to_string(),
            row[2].to_string()
        ));
    }
    return users;
}