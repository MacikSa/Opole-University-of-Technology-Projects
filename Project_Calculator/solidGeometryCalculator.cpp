#include "solidGeometryCalculator.h"
#include "geometryCalculations.h"
#include "utilities.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//objetosc graniastoslupa
void runcalculateGeometry() {
    cout << "Objetosc graniastoslupow:" << endl;
    cout << "1.) Graniastoslup o podstawie kwadratu" << endl;
	cout << "2.) Graniastoslup o podstawie prostokaata" << endl;
    cout << "3.) Wyjscie" << endl;
	cout << "\nWpisz cyfre od 1 - 2 co chcialbys obliczyc:" << endl;

	int choice_T;
	cin >> choice_T;
    try {
        if (cin.fail()) {
            cin.clear(); // Czyszczenie flagi b³êdu strumienia
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Usuniecie pozostalosci ze strumienia wejscia
            throw invalid_argument("Wprowadzono niepoprawna wartosc."); // Wyjatek
        }
        if (choice_T < 1 || choice_T > 3) {
            throw invalid_argument("Niedozwolony wybor");
        }

        switch (choice_T) {
        case 1: {
            double side, height;
            cout << "Graniastolup o podstawie kwadratu" << endl;
            cout << "Podaj dlugosc boku kwadratu: ";
            cin >> side;
            if (check(side)) break;

            cout << "Podaj wysokosc graniastoslupa: ";
            cin >> height;
            if (check(height)) break;

            double baseArea = calculateSquareArea(side);
            cout << "Objetosc graniastoslupa o podstawie kwadratu = " << baseArea * height << endl;
            waitForEnter();
            break;
        }
        case 2: {
            double length, width, height;
            cout << "Graniastolup o podstawie prostokata" << endl;
            cout << "Podaj dlugosc prostokata: ";
            cin >> length;
            if (check(length)) break;

            cout << "Podaj szerokosc prostokata: ";
            cin >> width;
            if (check(width)) break;

            cout << "Podaj wysokosc graniastoslupa: ";
            cin >> height;
            if (check(height)) break;

            double baseArea = calculateRectangleArea(length, width);
            cout << "Objetosc graniastoslupa o podstawie prostokata = " << baseArea * height << endl;
            waitForEnter();
            break;
        }
        case 3: {
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
}
//objetosc ostroslupa
void runcalculateGeo() {
    cout << "Objetosc ostroslupa:" << endl;
    cout << "1.) Ostroslup o podstawie kwadratu" << endl;
    cout << "2.) Ostroslup o podstawie prostokaata" << endl;
    cout << "3.) Wyjscie" << endl;
    cout << "\nWpisz cyfre od 1 - 2 co chcialbys obliczyc:" << endl;

    int choice_T;
    cin >> choice_T;
    try {
        if (cin.fail()) {
            cin.clear(); // Czyszczenie flagi b³êdu strumienia.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Usuniecie pozostalosci ze strumienia wejscia
            throw invalid_argument("Wprowadzono niepoprawna wartosc."); // Wyjatek
        }
        if (choice_T < 1 || choice_T > 3) {
            throw invalid_argument("Niedozwolony wybor");
        }

        switch (choice_T) {
        case 1: {
            double side, height;
            cout << "Ostroslup o podstawie kwadratu" << endl;
            cout << "Podaj dlugosc boku kwadratu: ";
            cin >> side;
            if (check(side)) break;

            cout << "Podaj wysokosc graniastoslupa: ";
            cin >> height;
            if (check(height)) break;

            double baseArea = calculateSquareArea(side);
            cout << "Objetosc ostroslupa o podstawie kwadratu = " << (baseArea * height)/3 << endl;
            waitForEnter();
            break;
        }
        case 2: {
            double length, width, height;
            cout << "Ostroslup o podstawie prostokata" << endl;
            cout << "Podaj dlugosc prostokata: ";
            cin >> length;
            if (check(length)) break;

            cout << "Podaj szerokosc prostokata: ";
            cin >> width;
            if (check(width)) break;

            cout << "Podaj wysokosc ostroslupa: ";
            cin >> height;
            if (check(height)) break;

            double baseArea = calculateRectangleArea(length, width);
            cout << "Objetosc ostroslupa o podstawie prostokata = " << (baseArea * height)/3 << endl;
            waitForEnter();
            break;
        }
        case 3: {
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
}

void runsolidGeometryCalculator() {

    while (true) {
        clearScreen();
        cout << "Obliczanie objetosci graniastoslupow i ostroslupow" << endl;
        cout << "---------------------------" << endl;
        cout << "1.) Objetosc graniastosupow" << endl;
        cout << "2.) Objetosc ostrosupow" << endl;
        cout << "3.) Wyjscie" << endl;
        cout << "\nWpisz cyfre od 1 - 3 co chcialbys obliczyc:" << endl;

        string choice;
        cin >> choice;
        if (choice == "1") {
            runcalculateGeometry();
        }
        else if (choice == "2") {
            runcalculateGeo();
        }
        else if (choice == "3")
        {
            break;
        }
        try {
            sprawdzenie(choice);
        }
        catch (const string& msg) {
            clearScreen();
            cout << "Blad: " << msg << endl;
            waitForEnter();
            clearScreen();
        }
    }
}