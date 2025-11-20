#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukan Sebuah Angka: ";
    cin >> angka;

    if ((angka / 2) * 2 == angka) {
        cout << angka << " Angka Genap";
    } else {
        cout << angka << " Angka Ganjil";
    }

    return 0;    
}