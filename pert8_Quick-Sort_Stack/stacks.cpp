#include <iostream>
#include <string>
#include <stack>
using namespace std;

void startMenu(int &pilihan) {
    system("cls");
    cout << "[1] Native Stack\n";
    cout << "[2] Stack Membalik kalimat\n";
    cout << "[3] Validitas kurung\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
}

void push(string stack[], int &top, int kapasitas) {
    string data;
    if (top == kapasitas - 1) {
        cout << "Stack sudah PENUH, tidak bisa memasukan data lagi!\n\n";
    } else {
        cout << "Masukan data yang ingin di push: ";
        getline(cin, data);

        top++;
        stack[top] = data;

        cout << "Memasukan '" << data << "' Ke dalam stack.\n\n";
    }
}

void pop(string stack[], int &top) {
    system("cls");
    if (top == -1) {
        cout << "Stack KOSONG, tidak dapat melakukan pop!\n\n";
    } else {
        cout << "Pop '" << stack[top] << "' Dari stack.\n\n";
        top--;
    }
}

void peek(string stack[], int top) {
    system("cls");
    if (top == -1) {
        cout << "Stack KOSONG, tidak ada elemen ter-atas!\n\n";
    } else {
        cout << "Elemen teratas: " << stack[top] << endl << endl;
    }
}

bool isEmpty(int top) {
    system("cls");
    return top == -1;
}

int size(int top) {
    return top + 1;
}

void nativeStack(int &pilihanMenu) {
    string stack[10];
    int top = -1;
    int kapasitas;
    system("cls");

    while (true) {
        cout << "Masukan max-kapasitas untuk stack (Min 1 - Max 10): ";
        cin >> kapasitas;
        if (kapasitas > 10 || kapasitas <= 0) {
            cout << "Masukan kapasitas sesuai ketentuan!" << endl;
            continue;
        }

        while (true) {
            cout << "=====Native Stack=====\n";
            cout << "[1] Push\n";
            cout << "[2] Pop\n";
            cout << "[3] Peek\n";
            cout << "[4] isEmpty\n";
            cout << "[5] Size\n";
            cout << "[0] Exit\n";
            cout << "Pilih operasi stack: ";
            
            if (!(cin >> pilihanMenu)) {
                cin.clear();
                cin.ignore();
                cout << "Input invalid.\n";
                continue;
            }
            cin.ignore();

            if (pilihanMenu == 0) break;

            if (pilihanMenu == 1) {
                push(stack, top, kapasitas);
            } 
            else if (pilihanMenu == 2) {
                pop(stack, top);
            } 
            else if (pilihanMenu == 3) {
                peek(stack, top);
            } 
            else if (pilihanMenu == 4) {
                if (isEmpty(top)) {
                    cout << "Stack KOSONG!" << endl << endl;
                } else {
                    cout << "Stack tidak KOSONG." << endl << endl;
                }
            } 
            else if (pilihanMenu == 5) {
                cout << "Stack size: "<< size(top) << " / " << kapasitas << endl << endl;
            }
        }
        break;
    }
}

void membalikanKalimat(int &pilihanMenu) {
    string kalimat;
    string hasil;
    stack<char> tumpukan;
    system("cls");

    while (true) {
        cout << "=====Stack Membalikan Kalimat=====" << endl;
        cout << "[1] Masukan Kalimat" << endl;
        cout << "[0] Kembali ke menu studi kasus" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilihanMenu)) {
            cin.clear();
            cin.ignore();
            cout << "Input invalid\n";
            continue;
        }
        cin.ignore();

        if (pilihanMenu == 0) {
            cout << endl;
            break;
        }

        if (pilihanMenu == 1) {
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
                for (char c : hasil) {
                    cout << "-";
                }
                cout << endl << endl;
                hasil.clear();
            }
        } else {
            cout << "Opsi invalid, mohon masukan pilihan yang tepat.\n" << endl;
        }
    }
}

void validitasKurung(int &pilihanMenu) {
    system("cls");

    while (true) {
        cout << "=====Stack Validitas Kurung=====" << endl;
        cout << "[1] Masukan Bilangan" << endl;
        cout << "[0] Kembali ke menu studi kasus" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilihanMenu)) {
            cin.clear();
            cin.ignore();
            cout << "Input invalid\n";
            continue;
        }
        cin.ignore();

        if (pilihanMenu == 0) {
            cout << endl;
            break;
        }

        if (pilihanMenu == 1) {
            string bilangan;
            stack<char> tumpukanKurung;
            bool valid = true;
            cout << "Masukan Bilangan: ";
            getline(cin, bilangan);

            if (bilangan.empty()) {
                cout << "Input kosong, silakan masukkan ulang.\n" << endl << endl;
                continue;
            }

            for (char c : bilangan) {
                if (c == '(' || c == '{' || c == '[') {
                    tumpukanKurung.push(c);
                } else if (c == ')' || c == '}' || c == ']') {
                    if (tumpukanKurung.empty() || (c == ')' && tumpukanKurung.top() != '(') || (c == '}' && tumpukanKurung.top() != '{') || (c == ']' && tumpukanKurung.top() != '[')) {
                        valid = false;
                        break;
                    } else {
                        tumpukanKurung.pop();
                    }
                }
            }

            if (!tumpukanKurung.empty()) valid = false;

            if (valid) {
                cout << "Bilangan Valid, setiap kurung mempunyai pasangan." << endl << endl;
            } else {
                cout << "Bilangan Invalid, ada kurung yang tidak mempunyai pasangan!" << endl << endl;
            }
        } else {
            cout << "Opsi invalid, mohon masukan pilihan yang tepat.\n" << endl << endl;
        }
    }
}


int main() {
    
    int pilihan = 0;
    int pilihanMenu = 0;

    while(true) {
        startMenu(pilihan);

        if(pilihan == 0) {
            break;
        }

        if(pilihan == 1) {
            nativeStack(pilihanMenu);
        } else if(pilihan == 2) {
            membalikanKalimat(pilihanMenu);
        } else if(pilihan == 3) {
            validitasKurung(pilihanMenu);
        }
    }
    
    return 0;
}