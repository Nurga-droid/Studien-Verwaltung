#include "StudentMenu.hpp"
#include <fstream> // In-/Output an txt
#include <iostream>

// ---- Private Methoden -----------------------------------------------------------------------------------

void StudentMenu::updateData() {
    clearFile(); // Lösche die Datenbank
    for (const auto& data : gStudentData) { // Lege die Datenbank ohne die gelöschte Person wieder an
        writeToFile(data);
    }
}

void StudentMenu::clearFile() {
    std::ofstream clearFile;
    clearFile.open("Datenbank.txt", std::ofstream::out | std::ofstream::trunc); // trunc-flag löscht den Inhalt beim öffenen
    clearFile.close();
}

void StudentMenu::writeToFile(const StudentData &data) {
    std::ofstream fileOut("Datenbank.txt", std::ios::app); // an diese Datei wird weitergegeben --> fStream
    if (fileOut.is_open()) {
        fileOut << "------------------------------";
        fileOut << "\n" << data.getStudentNumber();
        fileOut << "\n" << data.getName();
        fileOut << "\n" << data.getFaculty();
        fileOut << "\n" << data.getMajor();
        fileOut << "\n" << data.getState() << "\n";
        fileOut.close(); // fStream schließen
    }
}

void StudentMenu::readFromFile() {
    std::ifstream fileIn("Datenbank.txt", std::ios::app); // aus dieser Datei wird gelesen --> fStream
    if (fileIn.is_open()) {
        std::string line = "";
        std::getline(fileIn, line);
        while (line.compare("------------------------------") == 0) {
            std::getline(fileIn, line);
            int studentNumber = stoi(line);
            std::getline(fileIn, line);
            std::string name(line);
            std::getline(fileIn, line);
            char faculty = line[0];
            std::getline(fileIn, line);
            std::string major(line);
            std::getline(fileIn, line);
            char state = line[0];
            // gStudentData hinzufügen
            StudentData studentData(studentNumber, name, faculty, major, state);
            gStudentData.push_back(studentData);
            std::getline(fileIn, line);
        }
    }
    fileIn.close(); // fStream schließen
}

StudentData StudentMenu::readData() {
    // Matrikelnummer einlesen
    std::system("cls");
    std::cout << "Geben Sie die Matrikelnummer des Studenten an: ";
	int studentNumber;
    std::cin >> studentNumber;

    // Test ob Student schon existiert
    auto test = std::find_if(gStudentData.begin(), gStudentData.end(), [studentNumber](const StudentData& data) -> bool { return studentNumber == data.getStudentNumber(); });
    if (test != gStudentData.end()) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 == rot
        std::cout << "\nFehler! Student existiert bereits!";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
        return StudentData();
    }

    // Namen einlesen
    std::system("cls");
    std::cout << "Geben Sie den vollstaendigen Namen des Studenten in der Form [Vorname Nachname] an: ";
    char name[50];
    std::cin.ignore();
    std::cin.getline(name, 50);

    //Fakultät einlesen
    std::system("cls");
    std::cout << "Geben Sie die Fakultaet des Studenten an:";
    std::cout << "\n T = Technik";
    std::cout << "\n W = Wirtschaft";
    std::cout << "\n G = Gestaltung\n";
    bool check = false;
    char faculty;
    do {
        std::cin >> faculty;
        switch (faculty) {
            case 'T':
            case 'W':
            case 'G':
                check = true;
                break;
            default:
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 == rot
                std::cout << "Fehler beim einlesen der Fakultaet, bitte erneut eingeben: ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
                break;
        }
    } while (check != true);

    // Studiengang einlesen
    std::system("cls");
    std::cout << "Geben Sie den vollstaendigen Namen des Studiengangs an: ";
    std::cin.ignore();
    char major[50];
    std::cin.getline(major, 50);

    // Status einlesen
    std::system("cls");
    std::cout << "Geben Sie den Status des Studenten an.";
    std::cout << "\n\tA = Aktiv\n\tE = Exmatrikuliert\n";
    check = false;
    char state;
    do {
        std::cin >> state;
        switch (state) {
            case 'A':
            case 'E':
                check = true;
                break;
            default:
                std::system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 == rot
                std::cout << "Fehler beim einlesen des Status, bitte erneut eingeben.";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
                break;
        }
    } while (check != true);
    return StudentData(studentNumber, std::string(name), faculty, std::string(major), state);
}

void StudentMenu::showData(const StudentData &data) const { // const-Referenz um Kopiervorgänge zu verhindern --> Optimierung
    std::cout << "\nStudent: " << data.getName() << ", " << data.getStudentNumber();
    std::cout << "\nFakultaet: " << data.getFaculty();
    std::cout << "\nStudiengang: " << data.getMajor();
    std::cout << "\nStatus: " << data.getState();
    std::cout << "\n------------------------------";
}

