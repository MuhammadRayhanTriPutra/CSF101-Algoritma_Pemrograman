#include <iostream>
#include <stack>
#include <string>
using namespace std;

void start(int &pilihan) {
    system("cls");
    cout << "=====Implementasi Stack=====" << endl;
    cout << "[1] Undo / Redo Kalimat" << endl;
    cout << "[2] Membalik Kalimat" << endl;
    cout << "[3] Konversi Notasi Infix ke Postfix" << endl;
    cout << "Pilih Implemen Kasus: ";
    cin >> pilihan;
    cin.ignore();
}

void undoRedo(int &pilihanUR) {
    stack<string> undoStack;
    stack<string> redoStack;
    string sekarang = "";
    system("cls");

    while (true) {
        cout << "=====Implementasi Stack: Undo / Redo Kalimat=====" << endl;
        cout << "[1] Masukan Kalimat" << endl;
        cout << "[2] Undo" << endl;
        cout << "[3] Redo" << endl;
        cout << "[4] Hapus Kalimat" << endl;
        cout << "[5] Lihat Kalimat" << endl;
        cout << "[0] Kembali ke menu Implemen Stack" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilihanUR)) {
            cin.clear();
            cin.ignore();
            cout << "Input invalid\n" << endl;
            continue;
        }
        cin.ignore();

        if (pilihanUR == 0) {
            cout << endl;
            break;
        }

        if (pilihanUR == 1) {
            string input;
            cout << "Masukan Kalimat: ";
            getline(cin, input);

            undoStack.push(sekarang);
            while (!redoStack.empty()) redoStack.pop();
            
            sekarang = input;
            cout << "Kalimat disimpan.\n" << endl;
        } else if (pilihanUR == 2) {
            if (undoStack.empty()) {
                cout << "Tidak ada yang bisa di-undo.\n" << endl;
            } else {
                redoStack.push(sekarang);
                sekarang = undoStack.top();
                undoStack.pop();
                cout << "Undo Berhasil.\n" << endl;
            }
        } else if (pilihanUR == 3) {
            if (redoStack.empty()) {
                cout << "Tidak ada yang bisa di-redo.\n" << endl;
            } else {
                undoStack.push(sekarang);
                sekarang = redoStack.top(); 
                redoStack.pop();
                cout << "Redo Berhasil.\n" << endl;
            }
        } else if (pilihanUR == 4) {
            if (sekarang.empty()) {
                cout << "Tidak ada kalimat untuk di Hapus.\n" << endl;
            } else {
                undoStack.push(sekarang);
                while (!redoStack.empty()) redoStack.pop(); 
                sekarang.clear();
                cout << "Kalimat telah di Hapus.\n" << endl;
            }
        } else if (pilihanUR == 5) {
            cout << "-- Kalimat Saat Ini --\n";
            if (sekarang.empty()) cout << "(kosong)\n";
            else cout << sekarang << endl;
            cout << "----------------------\n" << endl;
        } else {
            cout << "Opsi invalid, mohon masukan pilihan yang tepat.\n" << endl;
        }
    } 

}

void membalikanKalimat(int &pilihanUR) {
    string kalimat;
    string hasil;
    stack<char> tumpukan;
    system("cls");

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

                cout << "\n--Hasil Kalimat Terbalik--" << endl;
                cout << hasil << endl;
                for(char c : hasil) {
                    cout << "-";
                }
                cout << endl;
                cout << endl;
                hasil.clear();
            }
        } else {
            cout << "Opsi invalid, mohon masukan pilihan yang tepat.\n" << endl;
        }
    }
}

bool isAlnum(char ch) {
    return (ch >= '0' && ch <= '9') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch == '_');
}

bool isSpaceChar(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

int precedence(char op) {
    if (op == '^') return 4;
    if (op == '*' || op == '/') return 3;
    if (op == '+' || op == '-') return 2;
    return 0;
}

void konversiNotasiInfixPostfix(int &pilihanUR) {
    string infix;
    string postfix;
    stack<char> tumpukan;
    system("cls");

    while (true) {
        cout << "=====Implementasi Stack: Notasi Infix ke Postfix=====" << endl;
        cout << "[1] Masukan notasi infix (contoh: a+b*(c-d))" << endl;
        cout << "[0] Kembali ke menu Implemen stack" << endl;
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
            cout << "Masukan notasi Infix: ";
            getline(cin, infix);

            while (!tumpukan.empty()) tumpukan.pop();
            postfix.clear();
            bool error = false;

            for (int i = 0; i < (int)infix.length(); ++i) {
                char ch = infix[i];
                if (isSpaceChar(ch)) continue;

                if (isAlnum(ch)) {
                    string token = "";
                    while (i < (int)infix.length() && isAlnum(infix[i])) {
                        token += infix[i];
                        ++i;
                    }
                    --i;
                    if (!postfix.empty()) postfix += ' ';
                    postfix += token;
                } else if (ch == '(') {
                    tumpukan.push(ch);
                } else if (ch == ')') {
                    bool found = false;
                    while (!tumpukan.empty()) {
                        if (tumpukan.top() == '(') { tumpukan.pop(); found = true; break; }
                        postfix += ' ';
                        postfix += tumpukan.top();
                        tumpukan.pop();
                    }
                    if (!found) { cout << "Error: tanda kurung tidak cocok\n"; error = true; break; }
                } else {
                    while (!tumpukan.empty() && tumpukan.top() != '(' &&
                           ((precedence(tumpukan.top()) > precedence(ch)) ||
                            (precedence(tumpukan.top()) == precedence(ch) && ch != '^'))) {
                        postfix += ' ';
                        postfix += tumpukan.top();
                        tumpukan.pop();
                    }
                    tumpukan.push(ch);
                }
            }

            if (error) continue;

            while (!tumpukan.empty()) {
                if (tumpukan.top() == '(' || tumpukan.top() == ')') {
                    cout << "Error: tanda kurung tidak cocok\n";
                    error = true;
                    break;
                }
                postfix += ' ';
                postfix += tumpukan.top();
                tumpukan.pop();
            }

            if (error) continue;

            int pos = 0;
            while (pos < (int)postfix.length() && isSpaceChar(postfix[pos])) ++pos;
            if (pos > 0) postfix = postfix.substr(pos);

            cout << "Postfix: " << postfix << endl << endl;
        } else {
            cout << "Opsi Invalid, mohon masukan pilihan yang benar.\n" << endl;
        }
    }
}

int main() {
    int pilihan = 0;
    int pilihanUR = 0;

    while (true) { 
        start(pilihan);
        
        if (pilihan == 0) {
            cout << "Keluar, sampai jumpa!\n";
            break;
        } else if (pilihan == 1) {
            cout << endl;
            undoRedo(pilihanUR);
        } else if (pilihan == 2) {
            cout << endl;
            membalikanKalimat(pilihanUR);
        } else if (pilihan == 3) {
            cout << endl;
            konversiNotasiInfixPostfix(pilihanUR);
        }
    }

    return 0;
}