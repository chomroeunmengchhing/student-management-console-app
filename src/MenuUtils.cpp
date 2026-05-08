#include "MenuUtils.hpp"
#include "ExcelUtils.hpp"
#include <tabulate/table.hpp>
#include <iostream>
#include <algorithm>
#include <conio.h>  
using namespace std;
//using namespace tabulate;
void printMenuAsTable(const vector<string> menulist){
    Table table;
    table.add_row({"Student Management Console App"});
    for (int i = 0; i < (int)menulist.size(); i++)
        table.add_row({menulist[i]});
    table[0].format()
        .font_style({FontStyle::bold})
        .font_align({FontAlign::center})
        .font_color({Color::blue});
        cout<<table<<endl; 
}
void printStudentAsTable(const vector<Student> studentList){
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
        .font_align({FontAlign::center})
        .font_color(Color::red);
        for(size_t i = 1; i < table.size(); i++){
        if(i % 2 == 0){
            table[i].format()
                .font_color(Color::yellow);
        }else{
            table[i].format()
                .font_color(Color::cyan);
        }
    }
    cout<<table<<endl;   
}
void printLabel(string label){
    Table table;
    table.add_row({label});
    table[0].format()
        .font_style({FontStyle::bold})
        .font_align({FontAlign::center})
        .font_color(Color::blue);
        cout<<table<<endl;    
}
void printLoginTable(){
    Table table;
    table.add_row({"LOGIN SYSTEM"});
    table.add_row({"Enter your username and password"});
    table[0].format()
        .font_style({FontStyle::bold})
        .font_align({FontAlign::center})
        .font_color(Color::red);
        table[1].format()
        .font_align({FontAlign::center})
        .font_color(Color::white);
        cout<<table<<endl; 
}
void pressEnter(){
    cout << "-----Press Enter to continue-----"<<endl;
    cin.ignore();
    cin.get();
}
void printTranscript(const Student& s) {
    system("cls");
    cout<<"\n";
    cout<<"\033[36m";
    cout<<"+========================================+\n";
    cout<<"|          STUDENT TRANSCRIPT            |\n";
    cout<<"|       Student Management System        |\n";
    cout<<"+========================================+\n";
    cout<<"\033[0m\n";
    Table t;
    t.add_row({"Field", "Details"});
    t.add_row({"Student ID",to_string(s.getId())});
    t.add_row({"Full Name",s.getName()});
    t.add_row({"Gender",s.getGender()});
    t.add_row({"Date of Birth",s.getDateOfBirth()});
    t.add_row({"Email",s.getEmail()});
    t.add_row({"Contact",s.getContact()});
    t.add_row({"Course",s.getCourse()});
    t.add_row({"Score",to_string(s.getScore())});
    t[0].format()
        .font_style({FontStyle::bold})
        .font_color(Color::cyan);
    for(size_t i = 1; i < t.size(); i++){
        t[i].format().font_color(Color::white);
    }
    cout<<t<<"\n";
    cout<<"\033[36m  +========================================+\n\033[0m";
    string grade  = s.getGrade();
    string status = s.getStatus();
    cout<<"  |  Grade  :  ";
    if(grade == "A+" || grade == "A")
        cout<<"\033[32m"<<grade<<"\033[0m";
    else if(grade == "B" || grade == "C")
        cout<<"\033[33m"<<grade<<"\033[0m";
    else
        cout<<"\033[31m"<<grade<<"\033[0m";
    cout<<"                              |\n";

    cout<<"  |  Status :  ";
    if(status == "PASSED")
        cout<<"\033[32m"<<status<<"\033[0m";
    else
        cout<<"\033[31m"<<status<<"\033[0m";
    cout<<"                              |\n";

    cout<<"\033[36m+========================================+\n\033[0m";
    cout<<"\n";
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
std::string getPasswordHidden(){
    string password = "";
    char ch;
    while((ch = _getch()) != '\r'){  
        if(ch == '\b'){              
            if(!password.empty()){
                password.pop_back();
                cout<<"\b \b";       
            }
        }else{
            password += ch;
            cout<<"*";               
        }
    }
    cout<<"\n";
    return password;
}

User* login(vector<User>& users) {
    string username, password;
    printLoginTable();
    cout<<"Please enter Username: "; cin>>username;
    cout<<"Please enter Password: "; password = getPasswordHidden();
    for (auto& user : users)
        if (user.getUsername() == username &&
            user.getPassword() == password)
            return &user;
    return nullptr;
}

void registerUser(vector<User>& users, const string& filename){
    string username, password, role;
    printLabel("REGISTER NEW USER");
    do {
        cout<<"Enter username: ";cin>>username;
        if (isUsernameExist(users, username))
            cout<<"Username already taken! Please try another."<<endl;
    } while(isUsernameExist(users, username));
    cout<<"Enter password: ";  password = getPasswordHidden();
    do{
        cout<<"Enter role (teacher/student): ";cin>>role;
        if(role != "teacher" && role != "student")
            cout<<"Invalid! Enter teacher or student."<<endl;
    }while(role != "teacher" && role != "student");
    users.push_back(User(username, password, role));
    writeUsersToExcel(filename, users);
    cout<<"[+] Registered successfully! You can now login."<<endl;
}