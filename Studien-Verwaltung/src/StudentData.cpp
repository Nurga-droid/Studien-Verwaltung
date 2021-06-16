#include "StudentData.hpp"
#include <iostream>

// ---- Konstruktoren -------------------------------------------------------------------------------
  // Standard-Konstruktor
StudentData::StudentData() :
    studentNumber(-1), name(), facutly(), major(), state() {
}
  // Daten-Konstruktor
StudentData::StudentData(int _studentNumber, std::string _name, char _faculty, std::string _major, char _state) :
    studentNumber(_studentNumber), name(_name), facutly(_faculty), major(_major), state(_state) {
}

// ---- Setter -----------------------------------------------------------------------------------
void StudentData::setName(std::string _name) {
    name = _name;
}

void StudentData::setFacultly(char _faculty) {
    facutly = _faculty;
}

void StudentData::setMajor(std::string _major) {
    major = _major;
}

void StudentData::setState(char _state) {
    state = _state;
}

// ---- Getter -----------------------------------------------------------------------------------
int StudentData::getStudentNumber() const {
    return studentNumber;
}
std::string StudentData::getName() const {
    return name;
}
char StudentData::getFaculty() const {
    return facutly;
}
std::string StudentData::getMajor() const {
    return major;
}
char StudentData::getState() const {
    return state;
}

// ---- Globale Variable gStudentData ------------------------------------------------------------
std::vector<StudentData> gStudentData;