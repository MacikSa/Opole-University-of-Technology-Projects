#include "calculator.h"
#include "utilities.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>

using namespace std;

// Funkcja zwracaj�ca priorytet operatora
int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Funkcja konwertuj�ca wyra�enie infix na wyra�enie ONP (odwrotna notacja polska)
vector<string> infixToRPN(const string& expression) {
    stack<char> ops;   // Stos przechowuj�cy operatory
    vector<string> output; // Wektor przechowuj�cy wyj�ciowe wyra�enie ONP
    string number; // Zmienna przechowuj�ca bie��c� liczb�
    int parenthesesCount = 0; // Licznik nawias�w

    for (char token : expression) {
        if (isdigit(token) || token == '.') { // Sprawdzenie, czy token jest cyfr� lub kropk�
            number += token; // Dodanie tokena do bie��cej liczby
        }
        else {
            if (!number.empty()) { // Je�li bie��ca liczba nie jest pusta, dodaj j� do wyj�ciowego wyra�enia
                output.push_back(number);
                number.clear(); // Wyczyszczenie bie��cej liczby
            }

            if (token == '(') { // Je�li token jest lewym nawiasem, dodaj go na stos
                ops.push(token);
                parenthesesCount++; // Zwi�ksz licznik nawias�w
            }
            else if (token == ')') { // Je�li token jest prawym nawiasem
                while (!ops.empty() && ops.top() != '(') { // Dop�ki stos nie jest pusty i na jego szczycie nie ma lewego nawiasu
                    output.push_back(string(1, ops.top())); // Dodaj operator na wierzcho�ku stosu do wyj�ciowego wyra�enia
                    ops.pop(); // Usu� operator ze stosu
                }
                if (ops.empty()) {
                    throw string("Niezbalansowane nawiasy");
                }
                ops.pop();  // Usu� lewy nawias ze stosu
                parenthesesCount--; // Zmniejsz licznik nawias�w
            }
            else if (token == '+' || token == '-' || token == '*' || token == '/') { // Je�li token jest operatorem
                while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(token)) {
                    output.push_back(string(1, ops.top())); // Dop�ki stos nie jest pusty i na jego szczycie jest operator o wy�szym lub r�wnym priorytecie
                    ops.pop(); // Dodaj operator na wierzcho�ku stosu do wyj�ciowego wyra�enia
                }
                ops.push(token); // Dodaj bie��cy operator na stos
            }
            else if (!isspace(token)) {
                throw string("Niedozwolony znak w wyra�eniu");
            }
        }
    }

    if (!number.empty()) { // Je�li bie��ca liczba nie jest pusta, dodaj j� do wyj�ciowego wyra�enia
        output.push_back(number);
    }

    while (!ops.empty()) { // Dop�ki stos nie jest pusty
        if (ops.top() == '(') {
            throw string("Niezbalansowane nawiasy");
        }
        output.push_back(string(1, ops.top())); // Dodaj operator na wierzcho�ku stosu do wyj�ciowego wyra�enia
        ops.pop(); // Usu� operator ze stosu
    }

    if (parenthesesCount != 0) {
        throw string("Niezbalansowane nawiasy");
    }

    return output; // Zwr�� wyj�ciowe wyra�enie ONP
}

// Funkcja obliczaj�ca warto�� wyra�enia RPN
double evaluateRPN(const vector<string>& rpn) {
    stack<double> values; // Stos przechowuj�cy warto�ci

    for (const string& token : rpn) {
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) { 
            values.push(stod(token)); // Dodaj liczb� na stos
        }
        else { 
            double right = values.top(); values.pop(); // Pobierz prawy operand
            double left = values.top(); values.pop(); // Pobierz lewy operand

            switch (token[0]) { // Wykonaj odpowiedni� operacj� w zale�no�ci od operatora
            case '+': values.push(left + right); break;
            case '-': values.push(left - right); break;
            case '*': values.push(left * right); break;
            case '/': values.push(left / right); break;
            }
        }
    }

    return values.top(); 
}

// Funkcja uruchamiaj�ca kalkulator
void runCalculator() {
    waitForEnter();
    clearScreen();
    string expression;
    cout << "Wprowadz wyrazenie matematyczne (lub 'Q' aby zakonczyc):\n ";

    while (getline(cin, expression)) { 
        if (expression == "Q" || expression == "q") break; 

        try {
            vector<string> rpn = infixToRPN(expression); //Konwertuje na ONP
            double result = evaluateRPN(rpn); // Obliczanie wyniku ONP
            cout << "Wynik: " << result << endl; 
        }
        catch (const string& e) {
            cout << "Blad: " << e << endl;
        }

        cout << "Wprowadz wyrazenie matematyczne (lub 'Q' aby zakonczyc): ";
    }
}