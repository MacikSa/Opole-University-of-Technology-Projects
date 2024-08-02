#include "calculator.h"
#include "utilities.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>

using namespace std;

// Funkcja zwracaj¹ca priorytet operatora
int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Funkcja konwertuj¹ca wyra¿enie infix na wyra¿enie ONP (odwrotna notacja polska)
vector<string> infixToRPN(const string& expression) {
    stack<char> ops;   // Stos przechowuj¹cy operatory
    vector<string> output; // Wektor przechowuj¹cy wyjœciowe wyra¿enie ONP
    string number; // Zmienna przechowuj¹ca bie¿¹c¹ liczbê
    int parenthesesCount = 0; // Licznik nawiasów

    for (char token : expression) {
        if (isdigit(token) || token == '.') { // Sprawdzenie, czy token jest cyfr¹ lub kropk¹
            number += token; // Dodanie tokena do bie¿¹cej liczby
        }
        else {
            if (!number.empty()) { // Jeœli bie¿¹ca liczba nie jest pusta, dodaj j¹ do wyjœciowego wyra¿enia
                output.push_back(number);
                number.clear(); // Wyczyszczenie bie¿¹cej liczby
            }

            if (token == '(') { // Jeœli token jest lewym nawiasem, dodaj go na stos
                ops.push(token);
                parenthesesCount++; // Zwiêksz licznik nawiasów
            }
            else if (token == ')') { // Jeœli token jest prawym nawiasem
                while (!ops.empty() && ops.top() != '(') { // Dopóki stos nie jest pusty i na jego szczycie nie ma lewego nawiasu
                    output.push_back(string(1, ops.top())); // Dodaj operator na wierzcho³ku stosu do wyjœciowego wyra¿enia
                    ops.pop(); // Usuñ operator ze stosu
                }
                if (ops.empty()) {
                    throw string("Niezbalansowane nawiasy");
                }
                ops.pop();  // Usuñ lewy nawias ze stosu
                parenthesesCount--; // Zmniejsz licznik nawiasów
            }
            else if (token == '+' || token == '-' || token == '*' || token == '/') { // Jeœli token jest operatorem
                while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(token)) {
                    output.push_back(string(1, ops.top())); // Dopóki stos nie jest pusty i na jego szczycie jest operator o wy¿szym lub równym priorytecie
                    ops.pop(); // Dodaj operator na wierzcho³ku stosu do wyjœciowego wyra¿enia
                }
                ops.push(token); // Dodaj bie¿¹cy operator na stos
            }
            else if (!isspace(token)) {
                throw string("Niedozwolony znak w wyra¿eniu");
            }
        }
    }

    if (!number.empty()) { // Jeœli bie¿¹ca liczba nie jest pusta, dodaj j¹ do wyjœciowego wyra¿enia
        output.push_back(number);
    }

    while (!ops.empty()) { // Dopóki stos nie jest pusty
        if (ops.top() == '(') {
            throw string("Niezbalansowane nawiasy");
        }
        output.push_back(string(1, ops.top())); // Dodaj operator na wierzcho³ku stosu do wyjœciowego wyra¿enia
        ops.pop(); // Usuñ operator ze stosu
    }

    if (parenthesesCount != 0) {
        throw string("Niezbalansowane nawiasy");
    }

    return output; // Zwróæ wyjœciowe wyra¿enie ONP
}

// Funkcja obliczaj¹ca wartoœæ wyra¿enia RPN
double evaluateRPN(const vector<string>& rpn) {
    stack<double> values; // Stos przechowuj¹cy wartoœci

    for (const string& token : rpn) {
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) { 
            values.push(stod(token)); // Dodaj liczbê na stos
        }
        else { 
            double right = values.top(); values.pop(); // Pobierz prawy operand
            double left = values.top(); values.pop(); // Pobierz lewy operand

            switch (token[0]) { // Wykonaj odpowiedni¹ operacjê w zale¿noœci od operatora
            case '+': values.push(left + right); break;
            case '-': values.push(left - right); break;
            case '*': values.push(left * right); break;
            case '/': values.push(left / right); break;
            }
        }
    }

    return values.top(); 
}

// Funkcja uruchamiaj¹ca kalkulator
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