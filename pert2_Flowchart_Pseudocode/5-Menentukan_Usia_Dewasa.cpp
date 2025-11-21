#include <iostream>
using namespace std;

int main() {
    int umur;

    cout << "Masukan umur anda: ";
    cin >> umur;

    if (umur >= 18) {
        cout << "Anda dewasa! Berumur: " << umur;
    } else {
        cout << "Anda belum dewasa!";
    }

    return 0;
}