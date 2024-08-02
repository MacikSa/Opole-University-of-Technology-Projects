#include <iostream>
#include "utilities.h"
#include "calculator.h"
#include "geometryCalculations.h"
#include "solidGeometryCalculator.h"

using namespace std;

int main() {
    while (true) {
        clearScreen();
        cout << "Kalkulator" << endl;
        cout << "----------" << endl;
        cout << "1.) Kalkulator (+ - * /) " << endl;
        cout << "2.) Obliczanie pol figur plaskich" << endl;
        cout << "3.) Graniastoslupy i ostroslupy" << endl;
        cout << "4.) Wyjscie" << endl;
        cout << "\nWpisz cyfre od 1 - 4 co chcialbys dzisiaj liczyc:" << endl;

        string menu;
        cin >> menu;

        if (menu == "1") {
            runCalculator();
        }
        else if (menu == "2") {
            runGeometryCalculator();
        }
        else if (menu == "3") {
            runsolidGeometryCalculator();
        }
        else if (menu == "4") {
            clearScreen();
            cout << "-------------" << endl;
            cout << "Do zobaczenia" << endl;
            cout << "-------------" << endl;
            break;
        }
        try {
            sprawdzenie(menu);
        }
        catch (const string& msg) {
            clearScreen();
            cout << "Blad: " << msg << endl;
            waitForEnter();
            clearScreen();
        }
    }
    return 0;
}