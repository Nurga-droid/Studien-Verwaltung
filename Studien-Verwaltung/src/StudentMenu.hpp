#pragma once
#include "StudentData.hpp"
#include <conio.h>
#include <Windows.h>

class StudentMenu
{
public:
    // public Methoden
    void create_student();                              // Studenten anlegen
    void display_student(int studentNumber) const;      // Nach Student suchen
    void display_all() const;                           // Alle Studenten anzeigen
    void delete_student(int studentNumber);             // Speziefischen Studenten löschen
    void change_student(int studentNumber);             // Speziefischen Studenten bearbeiten

    static void readFromFile();
    static void updateData();
    static void waitForInput();                         // Hält Program an, bis der Nutzer etwas tut

private:
    // private Methoden
    StudentData readData();                             // Input des Nutzers
    void showData(const StudentData &data) const;       // Anzeigen der Daten

    static void clearFile();                            // Löschen des txt-Dokuments
    static void writeToFile(const StudentData& data);   // Übertragen aller Daten des Containers auf das txt-Dokument
};