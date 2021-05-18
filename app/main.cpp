// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

// #include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
// #include <iostream>

// #include "exampleConfig.h"
// #include "example.h"
// #include "vector.hh"
// #include "matrix.hh"
#include "rectangle.hh"
#include "../include/lacze_do_gnuplota.hh"
// using namespace std;
// int main() 
// {
//   char  Opcja;
//   PzG::LaczeDoGNUPlota  Lacze;
//   Lacze.DodajNazwePliku("data.xy");
//   Lacze.DodajNazwePliku("data.xy");
//   Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
//   Lacze.ZmienTrybRys(PzG::TR_2D);
//   Lacze.UstawZakresY(-5,35);
//   Lacze.UstawZakresX(-35,35);
//   Lacze.Rysuj(); 
   
//   cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
//   cin >> noskipws >> Opcja;
// }
  char wybor;
int main ()
{
       Vector przesuniecie;
       Vector a,b,c,d;
       a[0] = 0;
       a[1] = 0;
       b[0] = 3;
       b[1] = 0;
       c[0] = 3;
       c[1] = 3;
       d[0] = 0;
       d[1] = 3;
       

       rectangle rec(a, b ,c ,d);
       // rec.stworz_prost();
       // std:: cin.get();

       std::cout << "Aby wyswietlic menu wpisz m ...." <<std::endl;
       std::cout << "o - obrot prostokata o zadany kat" << std::endl;
       std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
       std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
       std::cout << "m - wyswietl menu" << std::endl;
       std::cout << "k - koniec dzialania programu" << std::endl;
       
       do 
       {   
              std:: cin >> wybor ;
              switch (wybor)
              {
              case 'o':
              std::cout << "Wybrales obrot prostokata o dany kat. Podaj jego miare w stopniach : " <<std::endl;
                     double kat;
                     std::cin >> kat;
                     rec = rec.rotacja(kat);
              
                     rec.stworz_prost();
              
                     std:: cin.get();
                  
                     break;
              case 'p':
              std::cout << "Wybrales przesuniecie prostokata o dany wektor. Podaj jego wspolrzedne : " <<std::endl;
                     int x,y;
                     std::cin >> x >> y;
                     przesuniecie[0] = x;
                     przesuniecie[1] = y;
                     rec = rec.translacja(przesuniecie);
              
                     rec.stworz_prost();
                     std:: cin.get();
                     // std:: cin.get();
                     break;
              case 'w':
                     std::cout << "Wybrales wyswietlenie wspolrzednych prostokata. Oto one : " <<std::endl << rec <<std::endl;
                     break;
              case 'm':
                     std::cout << "o - obrot prostokata o zadany kat" << std::endl;
                     std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
                     std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
                     std::cout << "m - wyswietl menu" << std::endl;
                     std::cout << "k - koniec dzialania programu" << std::endl;
                     break;
              case 'k':
                     std::cout << "Koniec programu. Zegnam ! " <<std::endl;
                     break;
              
              default:
                     break;
              }
       }while (wybor != 'k');
}
