#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int increasingSequence(int N, vector<int>& sequence)
{
    vector<int> dp(N, 1);

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sequence[i] > sequence[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int Z;
    //cout << "Ile zestawow danych chcesz wprowadzic? (Zakres 1 - 25): ";
    cin >> Z;
    if (Z < 1 || Z > 25)
    {
        cout << "Bledne dane!" << endl;
        return 0;
    }

    for (int i = 0; i < Z; i++)
    {
        int N;
        //cout << "Podaj dlugosc ciagu wejsciowego: (N <= 200000)" << endl;
        cin >> N;

        if (N < 1 || N > 200000)
        {
            cout << "Bledne dane!" << endl;
            return 0;
        }

        vector<int> sequence(N);
        //cout << "Podaj zestaw liczb o dlugosci N, pojedyncza wartosc nie wieksza niz 10^9!" << endl;
        for (int j = 0; j < N; j++)
        {
            cin >> sequence[j];
            if (sequence[j] >= 1000000000)
            {
                cout << "Bledne dane!" << endl;
                return 0;
            }
        }


        int result = increasingSequence(N, sequence);
        cout << result << endl;
    }
    return 0;
}