
```bash
sudo apt install cmake -y  
mkdir build
cd build 
cmake .. 
cmake --build  . 
```
src/main.cpp src/Student.cpp src/ExcelUtils.cpp src/MenuUtils.cpp
```bash
just run 
just build 
```

- For working with window you can follow the guides video belows: 
```

- For working with window you can follow the guides video belows: 
1. https://www.youtube.com/watch?v=RWXjhBjU8wY
#include <iostream>
#include <tabulate/table.hpp>
#include <xlnt/xlnt.hpp>
#include <vector>
#include <algorithm>
#include<limits>
#include<cctype>
using namespace tabulate;
using namespace std;
using namespace xlnt;
class Student
{
private:
    int id; 
    string name;
    string gender;
    string email;
    string course;
    string dateOfBirth;
    string contact;
    float score;
public:
    Student(){}
    Student( int id, string name, string gender, string email, string course, float score, string contact, string dateOfBirth){
        this->id=id;
        this->name= name;
        this->gender= gender;
        this->score= score;
        this->contact= contact;
        this->email=email;
        this->course=course;
        this->dateOfBirth=dateOfBirth;
    }
    void input(){
    // Name
   // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter student Name: ";
    getline(cin, name);
    // Gender
    do{
        cout<<"Enter student Gender (F/M): ";cin >> gender;
        if(gender.length() == 1){
            gender[0] = toupper(gender[0]);
        }
        if(gender != "F" && gender != "M"){
            cout << " Invalid input. Please enter F or M only."<<endl;
        }
    }while(gender != "F" && gender != "M");
    // Date of Birth 
 do{
    cout<<"Enter Date of Birth (DD/MM/YYYY): ";cin>>dateOfBirth;
    if (dateOfBirth.length() != 10) {
        cout<<"Invalid format! Use DD/MM/YYYY."<<endl;
        continue;
    }
    if (dateOfBirth[2] != '/' || dateOfBirth[5] != '/') {
        cout<<"Invalid format! Use DD/MM/YYYY."<<endl;
        continue;
    }
    int day   = stoi(dateOfBirth.substr(0, 2));
    int month = stoi(dateOfBirth.substr(3, 2));
    int year  = stoi(dateOfBirth.substr(6, 4));
    if(day < 1 || day > 31){
        cout<<"Invalid day! Must be 01-31."<<endl;
        continue;
    }
    if(month < 1 || month > 12){
        cout<<"Invalid month! Must be 01-12."<<endl;
        continue;
    }
    if(year < 1900 || year > 2010){
        cout<<"Invalid year! Must be 1900-2010."<<endl;
        continue;
    }
    break;
}while(true);
    // Email 
    bool valid = true;
     do{
        cout<<"Enter student Email: ";cin>>email;
         valid = true;
        if(count(email.begin(), email.end(), '@') != 1){
            valid = false;
        }
        int atPos = email.find('@');
        int dotPos = email.find('.', atPos);
        if(atPos <= 0 || dotPos == string::npos || dotPos <= atPos + 1 || dotPos == email.length() - 1){
            valid = false;
        }
        if(!valid){
            cout<<"Invalid email format. Please Enter again."<<endl;
        }
    }while(!valid);
    // Contact
    do{
    cout<<"Enter student Contact (7 digits): ";cin>>contact;
    if(contact.length() != 7){
        cout<<"Contact must be exactly 7 digits!"<<endl;
        continue;
    }
    bool allDigits = true;
    for(char c : contact){
        if(!isdigit(c)){
            allDigits = false;
            break;
        }
    }
    if(!allDigits){
        cout<<"Contact must contain numbers only!"<<endl;
    }
}while(contact.length() != 7 || !all_of(contact.begin(), contact.end(), ::isdigit));
    // Course
    do {
        cout<<"Enter student Course(Math/Physics): ";
        cin>>course;
        if(course.length() == 1){
            course[0] = toupper(course[0]);
        }
        if(course != "Math" && course != "Physics"){
            cout<<" Invalid input. Please Enter Math or Physics"<<endl;
        }
    }while(course != "Math" && course != "Physics");
    // Score (0–100)
    do {
        cout<<"Enter student Score (0-100): ";cin>>score;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<" Invalid input. Please enter a number again."<<endl;
            continue;
        }
        if(score < 0 || score > 100){
            cout<<" Score must be between 0 and 100."<<endl;
        }
    } while(score < 0 || score > 100);
}
    void update(){
        cin.ignore();
                cout<<"Enter student Name: ";getline(cin,name);
                cout<<"Enter student gender(F/M): ";cin>>gender;
                 do {
                cout<<"Enter Date of Birth (DD/MM/YYYY): ";cin>>dateOfBirth;
        if (dateOfBirth.length() != 10 ||
            dateOfBirth[2] != '/'      ||
            dateOfBirth[5] != '/') {
            cout<<"Invalid format! Use DD/MM/YYYY."<<endl;
            continue;
        }
        int day   = stoi(dateOfBirth.substr(0, 2));
        int month = stoi(dateOfBirth.substr(3, 2));
        int year  = stoi(dateOfBirth.substr(6, 4));
        if(day < 1 || day > 31 ||
            month < 1 || month > 12 ||
            year < 1900 || year > 2010) {
            cout<<"Invalid date!"<<endl;
            continue;
        }
        break;
    }while(true);
                cout<<"Enter student Email: ";cin>>email; //how//
                cout<<"Enter student contact(7 digit): ";cin>>contact; // 7 digit
                cout<<"Enter student course(Math/Physics): ";cin>>course;  
                cout<<"Enter student score(0-100): ";cin>>score; //under 100
    }
    void output(){
                cout<<"ID: "<<id<<endl;
                cout<<"Name: "<<name<<endl;
                cout<<"Gender: "<<gender<<endl;
                cout<<"Date of birth: "<<dateOfBirth<<endl;
                cout<<"Email: "<<email<<endl;
                cout<<"Contact: "<<contact<<endl;
                cout<<"Course: "<<course<<endl;
                cout<<"Score: "<<score<<endl;
    }
    //getter and setter for all fields
int getId() const {return id;}
string getName(){return name;}
string getGender(){return gender;}
string getEmail(){return email;}
string getDateOfBirth(){return dateOfBirth;}
string getContact(){return contact;}
string getCourse(){return course;}
float getScore(){return score;}

void setId(int id){this->id=id;}
void setName(string name){this->name=name;}
void setGender(string gender){this->gender=gender;}
void setEmail(string email){this->email=email;}
void setDateOfBirth(string dateOfBirth){this->dateOfBirth=dateOfBirth;}
void setContact(string contact){this->contact=contact;}
void setCourse(string course){this->course=course;}
void setScore(float score){this->score=score;}
};
// relate to table
void printMenuAsTable(vector<string>menulist){
    Table table;
    table.add_row({"Student management Console App"});
    for(int i =0; i < menulist.size(); i++){
        table.add_row({menulist[i]});
    }
    table[0].format()
    .font_style({FontStyle::bold})
    .font_align({FontAlign::center});
    
            cout<<table<<endl;
}
void printStudentAsTable(vector<Student>studentList){
    Table table;
    table.add_row({"ID","Name","Gender","Email", "DateOfBirth", "Contact", "Course", "Score"});
    for(auto student: studentList){
        table.add_row({
            to_string(student.getId()),
            student.getName(),
            student.getGender(),
            student.getEmail(),
            student.getDateOfBirth(),
            student.getContact(),
            student.getCourse(),
            to_string(student.getScore())
        });
    }
    table[0].format()
            .font_style({FontStyle::bold})
            .font_align({FontAlign::center});
            cout<<table<<endl;
}
void printLabel(string label){
    Table table;
    table.add_row({label});
    table[0].format()
            .font_style({FontStyle::bold})
            .font_align({FontAlign::center});
            cout<<table<<endl;
}
void pressEnter(){
            cout<<"-----Press Enter to continue-----"<<endl;
    cin.ignore();
    cin.get();
}
void writeVectorToExcel(string filename, vector<Student> studentList){
workbook wb;
worksheet ws = wb.active_sheet();
ws.title("Studentdata");
// add header
ws.cell("A1").value("ID");
ws.cell("B1").value("Name");
ws.cell("C1").value("Gender");
ws.cell("D1").value("DateOfBirth");
ws.cell("E1").value("Email");
ws.cell("F1").value("Contact");
ws.cell("G1").value("Course");
ws.cell("H1").value("Score");
int row=2;
for(auto student: studentList){
ws.cell("A"+to_string(row)).value(to_string(student.getId()));
ws.cell("B"+to_string(row)).value(student.getName());
ws.cell("C"+to_string(row)).value(student.getGender());
ws.cell("D"+to_string(row)).value(student.getDateOfBirth());
ws.cell("E"+to_string(row)).value(student.getEmail());
ws.cell("F"+to_string(row)).value(student.getContact());
ws.cell("G"+to_string(row)).value(student.getCourse());
ws.cell("H"+to_string(row)).value(to_string(student.getScore()));
row++;
}
wb.save(filename);
        cout<<"Successfully Saved Data to Excel file."<<endl;
}
vector<Student> readStudentFromExcel(string&filename){
    vector<Student>studentList;
    workbook wb;
    try{
        wb.load(filename);
    }catch(...){
                cout<<"Unable to read the data from file"<<endl;
        return studentList;
    }
    worksheet ws= wb.active_sheet();
    for(auto row: ws.rows(false)){
        if(row[0].to_string()=="ID") continue;

        int id =stoi(row[0].to_string());
        string name=(row[1].to_string());
        string gender=(row[2].to_string());
        string dateOfbirth=(row[3].to_string());
        string email=(row[4].to_string());
        string contact=(row[5].to_string());
        string course=(row[6].to_string());
        float score=stof(row[7].to_string());
        studentList.push_back(Student(id, name, gender, email, course, score, contact, dateOfbirth));
    }
    return studentList;    
}
bool isIdExist(const vector<Student>& list, int id){
    return any_of(list.begin(), list.end(),
        [&](const Student& s){
            return s.getId() == id;
        });
}
class User{
private:
    string username;
    string password;
    string role;
public:
    User(){}
    User(string u, string p, string r){
        username = u;
        password = p;
        role     = r;
    }
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getRole()     const { return role;     }
    
    void setUsername(string u) { username = u; }
    void setPassword(string p) { password = p; }
    void setRole    (string r) { role     = r; }
};
void printLoginTable(){
    Table table;

    table.add_row({"LOGIN SYSTEM"});
    table.add_row({"Enter your username and password"});
    table.add_row({"Role: teacher / student"});
    table[0].format()
        .font_style({FontStyle::bold})
        .font_align({FontAlign::center});
    cout << table << endl;
}
User* login(vector<User>& users){
    string username, password;
    printLoginTable();
    cout<<"Please enter Username: ";cin>>username;
    cout<<"Please enter Password: ";cin>>password;
    for (auto &user : users){
        if (user.getUsername() == username && user.getPassword() == password){
            return &user;
        }
    }
    return nullptr;
}
bool isUsernameExist(const vector<User>& users, const string& username){
    for (auto& u : users){
        if (u.getUsername() == username){
            return true;
        }
    }
    return false;  
}
void writeUsersToExcel(const string& filename, const vector<User>& users){
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
    cout<<"User data saved to: "<<filename<<endl;
}
void registerUser(vector<User>& users, const string& filename){
    string username, password, role;
    printLabel("REGISTER NEW USER");
    // for unique username
    do {
        cout<<"Enter username: ";cin>>username;
        if (isUsernameExist(users, username)){
            cout<<"Username already taken! Please try another."<<endl;
        }
    } while (isUsernameExist(users, username));
    cout<<"Enter password: ";cin>>password;
    do {
        cout<<"Enter role (teacher/student): "; cin>>role;
        if (role != "teacher" && role != "student"){
            cout<<"Invalid! Enter teacher or student."<<endl;
        }
    } while (role != "teacher" && role != "student");
    users.push_back(User(username, password, role));
    writeUsersToExcel(filename, users);
    cout << "Registered successfully! You can now login."<<endl;
}
vector<User> readUsersFromExcel(const string& filename){
    vector<User> users;
    workbook wb;
    try {
        wb.load(filename);
    } catch (...){
        return users;
    }
    worksheet ws = wb.active_sheet();
    for (auto row : ws.rows(false)){
        if (row[0].to_string() == "Username") continue;
        string username = row[0].to_string();
        string password = row[1].to_string();
        string role     = row[2].to_string();
        users.push_back(User(username, password, role));
    }
    return users;
}
int main(){
    system("cls");
    string studentFile = "studentdata.xlsx";
    string userFile    = "userdata.xlsx";
    vector<User> users = readUsersFromExcel(userFile);
    if (users.empty()){
        users.push_back(User("admin", "admin123", "teacher"));
        writeUsersToExcel(userFile, users);
        cout << "First run! Default account created." <<endl;
        cout << "Username: admin | Password: admin123"<<endl<<endl;
    }
    bool running = true;
    while (running){
        User* currentUser = nullptr;
        while (currentUser == nullptr){
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
            cout<<"Please choose your option: ";
            cin>>authChoice;
            if(authChoice == 1){
                currentUser = login(users);
                if (currentUser == nullptr)
                    cout<<"Incorrect username or password. Please try again."<<endl;
            }
            else if(authChoice == 2){
                registerUser(users, userFile);
            }
            else if(authChoice == 0){
                running = false;   
                break;
            }
            else {
                cout<<"Invalid option!"<<endl;
            }
        }
        if (!running) break; 
            cout<<"Welcome, "<<currentUser->getUsername()
             <<"! Role: "<<currentUser->getRole()<<endl;

        vector<Student> studentList = readStudentFromExcel(studentFile);

        vector<string> menulist = {
            "1. Add New Student Data",
            "2. Update Student Data",
            "3. Delete Student Data",
            "4. Show all Student Data",
            "5. Search Student Data",
            "6. Sort Student Data",
            "7. Logout"           
        };
        int option;
    do {
    // ── Teacher menu ──
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
        cout<<">>>> Choose your option: ";
        cin>>option;
        switch(option){
            case 1: {
                printLabel("Add New Student Data");
                Student newStudent;
                int id;
                do {
                    cout<<"Enter student ID(4 digit): "; cin >> id;
                    if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Invalid input! Please enter numbers only."<<endl;
                continue;
            }
            if (id < 1000 || id > 9999) {
            cout<<"ID must be exactly 4 digits! Please enter again."<<endl;
            continue;
        }
            if (isIdExist(studentList, id))
                cout<<"ID already exists! Please try another ID."<<endl;
                } while(id < 1000 || id > 9999 || isIdExist(studentList, id));
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                newStudent.setId(id);
                newStudent.input();
                studentList.push_back(newStudent);
                writeVectorToExcel(studentFile, studentList);
                cout<<"Successfully added student!"<<endl;
                break;
            }
            case 2: {
                int studentId;
                printLabel("Update Student Data");
                cout<<"Enter Student ID to update: "; cin>>studentId;
                auto result = find_if(studentList.begin(), studentList.end(),
                    [&](Student s){ return s.getId() == studentId; });
                if (result != studentList.end()) {
                    cout<<"Student Found"<<endl;
                    result->update();
                    cout<<"Successfully updated!"<<endl;
                } else {
                    cout<<"Student ID " <<studentId<<" not found!"<<endl;
                }
                writeVectorToExcel(studentFile, studentList);
                pressEnter();
                break;
            }
            case 3: {
                int studentId;
                printLabel("Delete Student Data");
                cout<<"Enter Student ID to delete: "; cin>>studentId;
                auto result = find_if(studentList.begin(), studentList.end(),
                    [&](Student s){ return s.getId() == studentId; });
                if (result != studentList.end()) {
                    char confirm;
                    cout<<"Are you sure? (y/n): "; cin>>confirm;
                    if (confirm == 'y') {
                        studentList.erase(result);
                        cout<<"Deleted successfully."<<endl;
                    }
                } else {
                    cout<<"Student not found!"<<endl;
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
                cout<<"1. Search by ID"<<endl;
                cout<<"2. Search by Name"<<endl;
                cout<<"3. Search by Contact"<<endl;
                cout<<"Choose your optoin to search: ";cin>>searchOption;
                switch(searchOption){
                    case 1: {
                        int id;
                        cout<<"Enter Student ID: ";cin>>id;
                        auto it = find_if(studentList.begin(), studentList.end(),
                            [&](Student& s){ return s.getId() == id; });
                        if (it != studentList.end()) { it->output(); }
                        else cout<<"Student not found."<<endl;
                        break;
                    }
                    case 2: {
                        string name;
                        cout<<"Enter Student Name: ";cin>>name;
                        auto it = find_if(studentList.begin(), studentList.end(),
                            [&](Student& s){ return s.getName() == name; });
                        if (it != studentList.end()) { it->output(); }
                        else cout<<"Student not found."<<endl;
                        break;
                    }
                    case 3: {
                        string contact;
                        cout<<"Enter Student Contact: ";cin>>contact;
                        auto it = find_if(studentList.begin(), studentList.end(),
                            [&](Student& s){ return s.getContact() == contact; });
                        if (it != studentList.end()) { it->output(); }
                        else cout<<"Student not found."<<endl;
                        break;
                    }
                    default:
                        cout<<"Invalid option!"<<endl;
                        break;
                }
                pressEnter();
                break;
            }
            case 6: {
                int sortOption;
                printLabel("Sort Student Data");
                cout<<"1. Sort by ID (Ascending)"<<endl;
                cout<<"2. Sort by ID (Descending)"<<endl;
                cout<<"3. Sort by Score (Ascending)"<<endl;
                cout<<"4. Sort by Score (Descending)"<<endl;
                cout<<"Please choose your option to sort: ";cin>>sortOption;
                switch(sortOption){
                    case 1:
                        sort(studentList.begin(), studentList.end(),
                            [](Student a, Student b){ return a.getId() < b.getId(); });
                        cout<<"Sorted by ID Ascending."<<endl; break;
                    case 2:
                        sort(studentList.begin(), studentList.end(),
                            [](Student a, Student b){ return a.getId() > b.getId(); });
                        cout<<"Sorted by ID Descending."<<endl; break;
                    case 3:
                        sort(studentList.begin(), studentList.end(),
                            [](Student a, Student b){ return a.getScore() < b.getScore(); });
                        cout<<"Sorted by Score Ascending."<<endl; break;
                    case 4:
                        sort(studentList.begin(), studentList.end(),
                            [](Student a, Student b){ return a.getScore() > b.getScore(); });
                        cout<<"Sorted by Score Descending."<<endl; break;
                    default:
                        cout<<"Invalid option!"<<endl; break;
                }
                writeVectorToExcel(studentFile, studentList);
                printStudentAsTable(studentList);
                pressEnter();
                break;
            }
            case 7: {
                cout<<"Logged out successfully."<<endl;
                break;
            }
            default:
                cout<<"Invalid option! Please choose from  1 to 7."<<endl;
                break;
        }

    // ── Student menu ──
    }else{
        printMenuAsTable({
            "1. Show all Student Data",
            "2. Search Student Data",
            "3. Logout"
        });
        cout<<">>>> Choose your option: ";
        cin>>option;

        switch(option){
            case 1: {
                printStudentAsTable(studentList);
                pressEnter();
                break;
            }
            case 2: {
                int searchOption;
                printLabel("Search Student Data");
                cout<<"1. Search by ID"<< endl;
                cout<<"2. Search by Name"<< endl;
                cout<<"3. Search by Contact"<< endl;
                cout<<"Please choose your option to search: "; cin>>searchOption;
                switch(searchOption){
                    case 1: {
                        int id;
                        cout<<"Enter Student ID: ";cin>>id;
                        auto it = find_if(studentList.begin(), studentList.end(),
                            [&](Student& s){ return s.getId() == id; });
                        if (it != studentList.end()) { it->output(); }
                        else cout<<"Student not found."<<endl;
                        break;
                    }
                    case 2: {
                        string name;
                        cout<<"Enter Student Name: ";cin>>name;
                        auto it = find_if(studentList.begin(), studentList.end(),
                            [&](Student& s){ return s.getName() == name; });
                        if (it != studentList.end()) { it->output(); }
                        else cout<<"Student not found."<<endl;
                        break;
                    }
                    case 3: {
                        string contact;
                        cout<<"Enter Contact: ";cin>>contact;
                        auto it = find_if(studentList.begin(), studentList.end(),
                            [&](Student& s){ return s.getContact() == contact; });
                        if (it != studentList.end()) { it->output(); }
                        else cout<<"Student not found."<<endl;
                        break;
                    }
                    default:
                     cout<<"Invalid option!"<<endl;
                        break;
                }
                pressEnter();
                break;
            }
            case 3: {
                cout<<"Logged out successfully."<<endl;
                option = 7;
                break;
            }
            default:
                cout<<"Invalid option! Please choose from 1-3."<<endl;
                break;
        }
    }
}while(option != 7);
    return 0;
}
}
