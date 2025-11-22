#include <iostream>
#include <string>
using namespace std;

void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i=0;i < size - 1;i++) {
        swapped = false;
        for (int j=0;j < size - i - 1;j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
            cout << "Langkah Ke-" << i + 1 << " Iterasi Ke-" << j + 1 << ": ";
            for (int k=0;k < size;k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
        if (!swapped){
            break;
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i=0;i < size-1;i++) {
        int minIndex = i;
        for (int j=i+1;j<size;j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != 1) {
            swap(arr[i], arr[minIndex]);
        }
        cout << "Langkah Ke-" << i + 1 << ": ";
        for (int k=0;k<size;k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[4];
    int arrSel[4];
    int size = sizeof (arr) / sizeof (arr[0]);
    int sizeSel = sizeof (arrSel) / sizeof (arrSel[0]);

    int input;

    system("cls");
    
    for (int i=0;i < size;i++) {
        cout << "Input " << size << " angka random: ";
        cin >> arr[i];
    }

    cout << "1 = bubbleSort | 2 = selectionSort: ";
    cin >> input;

    cout << "Array sebelum di sort(urutkan): ";
    for (int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    if (input == 1) {
        bubbleSort(arr, size);

        cout << "Sorted Array Bubble(Ascending): ";
        for (int i=0;i<size;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        selectionSort(arr, size);

        cout << "Sorted Array Selection(Ascending): ";
        for (int i=0;i<size;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "selection sort umumnya lebih efisien daripada bubble sort karena jumlah pertukarannya lebih sedikit, meskipun keduanya memiliki kompleksitas waktu yang sama pada kasus terburuk";

    return 0;
}