#pragma once
#include"Student.hpp"
#include<string>
#include<vector>
class User;
void                 writeVectorToExcel  (const std::string& filename, std::vector<Student> studentList);
std::vector<Student> readStudentFromExcel(const std::string& filename);
void                 writeUsersToExcel   (const std::string& filename, const std::vector<User>& users);
std::vector<User>    readUsersFromExcel  (const std::string& filename);