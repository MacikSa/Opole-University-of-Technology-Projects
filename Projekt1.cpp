#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int maxShrinkingPieces = 8;
const int maxStretchingPieces = 8;

struct State {
    int position;                //Aktualna pozycja
    int cost;                    //koszt dotarcia do punktu docelowego
    int shrinkingPiecesUsed;     //Ilosc kawa³ków grzyba (-100)
    int stretchingPiecesUsed;    //Ilosc kawa³ków grzyba (*2)

    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int main() {
    int Z;
    //cout << "Ile testow chcialbys wykonac? (Zakres 1 - 100): ";
    cin >> Z;

    if (Z >= 1 && Z <= 100) {
        vector<int> eatenPieces(Z);

        //cout << "Wprowadz wartosci oddzielone spacja. Pierwsza wartosc, to wartosc startowa, druga, to wartosc ktora chcial(a)bys uzyskac: (Zakres 1 - 100000)" << endl;

        for (int i = 0; i < Z; ++i) {
            int x, y;
            cin >> x >> y;

            if (x >= 1 && y <= 100000) {
                priority_queue<State, vector<State>, greater<State>> pq;
                vector<vector<int>> visited(200001, vector<int>(maxShrinkingPieces + 1, 0));

                pq.push({ x, 0, 0, 0 });

                while (!pq.empty()) {
                    State current = pq.top();
                    pq.pop();

                    if (current.position == y) {
                        eatenPieces[i] = current.cost;
                        break;
                    }

                    if (visited[current.position][current.shrinkingPiecesUsed]) {
                        continue;
                    }

                    visited[current.position][current.shrinkingPiecesUsed] = 1;

                    // Zwiekszanie wzrostu
                    if (current.position * 2 <= 200000 && current.stretchingPiecesUsed < maxStretchingPieces) {
                        pq.push({ current.position * 2, current.cost + 1, current.shrinkingPiecesUsed, current.stretchingPiecesUsed + 1 });
                    }

                    // Zmniejszanie wzrostu
                    if (current.position >= 100 && current.shrinkingPiecesUsed < maxShrinkingPieces) {
                        pq.push({ current.position - 100, current.cost + 1, current.shrinkingPiecesUsed + 1, current.stretchingPiecesUsed });
                    }
                }
            }
            else {
                cout << "Wprowadzone dane sa niepoprawne!" << endl;
            }
        }

        for (int i = 0; i < Z; ++i) {
            if (eatenPieces[i] > 0) {
                cout << eatenPieces[i] << endl;
            }
            else {
                cout << "NIE" << endl;
            }
        }
    }
    return 0;
}