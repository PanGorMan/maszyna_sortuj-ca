#include<iostream>
#include<vector>
#include <cstdlib> // losowanie
#include <ctime> // czas dla losowania
#include <locale> // dla polskich znaków

using namespace std;
int main()
{
    locale::global(locale("")); // dla uznania polskich znaków
    char odp;
    int liczba = 0;
    vector<int> pula_liczb = {};
    int min;
    int max;




    //pobieranie wartości

    cout << "ustaiwmy wartosci czy lasujemy  ? y/n \n";
    cin >> odp;
    if (odp == 'y') {

        while (true) {
            cout << "wpisz liczbę - liczba 0 kończy\n";
            cin >> liczba;

            if (liczba == 0) {
                break;
            }
            else {
                pula_liczb.push_back(liczba);

                for (int x : pula_liczb)
                    cout << x << " ";

                cout << "\n";
            }
        }
    }
    else if (odp == 'n') {
        cout << "Podaj przedział losowania liczb (tlko liczby całkowite) \n najmniejszą wartość :";
        cin >> min;
        cout << "Teraz największa\n";
        cin >> max;
        cout << "Teraz jak ma być długa lista \n";
        cin >> liczba;

        srand(time(0));

        for (int y = 1; y <= liczba; y++) {
            int wylosowana = rand() % (max - min + 1) + min;
            pula_liczb.push_back(wylosowana);
        }
        for (int x : pula_liczb)
            cout << x << " ";
    }
}