#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    vector<int> L(n1), R(n2);
    for (int i=0;i<n1;i++) {
        L[i] = arr[kiri + i];
    }
    for (int j=0;j<n2;j++) {
        R[j] = arr[tengah + 1 + j];
    }

    int i = 0, j = 0, k = kiri;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeD(vector<int> &arr, int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    vector<int> L(n1), R(n2);
    for (int i=0;i<n1;i++) {
        L[i] = arr[kiri + i];
    }
    for (int j=0;j<n2;j++) {
        R[j] = arr[tengah + 1 + j];
    }

    int i = 0, j = 0, k = kiri;
    while (i<n1 && j<n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah +1, kanan);
        merge(arr, kiri, tengah, kanan);
        cout << "Merge Sort pada index " << kiri << " hingga " << kanan << ": ";
        for (int i=kiri;i<=kanan;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void mergeSortD(vector<int> &arr, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        mergeSortD(arr, kiri, tengah);
        mergeSortD(arr, tengah +1, kanan);
        mergeD(arr, kiri, tengah, kanan);
        cout << "Merge Sort pada index " << kiri << " hingga " << kanan << ": ";
        for (int i=kiri;i<=kanan;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void printArr(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;
}

void menu(vector<int> &arr, int pilihan, int sizeArr) {

    while (true) {
        cout << "=====Menu Merge Sorting=====" << endl;
        cout << "[1] Merge Sorting[Ascending]" << endl;
        cout << "[2] Merge Sorting[Descending]" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore();
            cout << "Input pilihan tidak tersedia.\n\n";
            continue;
        }
        if (pilihan == 0) {
            break;
        } else if (pilihan == 1) {
            cout << endl;
            cout << "Array mula-mula: ";
            printArr(arr);

            cout << "Proses Merge Sorting:\n";
            mergeSort(arr, 0, sizeArr - 1);

            cout << "\nArray Setelah Di Sorting: ";
            printArr(arr);
        } else if (pilihan == 2) {
            cout << endl;
            cout << "Array mula-mula: ";
            printArr(arr);

            cout << "Proses Merge Sorting:\n";
            mergeSortD(arr, 0, sizeArr - 1);

            cout << "\nArray Setelah Di Sorting: ";
            printArr(arr);
        }
    }
}

int main() {
    system("cls");
    vector<int> arr;
    int sizeArr = arr.size();
    int x;
    int pilihan;

    cout << "Berapa elemen yang anda ingin masukan: ";
    cin >> sizeArr;
    for (int i;i<sizeArr;i++) {
        cout << "Masukan elemen ke-" << i << ": ";
        cin >> x;
        arr.push_back(x);
    }
    cout << endl;
    menu(arr, pilihan, sizeArr);
    
    return 0;
}