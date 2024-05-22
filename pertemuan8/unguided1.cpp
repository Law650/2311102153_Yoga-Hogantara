#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// BINARYSEARCH PADA STRING YANG DIURUTKAN
bool binarySearch_153(const string &sortedstr, char target) {
    int kiri = 0;
    int kanan = sortedstr.length() - 1;

    while (kiri <= kanan) {
        int center = kiri + (kanan - kiri) / 2;

        if (sortedstr[center] == target) {
            return true;  
        }
        if (sortedstr[center] < target) {
            kiri = center + 1;
        } else {
            kanan = center - 1;
        }
    }

    return false;
}

// MENCARI SEMUA HURUF PADA INDEKS KALIMAT ASLI
vector<int> findIndices_153(const string &originalstr, char target) {
    vector<int> indices;
    for (size_t i = 0; i < originalstr.length(); ++i) {
        if (originalstr[i] == target) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    string input;
    char target;
    char pilih;

    do {
        
        cout << "INPUT KALIMAT: ";
        getline(cin, input);

       
        cout << "INPUT HURUF YANG DICARI: ";
        cin >> target;
        cin.ignore(); 

        // MEMBUAT SALINAN PADA INPUTAN
        string originalinput = input;

        // MENGURUTKAN STRING
        sort(input.begin(), input.end());

        // BINARYSEARCH
        bool ketemu = binarySearch_153(input, target);

        // HASIL PENCARIAN
        if (ketemu) {
            cout << "HURUF '" << target << "' KETEMU DI KALIMAT.\n";

            // MENCARI DAN MEAMPILKAN HURUF
            vector<int> indices = findIndices_153(originalinput, target);
            cout << "HURUF '" << target << "' ADA DI INDEKS : ";
            for (size_t i = 0; i < indices.size(); ++i) {
                cout << indices[i];
                if (i < indices.size() - 1) {
                    cout << ", ";  // JIKA BUKAN INDEKS TERAKHIR MENAMBAHKAN KOMA
                }
            }
            cout << endl;
        } else {
            cout << "HURUF '" << target<< "' GA KETEMU DI KALIMAT.\n";
        }

        // LAGI ATAU ENGGA
        cout << "LAGI ? (y/n): ";
        cin >> pilih;
        cin.ignore(); // MEMBERSIHKAN BUFFER
    } while (pilih == 'y' || pilih == 'Y');

    return 0;
}