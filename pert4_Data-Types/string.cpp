#include <iostream>
using namespace std;

int main() {
    string namadepan, namabelakang;

    cout << "Masukan nama depan: ";
    getline(cin, namadepan);

    cout << "Masukan nama belakang: ";
    getline(cin, namabelakang);

    cout << "\nHalo, " + namadepan + " " + namabelakang + "!" + "Selamat belajar algoritma.";

    return 0;
}