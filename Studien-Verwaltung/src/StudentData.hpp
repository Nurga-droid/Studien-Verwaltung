#pragma once
#include <vector>
#include <string>

class StudentData {
public:
    // Konstruktoren
    StudentData(); // Standard-Konstruktor --> liefert Matrikelnummer = -1
    StudentData(int studentNumber, std::string name, char faculty, std::string major, char state);  // Daten-Konstuktor

    // Setter
    void setName(std::string _name);
    void setFacultly(char _faculty);
    void setMajor(std::string _major);
    void setState(char _state);

    // Getter
    int getStudentNumber() const;
    std::string getName() const;
    char getFaculty() const;
    std::string getMajor() const;
    char getState() const;
private:
    // Member Daten
    int studentNumber;        // Matrikelnummer
    std::string name;         // Name
    char facutly;             // Fakultät
    std::string major;        // Studiengang
    char state;               // Status
};

extern std::vector<StudentData> gStudentData; // Globaler Container
