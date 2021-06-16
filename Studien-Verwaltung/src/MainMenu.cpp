#include "MainMenu.hpp"
#include <iostream>
using namespace std;

MainMenu::MainMenu() {
    StudentMenu::readFromFile(); // Liest Datenbank aus
}

void MainMenu::showMainMenu() {
    int Set[] = { 7,7,7,7,7,7 }; // Standard Farbe = Weiß
    int counter = 1;
    char key;

    // Hauptschleife
    do {
        // Initiierung
        int matrikelnummer;
        system("cls");

        // Bedienoberfläche
        gotoxy(0, 0);
        color(Set[0]);
        cout << "1. Neuen Student erstellen";

        gotoxy(0, 1);
        color(Set[1]);
        cout << "2. Nach Student suchen";

        gotoxy(0, 2);
        color(Set[2]);
        cout << "3. Alle Studenten anzeigen";

        gotoxy(0, 3);
        color(Set[3]);
        cout << "4. Einen Studenten loeschen";

        gotoxy(0, 4);
        color(Set[4]);
        cout << "5. Einen Studenten bearbeiten";

        gotoxy(0, 5);
        color(Set[5]);
        cout << "6. Exit";

        key = _getch(); // nimmt einen char aus der Konsole und gibt ihn als int wieder
        if (key == 72 && counter > 1) { // 72 == key up
            counter--;
        }
        if (key == 80 && counter < 6) { // 80 == key down
            counter++;
        }
        if (key == '\r') {
            switch (counter) {
            case 1:
                system("cls");
                studentMenu.create_student();
                break;
            case 2:
                system("cls");
                cout << "Matrikelnummer eingeben: ";
                cin >> matrikelnummer;
                system("cls");
                studentMenu.display_student(matrikelnummer);
                break;
            case 3:
                system("cls");
                studentMenu.display_all();
                break;
            case 4:
                system("cls");
                cout << "Matrikelnummer eingeben: ";
                cin >> matrikelnummer;
                studentMenu.delete_student(matrikelnummer);
                break;
            case 5:
                system("cls");
                cout << "Matrikelnummer eingeben: ";
                cin >> matrikelnummer;
                studentMenu.change_student(matrikelnummer);
                break;
            case 6:
                char end;
                system("cls");
                cout << "Programm beenden?";
                color(7);
                cout << "\nY/N\n";
                cin >> end;
                if (end == 'Y' || end == 'y') {
                    system("cls");
                    color(2);
                    cout << "Das Programm wird jetzt beendet, danke fuer den Gebrauch unserer Software.";
                    color(7);
                    exit(0);
                }
                else {
                    system("cls");
                    color(12);
                    cout << "Beenden abgebrochen.";
                    color(7);
                    StudentMenu::waitForInput();
                }
                break;
            }
        }
        // Alle weiß setzen
        for (int i = 0; i < 6; ++i) {
            Set[i] = 7;
        }

        // ausgewähltes Element Lila setzen
        if (counter > 0 && counter < 7) {
            Set[counter - 1] = 13;
        }
        fflush(stdin);
    } while (1);
}

void MainMenu::gotoxy(int x, int y) {
    COORD c;    // COORD:   Defines the coordinates of a character cell in a console screen buffer. The origin of the coordinate system (0,0) is at the top, left cell of the buffer.   
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void MainMenu::color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


/* legacy code
void MainMenu::showMainMenu() {
    // Bedienoberfläche    
    cout << "===============MENU===============";
    cout << "\n1. Neuen Student erstellen";
    cout << "\n2. Nach Student suchen";
    cout << "\n3. Alle Studenten anzeigen";
    cout << "\n4. Einen Studenten loeschen";
    cout << "\n5. Einen Studenten bearbeiten";
    cout << "\n6. Exit";
    cout << "\n\nAuswahl ...";

    char auswahl;
    // Hauptschleife
    do {
        // Initiierung
        int matrikelnummer;
        system("cls");

        // Eingabe
        cin >> auswahl;
        system("cls");

        // Verarbeitung der Eingabe
        switch(auswahl) {
        case '1':
            system("cls");
            studentMenu.create_student();
            break;
        case '2':
            system("cls");
            cout << "Matrikelnummer eingeben: ";
            cin >> matrikelnummer;
            system("cls");
            studentMenu.display_student(matrikelnummer);
            break;
        case '3':
            system("cls");
            studentMenu.display_all();
            break;
        case '4':
            system("cls");
            cout << "Matrikelnummer eingeben: ";
            cin >> matrikelnummer;
            studentMenu.delete_student(matrikelnummer);
            break;
        case '5':
            system("cls");
            cout << "Matrikelnummer eingeben: ";
            cin >> matrikelnummer;
            studentMenu.change_student(matrikelnummer);
            break;
        case '6':
            cout << "Das Programm wird jetzt beendet, danke fuer den Gebrauch unserer Software.";
            exit(0);
        default:
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 == rot
            std::cout << "Ungueltige Eingabe, bitte erneute Anweisung eingeben!";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
        }

        // Warten auf erneute Bestätigung
        waitForInput();
    } while (auswahl != '6');
}
*/