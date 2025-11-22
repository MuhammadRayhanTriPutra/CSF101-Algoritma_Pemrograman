#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    float nilai_akhir;
};

void inputDataMahasiswa(Mahasiswa &mhs) {

    cout <<"==========Masukan Data Mahasiswa==========" << endl;
    cout << "Masukan Nama: ";
    cin >> mhs.nama;
    cout << "Masukan Nilai: ";
    cin >> mhs.nilai_akhir;
    cout << " " << endl;

    cin.ignore();
};

void outputDataMahasiswa(Mahasiswa &mhs) {

    cout << "Nilai rata-rata kelas adalah: " << mhs.nilai_akhir;
};

int main() {
    Mahasiswa mhs;
    float nilaiAkhir;

    for (int i = 1;i <= 5;i++) {
        inputDataMahasiswa(mhs);
        nilaiAkhir += mhs.nilai_akhir;
    }
    cout << "==========Tampilkan Nilai Rata-rata Kelas==========" << endl;
    cout << (nilaiAkhir/5);

    return 0;
}