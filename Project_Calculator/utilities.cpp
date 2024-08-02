#include "utilities.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void sprawdzenie(const string& menu) {
    if (menu.length() != 1 || (menu[0] != '1' && menu[0] != '2' && menu[0] != '3' && menu[0] != '4')) {
        throw string("Niedozwolony znak");
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForEnter() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoruje wszystkie znaki do nowej linii
    cout << "Wcisnij enter aby kontynuowac" << endl;
    cin.get();
}

bool check(double a) {
    try {
        if (cin.fail()) {
            cin.clear(); // Czyszczenie flagi b³êdu strumienia.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Usuniecie pozostalosci ze strumienia wejscia
            throw invalid_argument("Wprowadzono niepoprawna wartosc."); // Wyjatek
        }
        else if (a <= 0) {
            throw invalid_argument("Niedozwolony znak");
        }
    }
    catch (const invalid_argument& e) {
        clearScreen();
        cout << "Blad: " << e.what() << endl;
        waitForEnter();
        clearScreen();
        return true; // Zwróæ true,jezeli wyst¹pi³ b³¹d
    }
    return false; // Zwróæ false, jezeli nie wyst¹pi³ b³¹d
}
