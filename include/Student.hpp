#pragma once
#include<string>
#include<vector>
class Student{
private:
    int id;
    std::string name;        
    std::string gender;
    std::string email;
    std::string course;
    std::string dateOfBirth;
    std::string contact;
    float       score;
public:
    Student() {}
    Student(int id, std::string name, std::string gender, std::string email,
            std::string course, float score, std::string contact, std::string dateOfBirth);
    // Getters
    int getId() const{return id;}
    std::string  getName() const{return name;}
    std::string  getGender() const{return gender;}
    std::string  getEmail() const{return email;}
    std::string  getDateOfBirth() const{return dateOfBirth;}
    std::string getContact() const {return contact;}
    std::string  getCourse() const{return course;}
    float        getScore() const{return score;}
    std::string getGrade()       const {
    if (score >= 90) return "A+";
    if (score >= 80) return "A";
    if (score >= 70) return "B";
    if (score >= 60) return "C";
    if (score >= 50) return "D";
    return "F";
}
std::string getStatus()      const {
    return score >= 50 ? "PASSED" : "FAILED";
}
    // Setters
    void setId(int i){id= i;}
    void setName(std::string n){name= n;}
    void setGender(std::string g){gender= g;}
    void setEmail(std::string e){email= e;}
    void setDateOfBirth(std::string d){dateOfBirth = d;}
    void setContact(std::string c){contact= c;}
    void setCourse(std::string c){course= c;}
    void setScore(float s){score= s;}

    void input();
    void update();
    void output();
};