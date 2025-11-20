#include <iostream>
using namespace std;

struct Alamat {
    string kota;
    string provinsi;
};

struct Mahasiswa {
    string nama;
    string nim;
    Alamat alamat;
};

void isiDataMahasiswa(Mahasiswa &mhs) {
    cout << "Masukan Nama: ";
    cin >> mhs.nama;

    cout << "Masukan NIM: ";
    cin >> mhs.nim;

    cin.ignore();
};

void isiDataAlamat(Mahasiswa &mhs) {
    cout << "Masukan Alamat Kota: ";
    cin >> mhs.alamat.kota;

    cout << "Masukan Alamat Provinsi: ";
    cin >> mhs.alamat.provinsi;

    cin.ignore();
};

int main() {
    Mahasiswa mhs;

    cout << "==========Mengisi Data Mahasiswa==========" << endl;
    isiDataMahasiswa(mhs);

    cout << "==========Mengisi Data Alamat==========" << endl;
    isiDataAlamat(mhs);

    cout << "==========Data Mahasiswa yang sudah di Isi==========" << endl;
    cout << "Nama Mahasiswa: " << mhs.nama << endl;
    cout << "NIM Mahasiswa: " << mhs.nim << endl;
    cout << "Alamat Mahasiswa: " << "Kota " + mhs.alamat.kota + ", " + "Provinsi " + mhs.alamat.provinsi << endl;

    return 0;
}