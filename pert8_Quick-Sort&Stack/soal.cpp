#include <iostream>
#include <string>
#include <stack>
using namespace std;

void startMenu(int &pilihan) {
    cout << "[1] Native Stack\n";
    cout << "[2] Stack\n";
    cout << "[3] Mengecek jika (operand) mempunyai pasangan\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
}

void strukturData(int &pilihanUR) {
    string data;

    while(true) {
        cout << "Masukan Data: ";
        getline(cin, data);

        if(!data.empty()) {
            cout << "=====Implementasi Native Stack=====" << endl;
            cout << "[1] Push" << endl;
            cout << "[2] Pop" << endl;
            cout << "[3] Peek" << endl;
            cout << "[4] isEmpty" << endl;
            cout << "[5] Size" << endl;
            cout << "[6] Exit" << endl;
            cout << ": ";
            if(!cin >> pilihanUR) {
                cin.clear();
                cin.ignore();
                cout << "Input Invalid\n";
                continue;
            }
            cin.ignore();

            if(pilihanUR == 0) {
                cout << endl;
                break;
            }

            if(pilihanUR == 1) {
                
            }
        }
    }
}

void membalikanKalimat(int &pilihanUR) {
    string kalimat;
    string hasil;
    stack<char> tumpukan;

    while (true) {
        cout << "=====Implementasi Stack: Membalikan Kalimat=====" << endl;
        cout << "[1] Masukan Kalimat" << endl;
        cout << "[0] Kembali ke menu Implemen Stack" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilihanUR)) {
            cin.clear();
            cin.ignore();
            cout << "Input invalid\n";
            continue;
        }
        cin.ignore();

        if (pilihanUR == 0) {
            cout << endl;
            break;
        }

        if (pilihanUR == 1) {
            cout << "Masukan Kalimat: ";
            getline(cin, kalimat);

            if (!kalimat.empty()) {
                for (char c : kalimat) tumpukan.push(c);

                while (!tumpukan.empty()) {
                    hasil += tumpukan.top();
                    tumpukan.pop();
                }

                cout << "\n--Hasil Kalimat Yang Di Balik--" << endl;
                cout << hasil << endl;
                cout << "-------------------------------" << endl << endl;
                hasil.clear();
            }
        } else {
            cout << "Opsi invalid, mohon masukan pilihan yang tepat.\n" << endl;
        }
    }
}

int main() {
    
    int pilihan = 0;
    int pilihanUR = 0;

    while(true) {
        startMenu(pilihan);

        if(pilihan == 0) {
            break;
        }

        if(pilihan == 1) {
            cout << "test";
        } else if(pilihan == 2) {
            membalikanKalimat(pilihanUR);
        } else if(pilihan == 3) {
            cout << "test3";
        }
    }
    
    return 0;
}