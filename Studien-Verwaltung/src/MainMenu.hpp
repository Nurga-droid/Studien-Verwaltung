#pragma once
#include "StudentMenu.hpp"
#include <conio.h>

class MainMenu {

public:
    // Konstruktor
    MainMenu();                  // Hier wird die Datenbank eingelesen

    // Methoden
    void showMainMenu();         // Zeigt das Menü an
private:
    StudentMenu studentMenu;
    void gotoxy(int x, int y);   // Auswahl im Menu
    void color(int color);       // Farbkodirung
};