#include "macierze.h"

// konstruktor domyslny tworzy pusta macierz
macierz::macierz() {
    wiersze = 0;
    kolumny = 0;
    std::cout << "Utworzono pusta macierz " << std::endl;
}

// konstruktor inicjalizujacy macierz o podanym rozmiarze wypelniony podana wartoscia
macierz::macierz(int w, int k, double wartosc) {
    wiersze = w;
    kolumny = k;
    dane = std::vector<std::vector<double>>(w, std::vector<double>(k, wartosc));
    std::cout << "Utworzono macierz " << w << "x" << k << " wypelniona " << wartosc << std::endl;
}

// konstruktor przyjmujacy gotowy wektor
macierz::macierz(std::vector<std::vector<double>> &d)
    : wiersze(d.size()), kolumny(d.empty() ? 0 : d[0].size()), dane(d) {}

void macierz::wyswietl() {
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            std::cout << dane[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void macierz::transpozycja() {
    // zamieniamy wiersze z kolumnami
    for (int i = 0; i < wiersze; i++) {
        for (int j = i; j < kolumny; j++) {
            if (dane[i][j] != dane[j][i]) {
                auto temporary = dane[i][j];
                dane[i][j] = dane[j][i];
                dane[j][i] = temporary;
            }
        }
    }
}


int main() {
    std::vector<std::vector<double>> daneMacierzy = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };
    macierz m(daneMacierzy);
    m.wyswietl();
    m.transpozycja();
    m.wyswietl();

    return 0;
}