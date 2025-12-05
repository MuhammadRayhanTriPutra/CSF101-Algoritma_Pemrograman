#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    system("cls");
    int n; // Jumlah proses
    struct Proses {
        int name;
        int at;
        int bt;
    };

    cout << "Masukan Jumlah proses: ";
    cin >> n;

    vector<Proses> p(n);

    for (int i=0;i<n;i++) { 
        p[i].name = i+1;
        cout << "Proses Name: " << "P" << p[i].name << endl;
        cout << "Arrival-Time - " << "P" << p[i].name << ": ";
        cin >> p[i].at;
        cout << "Burst-Time - " << "P" << p[i].name << ": ";
        cin >> p[i].bt;
        cout << endl;
    }

    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (p[j].bt < p[i].bt) {
                swap(p[i], p[j]);
            }
        }
    }
    
    cout << "=========== Gantt Chart ===========" << endl;
    cout << " ";
    for (int i=0;i<n;i++) {
        for (int j=0;j<p[i].bt;j++) cout << "--";
        cout << " ";
    }
    cout << "\n|";
    for (int i=0;i<n;i++) {
        for (int j=0;j<p[i].bt-1;j++) cout << " ";
        cout << p[i].bt;
        for (int j=0;j<p[i].bt-1;j++) cout << " ";
        cout << "|";
    }
    cout << endl;
        cout << " ";
    for (int i=0;i<n;i++) {
        for (int j=0;j<p[i].bt;j++) cout << "--";
        cout << " ";
    }
    cout << endl;
    cout << "=========== Tabel SRTF Preemtive Scheduling ===========" << endl;
    cout << "Proses\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (int i=0;i<n;i++) {
        cout << "P" << p[i].name << "\t"
        << p[i].at << "\t"
        << p[i].bt << "\t"
        << p[i].at + p[i].bt << "\t"
        << p[i].at + p[i].bt - p[i].at << "\t"  
        << p[i].at + p[i].bt - p[i].at - p[i].bt << "\t"
        << p[i].at - p[i].at;
        cout << endl;
    }

    return 0;
}