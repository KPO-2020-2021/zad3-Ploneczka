#pragma once

#include "size.hh"
#include "matrix.hh"
#include <iostream>
#include <math.h>

class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double [SIZE]);

    Vector operator + (const Vector &v) const;

    Vector operator - (const Vector &v) const;

    Vector operator * (const double &tmp) const;

    Vector operator / (const double &tmp) const;

    friend Vector operator * (Matrix m1, Vector tmp);           // Operator mnożenia przez wektor

    friend bool operator == (Vector vec1, Vector vec2);
    const double &operator [] (int index) const;

    double &operator [] (int index);

    Vector rotacja(const double &kat) const;

    double dl_boku () const;

};

std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::istream &operator >> (std::istream &in, Vector &tmp);

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
Vector::Vector() {
    for (int i = 0; i < SIZE; i++) {
        size[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */

Vector::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        size[i] = tmp[i];
    }
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
Vector Vector::operator + (const Vector &v) const{
    Vector result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = size[i] + v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
Vector Vector::operator - (const Vector &v) const {
    Vector result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = size[i] - v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */

Vector Vector::operator * (const double &tmp) const {
    Vector result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = size[i] * tmp;
    }
    return result;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */

Vector Vector::operator / (const double &tmp)const{
    Vector result;

    for (int i = 0; i < SIZE; i++) {
        result[i] = size[i] / tmp;
    }

    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
const double &Vector::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        throw std::out_of_range("Error: Wektor jest poza zasiegiem!" );
    }
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
double &Vector::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
std::ostream &operator << (std::ostream &out, Vector const &tmp) {
    for (int i = 0; i < SIZE; i++) {
        out << tmp[i] << " ";
    }
    return out;
}
bool operator == (Vector vec1, Vector vec2)
{
    for(int i = 0; i< SIZE;i++)
    {
        if (abs(vec1[i] - vec2[i]) >MIN)
        {   
            return false;
        }
    }
    return true; 
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
std::istream &operator >> (std::istream &in, Vector &tmp) {
    for (int i = 0; i < SIZE; i++) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

Vector Vector::rotacja(const double &kat) const
{
    Vector obrocony;

    double kat_radiany = (M_PI *(kat) )/180;
    if (SIZE == 2)
    {
        double zmienna[][SIZE] = {{cos(kat_radiany), -sin(kat_radiany)}, {sin(kat_radiany), cos(kat_radiany)}};
        Matrix zmieniony(zmienna);
        obrocony = zmieniony * *this;
    }
    else
    {
        throw std::out_of_range("blad!.");
    }
    
    return obrocony;
}

/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector operator * (Matrix m1, Vector tmp) {
    Vector result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i] += m1(i,j) * tmp[j];
        }
    }
    return result;
}

double Vector::dl_boku() const
{
    double dlugosc = 0;
    for (int i= 0;i<SIZE; i++)
    {
        dlugosc += pow(size[i], 2);
    }
    return sqrt(dlugosc);
}