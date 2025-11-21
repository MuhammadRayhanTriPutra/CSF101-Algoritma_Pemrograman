#include <iostream>
using namespace std;

int main() {
    float nilai;

    cout << "Masukkan nilai ujian: ";
    cin >> nilai;

    if (nilai >= 60) {
        cout << "Anda Lulus!" << endl;
    } else {
        cout << "Anda Tidak Lulus." << endl;
    }

    return 0;
}
