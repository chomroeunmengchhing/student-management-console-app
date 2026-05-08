#pragma once
#include"Student.hpp"
#include<string>
#include<vector>
#include <tabulate/table.hpp>
using namespace tabulate;
using namespace std;
class User{
private:
    std::string username;
    std::string password;
    std::string role;
public:
    User(){}
    User(std::string u, std::string p, std::string r)
        : username(u), password(p), role(r){}
    std::string getUsername() const{return username;}
    std::string getPassword() const{return password;}
    std::string getRole()     const{return role;}
    std::string getPasswordHidden();
    void setUsername(std::string u){username = u;}
    void setPassword(std::string p){password = p;}
    void setRole    (std::string r){role= r;}
};
void printTranscript(const Student& s);
void  printMenuAsTable(std::vector<std::string> menulist);
void  printStudentAsTable(std::vector<Student> studentList);
void  printLabel(std::string label);
void  printLoginTable();
void  pressEnter();
bool  isIdExist(const std::vector<Student>& list, int id);
bool  isUsernameExist(const std::vector<User>& users, const std::string& username);
User*login(std::vector<User>& users);
void  registerUser(std::vector<User>& users, const std::string& filename);