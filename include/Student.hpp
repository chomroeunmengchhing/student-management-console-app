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
    std::string getName(){return name;}
    std::string getGender(){return gender;}
    std::string getEmail(){return email;}
    std::string getDateOfBirth(){return dateOfBirth;}
    std::string getContact(){return contact;}
    std::string getCourse(){return course;}
    float       getScore(){return score;}
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