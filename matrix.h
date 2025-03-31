#ifndef MACIERZE_H
#define MACIERZE_H

#include <iostream>
#include <vector>

class macierz {
    public:
        // KONSTRUKTORY
        macierz(); // konstruktor domyslny

        macierz(int w, int k, double wartosc); // konstruktor z rozmiarem i wartoscia 

        macierz(std::vector<std::vector<double>> &d); // konstruktor przyjmujący gotowy wektor

        // wyswietlanie macierzy dla testow
        void wyswietl();

        // TRANSPOZYCJA
        void transpozycja();

        // DODAWANIE 

        // ODEJMOWANIE

        // MNOZENIE

        // MNOZENIE ELEMENT-WISE

        // WYZNACZNIK
        double wyznacznik() const; // TO DO

    private:
        int wiersze, kolumny; // wiersze i kolumny macierzy 

        std::vector<std::vector<double>> dane; // macierz

};


#endif // MACIERZE_H