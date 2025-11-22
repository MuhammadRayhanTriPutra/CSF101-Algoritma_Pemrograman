#include <iostream>
using namespace std;

int main() {
    int angka;
    bool trueorfalse;

    cout << "Masukan angka: ";
    cin >> angka;

    if (angka % 2 == 0) {
        trueorfalse = true;
    } else {
        trueorfalse = false;
    }

    cout << "Apakah angka genap? " << trueorfalse;
}