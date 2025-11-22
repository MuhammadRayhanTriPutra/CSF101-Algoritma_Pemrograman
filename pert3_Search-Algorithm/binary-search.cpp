#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,3,5,7,9,11,13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = -1;

    cout << "Masukan angka yang ingin dicari: ";
    cin >> x;

    int low = 0;
    int high = n - 1;

    if (x != -1) {
        while (low <= high) {
         int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                cout << "Angka ditemukan di index ke-" << mid;
                return 0;
            }

            if (arr[mid] < x)
                low = mid + 1;
            else 
                high = mid - 1;
        }
    }

    cout << "Angka tidak ditemukan";

    return 0;
}