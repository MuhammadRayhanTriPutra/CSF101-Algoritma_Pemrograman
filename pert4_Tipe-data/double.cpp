#include <iostream>
using namespace std;

int main() {
    int x; // Bilangan bulat ke-1
    int y; // Bilangan bulat ke-2
    double r; // Bilangan desimal

    cout << "Masukan Bilangan Bulat Pertama: ";
    cin >> x;

    cout << "Masukan Bilangan Bulat Kedua: ";
    cin >> y;

    cout << "Masukan Bilangan Desimal: ";
    cin >> r;

    double hasil = (x/y/r);

    cout << "=====HASIL OPERASI=====" << endl;

    cout << "Hasil penjumlahan (+): " << (x+y+r) << endl;
    cout << "Hasil pengurangan (-): " << (x-y-r) << endl;
    cout << "Hasil perkalian (x): " << (x*y*r) << endl;
    cout << "Hasil pembagian (/): " << hasil << endl;

    return 0;
}