#pragma once

#include "vector.hh"
#include<fstream>
#include "lacze_do_gnuplota.hh"

class rectangle
{
private:
    Vector a;
    Vector b;
    Vector c;
    Vector d;
public:
    rectangle();
    rectangle(Vector const &wsp_a_X, Vector const &wsp_b_X, Vector const &wsp_c_X, Vector const &wsp_d_X);
    rectangle translacja(Vector const &przesun) const;
    rectangle rotacja(const double &kat) const;

    void stworz_prost () const;
    bool sprawdz_boki () const;

    friend bool operator ==(const rectangle &a1, const rectangle &b1);

    friend std::ostream &operator << (std::ostream &out, rectangle const &tmp1);
};


rectangle::rectangle()
{
    double arg1[2] = {0, 0}, arg2[2] = {0, 0}, arg3[2] = {0, 0}, arg4[2] = {0, 0};
    a = Vector(arg1);
    b = Vector(arg2);
    c = Vector(arg3);
    d = Vector(arg4);
}
rectangle::rectangle(Vector const &wsp_a_X, Vector const &wsp_b_X, Vector const &wsp_c_X, Vector const &wsp_d_X)
{
    a = wsp_a_X;
    b = wsp_b_X;
    c = wsp_c_X;
    d = wsp_d_X;
    rectangle przyklad;
    przyklad = *this;
}
rectangle rectangle::translacja(Vector const &przesun) const
{
    rectangle przesuniecie;
    przesuniecie.a = a + przesun;
    przesuniecie.b = b + przesun;
    przesuniecie.c = c + przesun;
    przesuniecie.d = d + przesun;
    return przesuniecie;

}
rectangle rectangle::rotacja(const double &kat) const
{
    rectangle obrocony;
    obrocony.a = a.rotacja(kat);
    obrocony.b = b.rotacja(kat);
    obrocony.c = c.rotacja(kat);
    obrocony.d = d.rotacja(kat);

    return obrocony;

}

bool rectangle::sprawdz_boki() const
{
    Vector bok_AB, bok_BC, bok_CD, bok_DA;
    bok_AB = b - a;
    bok_BC = c - b;
    bok_CD = d - c;
    bok_DA = a - d;

    if ( (bok_AB.dl_boku() == bok_CD.dl_boku()) && (bok_BC.dl_boku() == bok_DA.dl_boku()))
    {
        return true;
    }
    return false;
    
}

std::ostream &operator << (std::ostream &out, rectangle const &tmp1) {
    out << tmp1.a<<std::endl;
    out << tmp1.b<<std::endl;
    out << tmp1.c<<std::endl;
    out << tmp1.d<<std::endl;
    out << tmp1.a<<std::endl;
    return out;
}
void rectangle::stworz_prost() const
{
    std::ofstream os("data.xy");
    if( !os.is_open())
    {
        throw std::invalid_argument("Plik sie nie otworzyl!.");
    }
    os << *this;

    PzG::LaczeDoGNUPlota plot;
    plot.DodajNazwePliku("data.xy");
    plot.UstawZakresX(-20,20);
    plot.UstawZakresY(-20, 20);
    plot.Inicjalizuj();
    plot.ZmienTrybRys(PzG::TR_2D);
    plot.Rysuj();
}
bool operator ==(const rectangle &a1, const rectangle &b1)
{
    if (a1.a == b1.a && a1.b == b1.b && a1.c == b1.c && a1.d == b1.d)
    {
        return true;
    }
    return false;
}

