#include "geometryCalculations.h"
#include "utilities.h"
#include <iostream>
#include <stdexcept>

using namespace std;


double calculateSquareArea(double side) {
    return side * side;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

void calculateFigureArea(int choice) {
    try {
        if (cin.fail()) {
            cin.clear(); // Czyszczenie flagi b³êdu strumienia.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Usuniecie pozostalosci ze strumienia wejscia
            throw invalid_argument("Wprowadzono niepoprawna wartosc."); // Wyjatek
        }

        if (choice < 1 || choice > 2) {
            throw invalid_argument("Niedozwolony wybor");
        }

        double area = 0.0;
        switch (choice) {
        case 1: {
            double side;
            cout << "Podaj dlugosc boku kwadratu: ";
            cin >> side;
            if (check(side)) {
                break;
            }
            area = calculateSquareArea(side);
            cout << "Pole kwadratu = " << area << endl;
            break;
        }
        case 2: {
            double length, width;
            cout << "Podaj dlugosc prostokata: ";
            cin >> length;
            if (check(length)) {
                break;
            }
            cout << "Podaj szerokosc prostokata: ";
            cin >> width;
            if (check(width)) {
                break;
            }
            area = calculateRectangleArea(length, width);
            cout << "Pole prostokata = " << area << endl;
            break;
        }
        default:
            cout << "Blednie wprowadzone dane!" << endl;
            break;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Blad: " << e.what() << endl;
        waitForEnter();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    waitForEnter();
}

void runGeometryCalculator(){

    while (true) {
        clearScreen();
        cout << "Obliczanie pol figury plaskiej" << endl;
        cout << "---------------------------" << endl;
        cout << "1.) Kwadrat" << endl;
        cout << "2.) Prostokat" << endl;
        cout << "3.) Wyjscie" << endl;
        cout << "\nWpisz cyfre od 1 - 3 co chcialbys obliczyc:" << endl;

        int choice;
        cin >> choice;
        if (choice == 3) {
            break;
        }
        calculateFigureArea(choice);
    }
}