/* -----------------------------------------------------------------------------------
  - Projekt:  Hausarbeit (OOSP SS2021)
  - Author:	  Vincent Schmitt
  - z.Hd.:	  Prof. Dr. rer. nat. Peer Johannsen
  - Datum:		11/06/2021 - 13/06/2021
-------------------------------------------------------------------------------------
  - Dies ist das main der Studentischen Datenbank
  - Optionen sind:  - Studenten hinzufügen
                    - spezifischen Studenten anzeigen (über Matrikelnummer)
                    - alle Studenten anzeigen
                    - spezifischen Studenten löschen
                    - spezifischen Studenten bearbeiten
  - Daten werden in dem Dokument "Datenbank.txt gespeichert"
  - HINWEIS: Das Dokument "Datenbank.txt" darf unter keinen Umständen verändert werden
    da dies zu schweren Programfehlern führen könnte
-----------------------------------------------------------------------------------*/

#include "MainMenu.hpp"

int main() {
    MainMenu mainMenu;
    mainMenu.showMainMenu();
    return 0;
}