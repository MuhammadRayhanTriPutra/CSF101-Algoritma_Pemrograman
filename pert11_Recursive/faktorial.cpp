#include <iostream>
#include <string>
using namespace std;

void faktorial_Iteratif();
void faktorial_Rekrusif();
void faktorial_Deret();

// fungsi untuk Rekrusif & Deret
int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * faktorial(n-1);
    }
}

void startMenu() {
    int pilihan;

    while (true) {
        cout << "=====Pilih Studi Kasus=====" << endl;
        cout << "[1] Faktorial Iteratif" << endl;
        cout << "[2] Faktorial Rekrusif" << endl;
        cout << "[3] Faktorial Deret" << endl;
        cout << "Pilih: ";
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore();
            cout << "Masukan pilihan yang benar!" << endl;
            cout << endl;
            continue;
        }
        cin.ignore();

        if (pilihan == 0) {
            break;
        }

        if (pilihan == 1) {
            cout << endl;
            faktorial_Iteratif();
        } else if (pilihan == 2) {
            cout << endl;
            faktorial_Rekrusif();
        } else if (pilihan == 3) {
            cout << endl;
            faktorial_Deret();
        }
    }
}

void faktorial_Iteratif() {
    int n;
    int hasil = 1;

    while (true) {       
        cout << "=====Faktorial Iteratif=====" << endl;
        cout << "Masukan angka: ";
        if (!(cin >> n)) {
            cin.clear();
            cin.ignore();
            cout << "Masukan ANGKA!" << endl;
            cout << endl;
            continue;
        }
        cin.ignore();

        if (n < 0) {
            cout << "Faktorial tidak terdefinisi untuk angka negatif!" << endl;
        } else {
            for (int i=1;i<=n;i++) {
                hasil *= i;
            }
            cout << n << "! = " << hasil << endl; 
            cout << endl;
            break;
        }
    }
}

void faktorial_Rekrusif() {
    int n;

    while (true) {
        cout << "=====Faktorial Rekrusif=====" << endl;
        cout << "Masukan angka: ";
        if (!(cin >> n)) {
            cin.clear();
            cin.ignore();
            cout << "Masukan ANGKA!" << endl;
            cout << endl;
            continue;
        }
        cin.ignore();

        if (n < 0) {
            cout << "Faktorial tidak terdefinisi untuk angka negatif!" << endl;
        } else {
            cout << "Faktorial dari " << n << " Adalah " << faktorial(n) << endl;
            cout << endl;
            break;
        }
    }
}

void faktorial_Deret() {
    int n;
    
    while (true) {    
        cout << "=====Faktorial Deret=====" << endl;
        cout << "Masukan angka: ";
        if (!(cin >> n)) {
            cin.clear();
            cin.ignore();
            cout << "Masukan ANGKA!" << endl;
            cout << endl;
            continue;
        }
        cin.ignore();
        
        if (n < 0) {
            cout << "Faktorial tidak terdefinisi untuk angka negatif!" << endl;
        } else {
            for (int i=1;i<=n;i++) {
                cout << i << "! = " << faktorial(i) << endl;
            }
            cout << endl;
            break;
        }
    }
}

int main() {
    system("cls");

    startMenu();
    
    return 0;
}