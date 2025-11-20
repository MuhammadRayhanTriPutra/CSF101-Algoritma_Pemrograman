#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs1, mhs2, mhs3;

    cout << "==========Mahasiswa 1==========" << endl;
    mhs1.nama = "Muhammad Rayhan Tri Putra";
    cout << "Nama: " << mhs1.nama << endl;
    mhs1.nim = "20250801080";
    cout << "NIM: " << mhs1.nim << endl;
    mhs1.ipk = 3.99;
    cout << "IPK: " << mhs1.ipk << endl;

    cout << "==========Mahasiswa 2==========" << endl;
    mhs2.nama = "Exsel Ramadhan";
    cout << "Nama: " << mhs2.nama << endl;
    mhs2.nim = "20250801081";
    cout << "NIM: " << mhs2.nim << endl;
    mhs2.ipk = 3.29;
    cout << "IPK: " << mhs2.ipk << endl;

    cout << "==========Mahasiswa 3==========" << endl;
    mhs3.nama = "Jehoshua Loka Putra";
    cout << "Nama: " << mhs3.nama << endl;
    mhs3.nim = "20250803030";
    cout << "NIM: " << mhs3.nim << endl;
    mhs3.ipk = 2.99;
    cout << "IPK: " << mhs3.ipk << endl;

    return 0;
}