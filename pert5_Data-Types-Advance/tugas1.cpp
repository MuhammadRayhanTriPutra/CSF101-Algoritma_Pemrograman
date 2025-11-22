#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float nilai;
};

int main() {
    Mahasiswa mhs1;

    cout << "==========Data Mahasiswa Yang Sudah Di Isi==========" << endl;
    mhs1.nama = "Muhammad Rayhan Tri Putra";
    cout << "Nama: " << mhs1.nama << endl;
    mhs1.nim = "NIM: 20250801080";
    cout << mhs1.nim << endl;
    mhs1.nilai = 88.8;
    cout << "Nilai: " << mhs1.nilai << endl;
    cout << "=====================================================";    

    return 0;
}