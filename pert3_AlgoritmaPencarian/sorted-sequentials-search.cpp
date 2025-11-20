#include <iostream>
using namespace std;

int main() {
    int arr[5] = {5,10,15,20,25};
    int n = sizeof(arr) / sizeof(arr[0]); // n = 5
    int x = 15;

    int i = 0;

    while (i < n && arr[i] != x) {
        i++;
    }

    if (i < n) {
        cout << "Angka ditemukan di index ke-" << i;
    } else {
        cout << "Angka tidak ditemukan";
    }

    return 0;
}