void StudentMenu::waitForInput() {
    std::cout << "\nBeliebige Eigabe bestaetigen um fortzufahren.";
    _getch();
}


// ---- Public Methoden ------------------------------------------------------------------------------------

void StudentMenu::create_student() {
    StudentData studentData = readData(); // Abfrage der Daten des neu angelegten Studenten
    if (studentData.getStudentNumber() != -1) {
        writeToFile(StudentData(studentData));  // in Datenbank schreiben
        gStudentData.push_back(studentData);    // Abspeichern des Studenten im Container
    }
}

void StudentMenu::display_student(int studentNumber) const {
    std::cout << "=============AUSGABE=============";
    // Test ob Student im container existiert
    for (const auto &data : gStudentData) {
        if (data.getStudentNumber() == studentNumber) {
            showData(data);
            waitForInput();
            return;
        }
    }
    // Sonst: Student existiert nicht
    std::system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 == rot
    std::cout << "Fehler! Student existiert in der Datenbank nicht!";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
    waitForInput();
}

void StudentMenu::display_all() const {
    std::cout << "=============AUSGABE=============";
    for (auto &data : gStudentData)
    {
        showData(data);
    }
    waitForInput();
}

void StudentMenu::delete_student(int studentNumber) {
    std::system("cls");
    auto toErease = std::find_if(gStudentData.begin(), gStudentData.end(), [studentNumber](const StudentData& data) -> bool { return studentNumber == data.getStudentNumber(); });
    if (toErease != gStudentData.end()) {
        gStudentData.erase(toErease);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // 2 == grün
        std::cout << "Student wurde geloescht!";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
        updateData();
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 == rot
        std::cout << "Fehler! Student existiert in der Datenbank nicht!";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
    }
    waitForInput();
}

void StudentMenu::change_student(int studentNumber) {
    auto toChange = std::find_if(gStudentData.begin(), gStudentData.end(), [studentNumber](const StudentData& data) -> bool { return studentNumber == data.getStudentNumber(); });
    if (toChange == gStudentData.end()) {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 == rot
        std::cout << "Fehler! Student existiert in der Datenbank nicht!";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
        waitForInput();
        return;
    }

    // Abfrage welcher Wert geändert werden soll
    char auswahl;
    do {
        // Initiierung
        std::system("cls");

        // Bedienoberfläche
        std::cout << "==========BEARBEITEN==========";
        std::cout << "\n1. Name bearbeiten";
        std::cout << "\n2. Fakultaet bearbeiten";
        std::cout << "\n3. Studiengang bearbeiten";
        std::cout << "\n4. Status bearbeiten";
        std::cout << "\n5. Speichern und beenden";
        std::cout << "\n\nAuswahl ...";

        // Eingabe
        std::cin >> auswahl;
        std::system("cls");

        // Verarbeitung der Eingabe
        bool check0 = false;
        bool check1 = false;
        switch (auswahl) {
        case '1':
            system("cls");
            std::cout << "Geben Sie den neuen vollstaendigen neuen Namen des Studenten in der Form [Vorname Nachname] an: ";
            char _name[50];
            std::cin.ignore();
            std::cin.getline(_name, 50);
            toChange->setName(_name);
            break;
        case '2':
            system("cls");
            std::cout << "Geben Sie die neue Fakultaet des Studenten an:";
            std::cout << "\n T = Technik";
            std::cout << "\n W = Wirtschaft";
            std::cout << "\n G = Gestaltung\n";
            char _faculty;
            do {
                std::cin >> _faculty;
                switch (_faculty) {
                case 'T':
                case 'W':
                case 'G':
                    check0 = true;
                    break;
                default:
                    system("cls");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 == rot
                    std::cout << "Fehler beim einlesen der Fakultaet, bitte erneut eingeben: ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
                    break;
                }
            } while (check0 != true);
            toChange->setFacultly(_faculty);
            break;
        case '3':
            system("cls");
            std::cout << "Geben Sie den vollstaendigen neuen Namen des Studiengangs an: ";
            std::cin.ignore();
            char _major[50];
            std::cin.getline(_major, 50);
            toChange->setMajor(_major);
            break;
        case '4':
            std::system("cls");
            std::cout << "Geben Sie den neuen Status des Studenten an.";
            std::cout << "\n\tA = Aktiv\n\tE = Exmatrikuliert\n";
            char _state;
            do {
                std::cin >> _state;
                switch (_state) {
                case 'A':
                case 'E':
                    check1 = true;
                    break;
                default:
                    std::system("cls");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 == rot
                    std::cout << "\nFehler beim einlesen des Status, bitte erneut eingeben.";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
                    break;
                }
            } while (check1 != true);
            toChange->setState(_state);
            break;
        case '5':
            system("cls");
            return;
        default:
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 == rot
            std::cout << "Ungueltige Eingabe, bitte erneute Anweisung eingeben!";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 == weiß
        }
    } while (auswahl != '5');

    // Daten updaten
    updateData();
}