#include <iostream>
using namespace std;

int main() {
    enum jenisAkun {
        dosen,
        mahasiswa
    };

    jenisAkun tipe;

    cout << "Pilih jenis akun: \n1. Dosen\n2. Mahasiswa" << endl;
    
    int x;
    cin >> x;

    if (x == 1) {
        tipe = dosen;
        cout << "Anda memilih akun: " << tipe;
    } else if (x == 2) {
        tipe = mahasiswa;
        cout << "Anda memilih akun: " << tipe;
    } else {
        cout << "Invalid input";
        return 0;
    }

    return 0;
}