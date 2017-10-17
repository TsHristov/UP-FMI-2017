// УП-практикум, спец.Информатика, 6-та група, Седмица 2
// Пример за проблем при типовете данни, когато от един тип преобразуваме към друг.
#include <iostream>
using namespace std;

int main()
{
  // Ако имаме signed int отрицателно число (4 байта) и искаме да вземем същото число,
  // само че неотрицателно, може би ще пробваме да го
  // присвоим на unsigned int променлива (cъщо 4 байта), това обаче
  // не работи както се очаква:
  signed int signed_number = -5;
  cout << "signed_number value: " << signed_number << "\n";
  unsigned int unsigned_number = signed_number; // Какво ще се случи тук?
  cout << "unsigned_number value: " << unsigned_number << "  Ooops!\n";

  // Тук обаче няма да имаме проблем, защо?:
  signed_number = 0;
  cout << "signed_number value: " << signed_number << "\n";
  unsigned_number = signed_number; // Какво ще се случи тук?
  cout << "unsigned_number value: " << unsigned_number << "\n";

  return 0;
}