#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

void isiDataMahasiswa(Mahasiswa &mhs) {

    cout << "==========Mengisi Data Mahasiswa==========" << endl;
    cout << "Masukan Nama: ";
    cin >> mhs.nama;
    cout << "Masukan NIM: ";
    cin >> mhs.nim;
    cout << "Masukan IPK: ";
    cin >> mhs.ipk;

    cin.ignore();
};

void tampilDataMahasiswa(const Mahasiswa &mhs) {

    cout << "==========Tampilkan Data Mahasiswa==========" << endl;
    cout << "Nama Mahasiswa: " << mhs.nama << endl;
    cout << "NIM Mahasiswa: " << mhs.nim << endl;
    cout << "IPK Mahasiswa: " << mhs.ipk << endl;
    cout << " " << endl;
}
int main() {
    Mahasiswa mhs;

    for (int i = 1; i <= 2; i++) {
        isiDataMahasiswa(mhs);
        tampilDataMahasiswa(mhs);
    }
    cout << " " << endl;

    return 0;
}