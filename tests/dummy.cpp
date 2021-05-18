#include "../tests/doctest/doctest.h"
#include "example.h"
#include "vector.hh"
#include <sstream>
#include "rectangle.hh"
// Tests that don't naturally fit in the headers/.cpp files directly
// can be placed in a tests/*.cpp file. Integration tests are a good example.

TEST_CASE("konskruktor domyslny")
{
  Vector v1,v2;
  v2[0]=0;
  v2[1]=0;
  CHECK_EQ(v1, v2);
}
TEST_CASE("konskruktor parametryczny")
{
  double a[2] = {1,1};
  Vector v1(a),v2;
  v2[0]=1;
  v2[1]=1;
  
  CHECK_EQ(v1, v2);
}
TEST_CASE("dodawanie")
{
  Vector v1,v2,v3;
  v1[0]=3;
  v1[1]=2;
  v2[0]=6;
  v2[1]=4;
  v3[0]=9;
  v3[1]=6;
  
  CHECK_EQ(v1+v2, v3);
}
TEST_CASE("mnozenie")
{
  Vector v1,v2;
  v1[0]=1;
  v1[1]=5;
  v2[0]=2;
  v2[1]=10;

  CHECK_EQ(v1*2, v2);
}
TEST_CASE("dzielenie")
{
  Vector v1,v2;
  v1[0]=6;
  v1[1]=4;
  v2[0]=3;
  v2[1]=2;

  CHECK_EQ(v1/2, v2);
}
TEST_CASE("odejmowanie")
{
  Vector v1,v2,v3;
  v1[0]=3;
  v1[1]=2;
  v2[0]=1;
  v2[1]=4;
  v3[0]=2;
  v3[1]=-2;
  
  CHECK_EQ(v1-v2, v3);
}
TEST_CASE("miejsca po przecinku")
{
  Vector v1,v2;
  v1[0]=3;
  v1[1]=2.7548945;
  v2[0]=3;
  v2[1]=2.7548945;
  
  CHECK_EQ(v1, v2);
}
TEST_CASE("<<")
{
  std::stringstream ss;
  Vector a1;
  ss << a1;
  
  CHECK_EQ(ss.str(), "0 0 ");
}
TEST_CASE(">>")
{
  std::stringstream ss;
  Vector a1, a2;
  ss<<"1 1 ";
  ss >> a1;
  a2[0]= 1;
  a2[1] = 1;
  
  CHECK_EQ(a1, a2);
}
TEST_CASE("indeks")
{
  Vector a1;
  a1[0] = 0;
  a1[1] = 3;
  CHECK_EQ(a1[1], 3);
}
TEST_CASE("poza indeks")
{
  Vector a1;
  a1[0] = 0;
  a1[1] = 3;
  WARN_THROWS(a1[2]);
}
TEST_CASE("indeks z consta")
{
  Vector a1;
  const double b = a1[0];
 
  CHECK_EQ(b, 0);
}
TEST_CASE("Macierz domyslny")
{
  Matrix m1,m2;
  m2(0,0) = 0;
  m2(0,1) = 0;
  m2(1,0) = 0;
  m2(1,1) = 0;
  CHECK_EQ(m1, m2);
}
TEST_CASE("Macierz parametryczna")
{
  double dwu[2][2];
  dwu[0][0] = 0;
  dwu[0][1] = 0;
  dwu[1][0] = 0;
  dwu[1][1] = 0;
  Matrix m1,m2(dwu);
  
  CHECK_EQ(m1, m2);
}
TEST_CASE("Macierz x Wektor")
{
  Matrix m1;
  Vector a1, wynik;
  wynik[0] = 7;
  wynik[1] = 9;
  a1[0] = 1;
  a1[1] = 3;
  m1(0,0) = 1;
  m1(0,1) = 2;
  m1(1,0) = 3;
  m1(1,1) = 2;
  CHECK_EQ(m1*a1, wynik);
}
TEST_CASE("Macierz indeks bez const")
{
  Matrix m1;
  m1(0,0) = 1;
  m1(0,1) = 2;
  m1(1,0) = 3;
  m1(1,1) = 2;
  CHECK_EQ(m1(1,0), 3);
}
TEST_CASE("Macierz indeks z consta")
{
  Matrix m1;
  const double b = m1(0,0);
 
  CHECK_EQ(b, 0);
}
TEST_CASE("Macierz obrotu")
{
  Vector a1,a2;
  a1[0]=1;
  a1[1]=1;
  a1 = a1.rotacja(180);
  a2[0]=-1;
  a2[1]=-1;
  CHECK_EQ(a1, a2);
}
TEST_CASE("Prostokat bez parametryczny")
{
  rectangle rec1, rec2;
  
  CHECK_EQ(rec1, rec2);
}
TEST_CASE("Prostokat  parametryczny")
{
  Vector ve1,ve2,ve3,ve4;
  rectangle rec1, rec2(ve1,ve2,ve3,ve4);
  
  CHECK_EQ(rec1, rec2);
}
TEST_CASE("Prostokat  translacja")
{
  Vector ve1,ve2,ve3,ve4, vek1, vek2, vek3, vek4, przesun;
  przesun[0]= 1;
  przesun[1]= 1;
  ve1[0] = 0;
  ve1[1] = 0;
  ve2[0] = 3;
  ve2[1] = 0;
  ve3[0] = 3;
  ve3[1] = 2;
  ve4[0] = 0;
  ve4[1] = 2;
  vek1[0] = 1;
  vek1[1] = 1;
  vek2[0] = 4;
  vek2[1] = 1;
  vek3[0] = 4;
  vek3[1] = 3;
  vek4[0] = 1;
  vek4[1] = 3;
  rectangle rec1(vek1,vek2,vek3,vek4), rec2(ve1+przesun, ve2+przesun, ve3+przesun, ve4+przesun);
  
  CHECK_EQ(rec1, rec2);
}
TEST_CASE("prostokat rotacja")
{
  Vector ve1,ve2,ve3,ve4, vek1, vek2, vek3, vek4;
  double kat = 180;
  ve1[0] = 0;
  ve1[1] = 0;
  ve2[0] = 3;
  ve2[1] = 0;
  ve3[0] = 3;
  ve3[1] = 3;
  ve4[0] = 0;
  ve4[1] = 3;
  vek1[0] = 0;
  vek1[1] = 0;
  vek2[0] = -3;
  vek2[1] = 0;
  vek3[0] = -3;
  vek3[1] = -3;
  vek4[0] = 0;
  vek4[1] = -3;
  rectangle rec(ve1,ve2,ve3,ve4), rec7(vek1, vek2, vek3, vek4);

  CHECK_EQ(rec.rotacja(kat), rec7);
}
TEST_CASE("prostokat rotacja, kat ujemny")
{
  Vector ve1,ve2,ve3,ve4, vek1, vek2, vek3, vek4;
  double kat = -90;
  ve1[0] = 0;
  ve1[1] = 0;
  ve2[0] = 3;
  ve2[1] = 0;
  ve3[0] = 3;
  ve3[1] = 3;
  ve4[0] = 0;
  ve4[1] = 3;
  vek1[0] = 0;
  vek1[1] = 0;
  vek2[0] = 0;
  vek2[1] = -3;
  vek3[0] = 3;
  vek3[1] = -3;
  vek4[0] = 3;
  vek4[1] = 0;
  rectangle rec(ve1,ve2,ve3,ve4), rec7(vek1, vek2, vek3, vek4);

  CHECK_EQ(rec.rotacja(kat), rec7);
}
TEST_CASE("nierowne boki prostokata")
{
  Vector vek1, vek2, vek3, vek4;
  vek1[0] = 0;
  vek1[1] = 0;
  vek2[0] = 2;
  vek2[1] = -3;
  vek3[0] =26;
  vek3[1] = -3;
  vek4[0] = 992;
  vek4[1] = 7;
  rectangle rec(vek1, vek2, vek3, vek4);
  CHECK_FALSE(rec.sprawdz_boki());
}
TEST_CASE("rowne boki prostokata")
{
  Vector vek1, vek2, vek3, vek4;
  vek1[0] = 0;
  vek1[1] = 0;
  vek2[0] = 3;
  vek2[1] = 0;
  vek3[0] = 3;
  vek3[1] = 2;
  vek4[0] = 0;
  vek4[1] = 2;
  rectangle rec(vek1, vek2, vek3, vek4);
  CHECK_FALSE(!rec.sprawdz_boki());
}