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
    int min = 99999999999; int max = 1;


    //pobieranie wartości
    while (true) {
        cout << "ustaiwmy wartosci czy lasujemy  ?\n u - ustawiamy \n l - losujemy\n";
        cin >> odp;
        while (true) {

            if (odp == 'u') {

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
                break;
            }
            else if (odp == 'l') {
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
                for (int x : pula_liczb) {
                    cout << x << " ";
                }
                break;
            }
            else {
                cout << "\nzła komenda :\nustaiwmy wartosci czy lasujemy  ?\n u - ustawiamy \n l - losujemy\n";
                cin >> odp;
            }

        }
        cout << "\n wybór sposobu sortowania : \n 1 - sortowanie bombelkowe \n 2 - sortowanie kubełkowe \n 3 - sortowanie przez wstawianie  \n";
        cin >> liczba;

        // właściwe losowanie

        while (true) {

            if (liczba == 1) {
                liczba = pula_liczb.size();
                min = 99999999999; max = 1;
                for (int i = 0; i < liczba; i++) {
                    if (pula_liczb[i] < min) min = pula_liczb[i];
                    if (pula_liczb[i] > max) max = pula_liczb[i];
                }
                for (int i = 0; i < liczba - 1; i++) {
                    for (int j = 0; j < liczba - 1 - i; j++) {
                        if (pula_liczb[j] > pula_liczb[j + 1]) {
                            swap(pula_liczb[j], pula_liczb[j + 1]);
                            for (int x : pula_liczb) {
                                cout << x << " ";
                            }
                            cout << " \n";
                        }
                    }
                }
                break;
            }

            else if (liczba == 2) {
                liczba = pula_liczb.size();

                for (int i = 0; i < liczba; i++) {
                    if (pula_liczb[i] < min) min = pula_liczb[i];
                    if (pula_liczb[i] > max) max = pula_liczb[i];
                }

                vector<vector<int>> lista_list(max - min + 1);


                for (int i = 0; i < liczba; i++) {
                    lista_list[(pula_liczb[i] - min)].push_back(pula_liczb[i]);
                }

                pula_liczb.clear();
                for (int i = 0; i < lista_list.size(); i++) {
                    for (int j = 0; j < lista_list[i].size(); j++) {
                        pula_liczb.push_back(lista_list[i][j]);
                    }
                }
                break;
            }

            else if (liczba == 3) {

                int zmienna_pomocnicza = 0;
                liczba = pula_liczb.size();
                int kolejnosc = 0;
                for (int i = 1; i < liczba - 1; i++) {
                    zmienna_pomocnicza = pula_liczb[i];
                    int j = i - 1;
                    for (j; (j >= 0 && pula_liczb[j] > zmienna_pomocnicza); j--) {
                        pula_liczb[j + 1] = pula_liczb[j];
                    }
                    pula_liczb[j + 1] = zmienna_pomocnicza;

                    for (int x : pula_liczb) cout << x << " ";
                    cout << "\n";
                }
                break;
            }

            else {
                cout << "\nzła komenda \n wybór sposobu sortowania : \n 1 - sortowanie bombelkowe \n 2 - sortowanie kubełkowe \n 3 - sortowanie przez wstawianie  \n";
                cin >> liczba;
            }
        }

        // ostateczne wypisanie wyniku

        cout << "\nPo sortowaniu:\n ";
        for (int x : pula_liczb) cout << x << " ";
        cout << "\nwartość najmniejsza = " << min << "\nwartość największa = " << max << "\n\n Zacząć od nowa czy zakończyć działanie programu ?\n r - restart \n k - konec\n";
        cin >> odp;
        while (true){
        if (odp == 'k') {
            exit(0);
        }
        else if (odp == 'r') {
            cout << "\n ZACZYNAMY OD NOWA \n";
            break; 
        }
        else {
            cout << "\n nie prawidłowa komenda\n r - restart \n k - konec\n ";
            cin >> odp;
        }
        }
    }
}